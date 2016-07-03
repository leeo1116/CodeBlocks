#ifndef LEETCODE_H_INCLUDED
#define LEETCODE_H_INCLUDED

#include <unordered_map>
#include <vector>
#include <utility>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    bool CanFinishBFS(int numCourses, vector<pair<int, int>>& prerequisites);
    bool CanFinishDFS(int numCourses, vector<pair<int, int>>& prerequisites);
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
    bool ContainsDuplicatesIII(vector<int>& nums, int k, int t);
    string LargestNumber(vector<int> &nums);
    int LadderLength(string beginWord, string endWord, unordered_set<string>& wordList);

private:
    bool HasCycleDFS(unordered_map<int, unordered_set<int>> &graph, int startVertex, vector<bool> &visited, vector<bool> &onPath);
    bool HasCycleDFS_II(unordered_map<int, unordered_set<int>> &graph, int startVertex, vector<bool> &visited, vector<bool> &onPath, vector<int> &courseOrder);
    string IntToString(int i);
    void AddNextWords(string beginWord, unordered_set<string> &wordsList, queue<string> &toVisit);
};

#endif // LEETCODE_H_INCLUDED
