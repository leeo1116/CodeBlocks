#include "Leetcode.h"


UndirectedGraphNode *UndirectedGraphNode::CloneGraphBFS(UndirectedGraphNode *startNode){
    if(!startNode) return NULL;
    UndirectedGraphNode *startNodeCopy = new UndirectedGraphNode(startNode->label);
    graphMap[startNode] = startNodeCopy;
    queue<UndirectedGraphNode *> toVisit;
    toVisit.push(startNode);
    while(!toVisit.empty()){
        UndirectedGraphNode *currentNode = toVisit.front();
        toVisit.pop();
        for(UndirectedGraphNode *n : currentNode->neighbors){
            // if cannot find neighbor
            if(graphMap.find(n) == graphMap.end()){
                UndirectedGraphNode *nCopy = new UndirectedGraphNode(n->label);
                graphMap[n] = nCopy;
                toVisit.push(n);
            }
            graphMap[currentNode]->neighbors.push_back(graphMap[n]);
        }
    }
    return startNodeCopy;
}


UndirectedGraphNode *UndirectedGraphNode::CloneGraphDFS(UndirectedGraphNode *startNode){
    if(!startNode) return NULL;
    if(graphMap.find(startNode) == graphMap.end()){
        graphMap[startNode] = new UndirectedGraphNode(startNode->label);
        for(UndirectedGraphNode *n : startNode->neighbors)
            graphMap[startNode]->neighbors.push_back(CloneGraphDFS(n));
    }
    return graphMap[startNode];
}
