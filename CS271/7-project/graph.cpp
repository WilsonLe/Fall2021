#include<iostream>
#include<fstream>
#include<string>
#include "graph.h"
#include "pq.h"
using namespace std;

Graph::Graph(string fileName) {
    ifstream graph(fileName);
    if(graph.is_open()) {
        int numVertexes;
        graph >> numVertexes;
        for(int i = 0; i < numVertexes; i++) {
            adjList.push_back(new Vertex(i));
        }
        for(int i = 0; i < numVertexes; i++) {
            for(int j = 0; j < numVertexes; j++) {
                int weightij;
                graph >> weightij;
                if(i != j && weightij > 0) {
                    adjList[i]->edges.push_back(new Edge(adjList[j], weightij));
                }
            }
        }
    }
}

/*
In this implementation, I use a trick to avoid using the decreaseKey operation of the priority queue, since
the decreaseKey operations requires us to save the information about the index of different vertexes in the priority queue, which keeps changing overtime.
In this implementation, instead of using the decrease key operation when update minimum weight of a vertex, I just insert that vertex again in the 
pq, and the pq will automatically push that vertex up. To deal with duplicated vertex in the queue, I check if a vertex has already been put into
the MST in O(1). The memory efficiency will not be impacted much, since we have the maximum of O(E) in the priority queue, 
while we already using O(V + E) memory to store graph. 
*/
void Graph::prim(int root) {
    for(Vertex *vertex : adjList) {
        vertex->minWeight = INT_MAX;
        Vertex->parent = nullptr;
    }

    adjList[root]->minWeight = 0;
    MinPriorityQueue<Vertex> pq(adjList);

    // If the vertex i is already in the MST, then inMST[i] = true, false otherwise.
    vector<bool> inMST(adjList.size(), false);

    while(!pq.empty()) {
        Vertex *top = pq.extractMin();

        // If the vertex has already been put into the MST, then skip this vertex.
        if(inMST[top->key]) continue;
        inMST[top->key] = true;

        for(Edge *edge : top->edges) {
            if(edge->weight < edge->dest->minWeight) {
                edge->dest->minWeight = edge->weight ;
                edge->dest->parent = top;
                // Instead of calling decreaseKey and deal with indexes, just insert the vertex again and let the pq put it at the right place
                pq.insert(edge->dest);
            }
        }
    }
}