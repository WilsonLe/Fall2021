#include "graph.h"
#include "pq.h"
using namespace std;

/*
In this implementation, I use a trick to avoid using the decreaseKey operation of the priority queue, since
the decreaseKey operations requires us to save the information about the index of different vertexes in the priority queue, which keeps changing overtime.
In this implementation, instead of using the decrease key operation when update shortest distance to vertex, I just insert that vertex again in the 
pq, and the pq will automatically push that vertex up. To deal with duplicated vertex in the queue, I check if a vertex has already been put into
the MST in O(1). The memory efficiency will not be impacted much, since we have the maximum of O(E) in the priority queue, 
while we already using O(V + E) memory to store graph. 
*/
void Graph::prim(int root) {
    for(Vertex *vertex : adjList) {
        vertex->dist = INT_MAX;
        Vertex->parent = nullptr;
    }

    adjList[root]->dist = 0;
    MinPriorityQueue<Vertex> pq(adjList);
    
    // If the vertex i is already in the MST, then inMST[i] = true, false otherwise.
    vector<bool> inMST(adjList.size(), false);

    while(!pq.empty()) {
        Vertex *top = pq.extractMin();

        // If the vertex has already been put into the MST, then skip this vertex.
        if(inMST[top->key]) continue;
        inMST[top->key] = true;

        for(Edge *edge : top->edges) {
            if(edge->dest->dist > top->dist + edge->weight) {
                edge->dest->dist = top->dist + edge->weight;
                edge->dest->parent = top;
                // Instead of calling decreaseKey and deal with indexes, just insert the vertex again and let the pq put it at the right place
                pq.insert(edge->dest);
            }
        }
    }
}