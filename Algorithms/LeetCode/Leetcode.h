#ifndef LEETCODE_H_INCLUDED
#define LEETCODE_H_INCLUDED

#include <unordered_map>
#include <vector>
#include <utility>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool CanFinishBFS(int numCourses, vector<pair<int, int>>& prerequisites);
    bool CanFinishDFS(int numCourses, vector<pair<int, int>>& prerequisites);
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);

private:
    bool HasCycleDFS(unordered_map<int, unordered_set<int>> &graph, int startVertex, vector<bool> &visited, vector<bool> &onPath);
    bool HasCycleDFS_II(unordered_map<int, unordered_set<int>> &graph, int startVertex, vector<bool> &visited, vector<bool> &onPath, vector<int> &courseOrder);
};

#endif // LEETCODE_H_INCLUDED
