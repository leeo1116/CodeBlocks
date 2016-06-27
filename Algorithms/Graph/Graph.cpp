#include "Graph.h"


Graph::Graph(int v)
{
    this->vNum = v;             // alternative: vNum = v;
    adj = new list<int>[v];     // list array with v elements, each element is a list object
    //adj = new vector<int>[v];
}


void Graph::AddEdge(int v, int w)
{
    adj[v].push_back(w);    // add w to v's adjacency list
}


void Graph::DFS_helper(int v, bool visited[])
{
    // Mark current node as visited
    visited[v] = true;
    cout << v << " ";

    // Recursion for all vertexes adjacent to node v
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if(!visited[*i])
            DFS_helper(*i, visited);
    }
}


void Graph::DFS(int v)
{
    // Mark all nodes as not visited
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;

    // Call DFS_helper to print all node in DFS sense
    DFS_helper(v, visited);
}


