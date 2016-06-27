#include "Graph.h"


Graph::Graph(int v)
{
    this->vNum = v;     // no need to use this pointer here, alternative: vNum = v;
}


void Graph::AddEdge(int v, int w)
{
    vertexNeighborsMap[v].push_back(w);
}


void Graph::DFS_helper(int v, unordered_map<int, bool> *nodeVisitedMapPointer)
{
    (*nodeVisitedMapPointer)[v] = true;
    cout << v << " ";
    vector<int> vNeighbors = vertexNeighborsMap[v];
    for(unsigned i = 0; i < vNeighbors.size(); i++)
    {
        if(!(*nodeVisitedMapPointer)[vNeighbors[i]])
            DFS_helper(vNeighbors[i], nodeVisitedMapPointer);
    }
}


void Graph::DFS(int v)
{
    // Mark all nodes as not visited
    unordered_map<int, bool> *nodeVisitedMapPointer;
    nodeVisitedMapPointer = new unordered_map<int, bool>({{v, false}, {v, false}});
    unordered_map<int, vector<int>>::iterator i;
    for(i = vertexNeighborsMap.begin(); i != vertexNeighborsMap.end(); i++)
        (*nodeVisitedMapPointer)[i->first] = false;

    // Call DFS_helper to print all node in DFS sense
    DFS_helper(v, nodeVisitedMapPointer);
    delete nodeVisitedMapPointer;
}


