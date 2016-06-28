/* Graph traversal by DFS and BFS
Reference 1 - http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
Reference 2 - http://www.geeksforgeeks.org/applications-of-depth-first-search/
Reference 3 - http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
*/

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;


class Graph
{
    private:
        // Number of vertexes
        int vNum;
        // Use map as adjacency list {{v1, [n11, n12, ..., n1N1]}, {v2, [n21, n22, ..., n2N2]}, ..., {vV, [vV1, vV2, ..., vVNV]}}
        unordered_map<int, vector<int>> vertexNeighborsMap;
        // DFS helper function with recursion
        void DFS_helper(int v, unordered_map<int, bool> *nodeVisitedMapPtr);

    public:
        Graph(int v);                   // constructor
        void AddEdge(int v, int w);     // function to add edge to graph
        void DFS(int v);                // DFS traversal of the vertex reachable from v
        void BFS(int v);                // BFS traversal of the vertex reachable from v
};


#endif // GRAPH_H_INCLUDED
