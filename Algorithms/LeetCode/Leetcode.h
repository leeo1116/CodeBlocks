#ifndef LEETCODE_H_INCLUDED
#define LEETCODE_H_INCLUDED

#include <unordered_map>
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool CanFinishBFS(int numCourses, vector<pair<int, int>>& prerequisites);
    bool CanFinishDFS(int numCourses, vector<pair<int, int>>& prerequisites);
private:
    bool HasCycleDFS(unordered_map<int, unordered_set<int>> &graph, int startVertex, vector<bool> &visited, vector<bool> &onPath);
};

#endif // LEETCODE_H_INCLUDED
