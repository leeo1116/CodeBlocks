#include "Graph.h"


Graph::Graph(int v)
{
    this->vNum = v;     // can be deleted or vNum = v;
}


// Creating graph by adding edges one by one
void Graph::AddEdge(int v, int w)
{
    vertexNeighborsMap[v].push_back(w);
}


// Helper function of DFS
void Graph::DFS_helper(int v, unordered_map<int, bool> *nodeVisitedMapPtr)
{
    // Mark current vertex as visited and print it
    (*nodeVisitedMapPtr)[v] = true;
    cout << v << " ";
    // Check if all the neighbors of vertex v are visited
    vector<int> vNeighbors = vertexNeighborsMap[v];
    for(unsigned i = 0; i < vNeighbors.size(); i++)
    {
        // If the neighbor is not visited
        if(!(*nodeVisitedMapPtr)[vNeighbors[i]])
            // Search it in DFS fashion
            DFS_helper(vNeighbors[i], nodeVisitedMapPtr);
    }
}


// Search graph in Depth-first fashion
void Graph::DFS(int v)
{
    // Use map to record if node is visited, use pointer since recursion will shadow the scope of non-pointer variable
    unordered_map<int, bool> *nodeVisitedMapPtr;
    // Initialize pointer to NULL or empty map {{}}
    nodeVisitedMapPtr = new unordered_map<int, bool>();
    // Iterate each vertex and mark it as unvisited
    unordered_map<int, vector<int>>::iterator i, j;
    for(i = vertexNeighborsMap.begin(); i != vertexNeighborsMap.end(); i++)
        (*nodeVisitedMapPtr)[i->first] = false;

    // Traverse each node as start vertex accounting for disconnected graph
    for(j = vertexNeighborsMap.begin(); j != vertexNeighborsMap.end(); j++)
    {
        // If this vertex is not visited, use it as start vertex
        if(!(*nodeVisitedMapPtr)[j->first])
            // DFS traversal
            DFS_helper(j->first, nodeVisitedMapPtr);
    }
    delete nodeVisitedMapPtr;
}


// Search graph in Breadth-first fashion
void Graph::BFS(int v)
{
    // Mark all nodes as not visited
    unordered_map<int, bool> *nodeVisitedMapPtr;
    nodeVisitedMapPtr = new unordered_map<int, bool>({{v, false}, {v, false}});     // initialize map pointer

    unordered_map<int, vector<int>>::iterator i, j;
    for(i = vertexNeighborsMap.begin(); i != vertexNeighborsMap.end(); i++)
        (*nodeVisitedMapPtr)[i->first] = false;

    queue<int> nodesQueue;
    // Traverse each node as start vertex accounting for disconnected graph
    for(j = vertexNeighborsMap.begin(); j != vertexNeighborsMap.end(); j++)
    {
        // If this vertex is not visited, use it as start vertex
        if(!(*nodeVisitedMapPtr)[j->first])
        {
            // Mark it visited
            (*nodeVisitedMapPtr)[j->first] = true;
            // and put it into queue
            nodesQueue.push(j->first);

            // While the queue is not empty
            while(!nodesQueue.empty())
            {
                // Save first vertex in the queue temporarily, and print it
                int node = nodesQueue.front();
                cout << node << " ";
                // Dequeue first vertex
                nodesQueue.pop();

                // Enqueue all unvisited neighbors of first vertex
                vector<int> neighbors = vertexNeighborsMap[node];
                for(unsigned k = 0; k < neighbors.size(); k++)
                {
                    // If the neighbor is not visited
                    if(!(*nodeVisitedMapPtr)[neighbors[k]])
                    {
                        // Mark it as visited and enqueue
                        (*nodeVisitedMapPtr)[neighbors[k]] = true;
                        nodesQueue.push(neighbors[k]);

                    }   // end if
                }   // end for
            }   // end while
        }   // end if
    }   // end for
    delete nodeVisitedMapPtr;
}   // end BFS
