#include "Leetcode.h"


bool Solution::CanFinishBFS(int numCourses, vector<pair<int, int>>& prerequisites) {
    // Use adjacency list to represent graph, key: vertex, value: set.
    unordered_map<int, unordered_set<int>> vertexNeighborsMap;
    // Indegrees of each vertex, the length should equal to numCourse
    vector<int> vertexIndegrees(numCourses, 0);
    // Traverse each pair to create graph
    for(auto p : prerequisites){
        int candidate = p.first;
        int pre = p.second;
        vertexNeighborsMap[pre].insert(candidate);
    }
    // Calculate indegrees of each vertex
    for(int i = 0; i < numCourses; i++){
        for(auto n : vertexNeighborsMap[i])
            vertexIndegrees[n]++;
    }

    int j;
    // Traverse |V| times to find vertex with 0 indegrees for updated graph, if succeeds, then there is no loop
    for(int i = 0; i < numCourses; i++){
        // Traverse each vertex to find vertex that has 0 indegrees for updated graph, breadth-first is reflected here
        for(j = 0; j < numCourses; j++){
            // if the indegrees of the vertex is 0, use it as the start vertex to continue searching
            if(vertexIndegrees[j] == 0)
                break;
        }
        // if indegrees of all vertexes are not 0, return false, there must be a cycle
        if(j == numCourses)
            return false;
        // vertex j has 0 indegrees, update its indegree to -1 to avoid repeating
        vertexIndegrees[j] = -1;
        // Traverse every neighbor of vertex j, decrease by 1 since vertex j is visited
        for(auto n : vertexNeighborsMap[j])
            vertexIndegrees[n]--;
    }
    return true;
};
