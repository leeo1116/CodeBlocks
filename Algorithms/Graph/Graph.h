/* Graph traversal by DFS and BFS
Reference 1 - http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
Reference 2 - http://www.geeksforgeeks.org/applications-of-depth-first-search/
Reference 3 - http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
*/

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;


class Graph
{
    private:
        int vNum;           // number of vertex
        unordered_map<int, vector<int>> vertexNeighborsMap;
        void DFS_helper(int v, unordered_map<int, bool> *nodeVisitedMapPointer);     // a function used by DFS

    public:
        Graph(int v);                   // constructor
        void AddEdge(int v, int w);     // function to add edge to graph
        void DFS(int v);                // DFS traversal of the vertex reachable from v
};


#endif // GRAPH_H_INCLUDED
