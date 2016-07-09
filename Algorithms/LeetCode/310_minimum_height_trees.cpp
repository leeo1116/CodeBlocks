#include "Leetcode.h"


vector<int> Solution::FindMinHeightTree(int n, vector<pair<int, int>> &edges){
    vector<int> leaves;
    // Corner case
    if(n == 1)
        return vector<int> {0};
    // Create graph with adjacency list representation
    vector<unordered_set<int>> adjList(n);
    for(auto e : edges){
        adjList[e.first].insert(e.second);
        adjList[e.second].insert(e.first);
    }

    // Find leaves of the out-most layer
    for(int i = 0; i < n; i++)
        if(adjList[i].size() == 1)
            leaves.push_back(i);

    // BFS
    while(true){
        vector<int> subLeaves;
        for(int leaf : leaves){
            for(int neighbor : adjList[leaf]){
                adjList[neighbor].erase(leaf);
                if(adjList[neighbor].size() == 1)
                    subLeaves.push_back(neighbor);
            }
        }
        if(subLeaves.empty())
            return leaves;
        leaves = subLeaves;
    }
}
