// Optimization.cpp

/**
 * FILL IN A DESCRIPTION OF YOUR ALGORITHM HERE
 * A first solution to this problem is to create a 2d array, with the first dimension corresponding to
 * the 6 possible content locations, and the second dimension corresponding to the time slots for that
 * location. Each location in this 2d array holds vector of content ids (strings). I'm using a vector so
 * that I can just use a method from the vector class to check the size, and also in case future versions
 * of the content layout requirements might allow more or less pieces of content scheduled at a time.
 * As schedule requests are read in, their content id is added to each time slot in which they appear,
 * at the appropriate location. All schedule requests are read in before handling any optimization requests.
 * Each optimization request is then read in, and starting at the location with the highest multiplier,
 * each time slot is checked to see if there are less than 3 pieces of content scheduled. If there is
 * space for the new content, the content ids are checked against the new one to ensure there arent
 * conflicts. The first gap that is found which has enough space and no conflicts is picked, and
 * then this choice is output to the file. If there aren't gaps found within the time slots already
 * scheduled, the algorithm reports an error and throws an exception. Adding the new content to the end
 * of one of the schedules would also have been acceptable.
 *
 * Optimizations I want to do:
 * I want to only store gaps in the schedule instead of the schedule itself. I would also need to keep
 * around information such as what content IDs occupy the schedule in the different time slots of each gap.
 * I also want to dynamically determine the order of the content locations to prioritize, based on the LocationValueMap,
 * since specs and requirements may change in the future.
 *
 *
 * Update: Now using a set instead of a vector to hold the content IDs for a given time slot. Lookup is easier.
 * Update: Working on storing the gaps in the schedule instead of the schedule itself. Much less work to do for each OptimizationRequest
 *
 * @author Eric Mackay
 * Number 17.
 */

#include "ScheduleRequestInputStream.h"
#include "OptimizationRequestInputStream.h"
#include "ScheduleRequestWriter.h"
#include "ContentScoreMap.h"
#include "LocationValueMap.h"
#include "TestFiles.h"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

#define NUMBER_OF_LOCATIONS 6	//I could get this from 
#define MAX_TIME_SLOTS 5000	//A fixed size to make a simple first attempt, didnt see anything past 1000 in sample input
#define MAX_CONTENT_PER_TIME 3

typedef std::unordered_set<std::string> contentIDs;	//using a vector so that I can just ask what the size is the vector, to easily identify gap

//class that represents each gap that is found
class GapInfo {
private:
	std::string location;
	std::vector<contentIDs> timeSlots;
	int startTime;
	int endTime;
public:
	GapInfo();
	GapInfo(const GapInfo& other);

	const std::string getLocation() { return location; }
	const int getStartTime() { return startTime; }
	const int getEndTime() { return endTime; }

	//this method searches all the time slots and returns true if there is a match anywhere
	const bool containsContentID(std::string contentID) {
		int numSlots = timeSlots.size();
		for(int i = 0; i < numSlots; i++) {
			int numContent = timeSlots[i].size();
			for(int j = 0; j < numContent; j++) {
				//NO TIME! :(
			}
		}
		return false;
	}

};

typedef std::vector<GapInfo> gapVector;
typedef std::map<int, gapVector> allGaps;

class Optimization {
public:

	//for now this is okay, but later I want to actually create this from the LocationValueMap, since multipliers are unlikely to remain static with respect to the future
	static int findLocationSlot(std::string locationID){
		if(locationID == "center-top"){
			return 0;
		}
		else if(locationID == "right-top"){
			return 1;
		}
		else if(locationID == "center-middle"){
			return 2;
		}
		else if(locationID == "center-bottom"){
			return 3;
		}
		else if(locationID == "right-middle"){
			return 4;
		}
		else if(locationID == "right-bottom"){
			return 5;
		}
		else{
			return -1;
		}
	}

	//for now this is okay, but later I want to actually create this from the LocationValueMap, since multipliers are unlikely to remain static with respect to the future
	static std::string findLocationID(int locationID){
		switch(locationID){
			case 0:
				return "center-top";
			case 1:
				return "right-top";
			case 2:
					return "center-middle";
			case 3:
				return "center-bottom";
			case 4:
				return "right-middle";
			case 5:
				return "right-bottom";
			default:
				return "unknown";
		}
	}
		
	/**
	 * The implementation for the optimization phase.
	 */
	static void optimize(ScheduleRequestInputStream& scheduleIn,
			OptimizationRequestInputStream& optimizationsRequestsIn,
			ScheduleRequestWriter& optimizationOut, ContentScoreMap& contentScoreMap,
			LocationValueMap& locationValueMap) {

		//array holding the vectors of content schedules for each location
		//index 0 corresponds to the location with the highest multiplier, 1 corresponds to the next highest, etc
		//the order is as follows (will make dynamic in future): center-top, right-top, center-middle, center-bottom, right-middle, right-bottom
		//I can use an array because I have a known number of content locations
		contentIDs* timeSlotsForEachLocation[NUMBER_OF_LOCATIONS][MAX_TIME_SLOTS];
		int latestEndTime[NUMBER_OF_LOCATIONS] = {0,0,0,0,0,0};

		//create a vector in all locations, waste of space
		for(int a = 0; a < NUMBER_OF_LOCATIONS; a++){
			for(int b = 0; b < MAX_TIME_SLOTS; b++){
				timeSlotsForEachLocation[a][b] = new contentIDs();
			}
		}

		//reconstruct the (assumed) valid schedule
		while(scheduleIn.hasNext()){
			ScheduleRequest request = scheduleIn.next();
			int location = findLocationSlot(request.getLocationId());

			//check for errors in input
			if(location == -1){
				std::cout << "We had an error!" << request.getLocationId() << " was not found!" << std::endl;
				throw std::exception();	//I can give the exception more info later
			}
			else{
				int finish = request.getEndTime();

				//add the content id to each time slot for the location
				//times will be off by 1 with respect to the array indices
				for(int i = request.getStartTime() - 1; i < finish; i++){
					timeSlotsForEachLocation[location][i]->insert(request.getContentId());
				}

				//we want to keep track of the last time slot occupied so we know when to stop looking for gap
				if(finish > latestEndTime[location]){
					latestEndTime[location] = finish;
				}
			}
		}

		/* TODO: Add optimizations here. Find gaps in schedule, store in map with size of gap as key, and the value is a
		vector of elements, and at each index of the vector is a set of the content id's at that time slot. This means
		that we can throw away all the stuff used initially to create the overall schedule, and then we also only have to
		iterate through a smaller amount of things for each optimization request. */
		
		while(optimizationsRequestsIn.hasNext()){
			OptimizationRequest request = optimizationsRequestsIn.next();

			int gapSize = 0;
			bool foundFit = false;
			std::string contentID = request.getContentId();
			int duration = request.getDuration();

			//starting with the location of max value, find the first gap that doesn't conflict with the new reqest
			for(int a = 0; a < NUMBER_OF_LOCATIONS && !foundFit; a++){
				gapSize = 0;

				//we want to know when to stop looking for gap
				int lastTime = latestEndTime[a];
				for(int b = 0; b < lastTime && !foundFit; b++){
					int size = timeSlotsForEachLocation[a][b]->size();
					
					//we have found a gap
					if(size < 3){

						//check for content conflicts
						bool conflicts = false;
						if(timeSlotsForEachLocation[a][b]->count(contentID)){
								//found a conflict. Boo :(
								conflicts = true;
						}

						//we found a conflict, reset gap to 0
						if(conflicts){
							gapSize = 0;
						}
						//we can increase the gap size because there are no conflicts in this gap
						else{
							gapSize++;
						}
					}
					//no gap here
					else{
						gapSize = 0;
					}

					//we found a fit!
					if(gapSize == duration)
					{
						foundFit = true;
						int endTime = b + 1;
						int startTime = endTime - duration + 1;
						ScheduleRequest output(contentID, findLocationID(a), startTime, endTime);
						optimizationOut.write(output);
					}
				}
			}

			if(!foundFit){
				//could also just add to the end of the schedule
				std::cout << "Couldn't find a fit for new content " << request.getContentId() << "!" << std::endl;
				throw std::exception();	//should make this another type of exception
			}
		}
		
		// Note: output is done up above
		// optimizationOut.write(request); // etc.
		optimizationOut.close();
	}

};

int main(int argc, char* argv[]) {

	try {
		// Input
		ScheduleRequestInputStream scheduleIn(TESTFILE_SCHEDULEOUTPUT);
		OptimizationRequestInputStream optimizationsRequestsIn(TESTFILE_OPTIMIZATIONREQUESTS);
		ContentScoreMap contentScoreMap(TESTFILE_CONTENTSCORES);
		LocationValueMap locationValueMap;

		//Some testing inputs
		/*ScheduleRequestInputStream scheduleIn("SCHEDULE_REQUESTS_TEST.tsv");
		OptimizationRequestInputStream optimizationsRequestsIn("OPTIMIZATION_REQUESTS_TEST.tsv");
		ContentScoreMap contentScoreMap(TESTFILE_CONTENTSCORES);
		LocationValueMap locationValueMap;*/

		// Output
		ScheduleRequestWriter optimizationOut("OPTIMIZATION-OUTPUT.tsv");

		Optimization::optimize(scheduleIn, optimizationsRequestsIn, optimizationOut, contentScoreMap, locationValueMap);

	} catch (std::exception& ex) {
		std::cerr << "[ERROR] " << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknown exception caught!";
	}

	return 0;

}
