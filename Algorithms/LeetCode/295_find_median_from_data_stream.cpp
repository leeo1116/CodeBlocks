#include "Leetcode.h"


void MedianFinder::AddNum(int num){
    smallHeap.push(num);
    largeHeap.push(-smallHeap.top());
    smallHeap.pop();
    if(smallHeap.size() < largeHeap.size()){
        smallHeap.push(-largeHeap.top());
        largeHeap.pop();
    }

}


double MedianFinder::FindMedian(){
    return smallHeap.size() > largeHeap.size() ? smallHeap.top() : (smallHeap.top()+largeHeap.top())/2.0;
}
