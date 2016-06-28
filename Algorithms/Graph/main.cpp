#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char **argv)
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.AddEdge(3, 9);
    g.AddEdge(3, 10);
    g.AddEdge(5, 3);
    g.AddEdge(5, 9);
    g.AddEdge(5, 10);
    g.AddEdge(6, 5);
    g.AddEdge(9, 6);
    g.AddEdge(10, 5);

    cout << "DFS Traversal (starting from vertex 3)" << endl;
    g.DFS(3);
    cout << "" << endl;

    cout << "BFS Traversal (starting from vertex 3)" << endl;
    g.BFS(3);

    return 0;
}
