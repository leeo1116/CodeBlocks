#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char **argv)
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);

    cout << "DFS Traversal (starting from vertex 2)" << endl;
    g.DFS(2);

    return 0;
}
