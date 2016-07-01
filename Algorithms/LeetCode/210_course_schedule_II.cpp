#include "Leetcode.h"

vector<int> Solution::findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    // Use map to record if node is visited, use pointer since recursion will otherwise shadow the scope of non-pointer variable
    vector<bool> nodeVisited(numCourses, false), onPathVisited(numCourses, false);
    // Use map as adjacency list {{v1, [n11, n12, ..., n1N1]}, {v2, [n21, n22, ..., n2N2]}, ..., {vV, [vV1, vV2, ..., vVNV]}}
    unordered_map<int, unordered_set<int>> vertexNeighborsMap;
    // Create graph
    for(auto p : prerequisites){
        vertexNeighborsMap[p.second].insert(p.first);
    }
    vector<int> courseOrder;
    // Traverse each node as start vertex accounting for disconnected graph
    for(int i = 0; i < numCourses; i++){
        // If this vertex is not visited, use it as start vertex
        if(!nodeVisited[i]){
            // If cycle detected, return course schedule cannot be completed
            if(HasCycleDFS_II(vertexNeighborsMap, i, nodeVisited, onPathVisited, courseOrder))
                return {};
        }
    }
    reverse(courseOrder.begin(), courseOrder.end());
    return courseOrder;
    }


bool Solution::HasCycleDFS_II(unordered_map<int, unordered_set<int>> &graph, int startVertex, vector<bool> &visited, vector<bool> &onPath, vector<int> &courseOrder){
    if(visited[startVertex])
        return false;
    onPath[startVertex] = visited[startVertex] = true;
    for(int n : graph[startVertex]){
        // if the candidate vertex is already on current DFS path or recursively, its next neighbor or next next neighbor ... has cycle
        if(onPath[n] || HasCycleDFS_II(graph, n, visited, onPath, courseOrder))
            return true;
    }
    // reset startVertex to default status so that another path containing startVertex can work properly
    onPath[startVertex] = false;
    // Append startVertex to courseOrder, which appended in reverse way. i.e. the deepest vertex append first
    courseOrder.push_back(startVertex);
    return false;
}
