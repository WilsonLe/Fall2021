#include "graph.h"
#include "pq.h"
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Graph::Graph(string fileName) {
  ifstream graph(fileName);
  if (graph.is_open()) {
    int numVertexes;
    graph >> numVertexes;
    for (int i = 0; i < numVertexes; i++) {
      adjList.push_back(new Vertex(i));
    }
    for (int i = 0; i < numVertexes; i++) {
      for (int j = 0; j < numVertexes; j++) {
        int weightij;
        graph >> weightij;
        if (i != j && weightij > 0) {
          adjList[i]->edges.push_back(new Edge(adjList[j], weightij));
        }
      }
    }
  }
}

Graph::~Graph() {}

string Graph::toString() {
  stringstream ss;
  for (Vertex *v : this->adjList) {
    ss << v->key << ": ";
    for (Edge *e : v->edges) {
      ss << e->dest->key << " ";
    }
    ss << endl;
  }
  return ss.str();
}

void Graph::dfs() {
  for (Vertex *vertex : adjList) {
    vertex->visited = false;
  }
  for (Vertex *vertex : adjList) {
    if (vertex->visited == false) {
      this->dfsVisit(vertex);
      cout << endl;
    }
  }
}

void Graph::dfsVisit(Vertex *u) {
  u->visited = true;
  cout << u->key << " ";
  for (Edge *edge : this->adjList[u->key]->edges) {
    if (edge->dest->visited == false) {
      dfsVisit(edge->dest);
    }
  }
}

bool Graph::cycle() {
  for (Vertex *vertex : adjList) {
    vertex->visited = false;
  }
  for (Vertex *vertex : adjList) {
    if (vertex->visited == false) {
      bool hasCycle = this->dfsCycleVisit(vertex);
      if (hasCycle == true) {
        return true;
      }
    }
  }
  return false;
}

bool Graph::dfsCycleVisit(Vertex *u) {
  u->visited = true;
  for (Edge *edge : this->adjList[u->key]->edges) {
    if (edge->dest->visited == false) {
      return this->dfsCycleVisit(edge->dest);
    } else {
      return true;
    }
  }
  return false;
}

/*
In this implementation, I use a trick to avoid using the decreaseKey operation
of the priority queue, since the decreaseKey operations requires us to save the
information about the index of different vertexes in the priority queue, which
keeps changing overtime. In this implementation, instead of using the decrease
key operation when update minimum weight of a vertex, I just insert that vertex
again in the pq, and the pq will automatically push that vertex up. To deal with
duplicated vertex in the queue, I check if a vertex has already been put into
the MST in O(1). The memory efficiency will not be impacted much, since we have
the maximum of O(E) vertices in the priority queue, while we already using O(V +
E) memory to store graph. The time complexity will be O(E log(E)), but since E =
O(V^2) => log(E) = O(log(V^2)) = O(logV). Therefore, the time complexity will be
O(E logV)
*/
void Graph::prim(int root) {
  // The total number of edges in the graph
  int numEdges = 0;

  for (Vertex *vertex : adjList) {
    vertex->minWeight = INT_MAX;
    vertex->parent = nullptr;
    numEdges += vertex->edges.size();
  }

  adjList[root]->minWeight = 0;

  // We will have at maximum O(E) vertices in the priority queue
  MinPriorityQueue<Vertex> pq(numEdges / 2);
  pq.insert(adjList[root]);

  // If the vertex i is already in the MST, then inMST[i] = true, false
  // otherwise.
  vector<bool> inMST(adjList.size(), false);

  while (!pq.empty()) {
    Vertex *top = pq.extractMin();
    // If the vertex has already been put into the MST, then skip this vertex.
    if (inMST[top->key])
      continue;
    inMST[top->key] = true;

    for (Edge *edge : top->edges) {
      if (!inMST[edge->dest->key] && edge->weight < edge->dest->minWeight) {
        edge->dest->minWeight = edge->weight;
        edge->dest->parent = top;
        // Instead of calling decreaseKey and deal with indexes, just insert the
        // vertex again and let the pq put it at the right place
        pq.insert(edge->dest);
      }
    }
  }

  for (Vertex *vertex : adjList) {
    if (vertex->parent == nullptr && vertex != adjList[root]) {
      cout << "The graph is disconnected. Therefore, prim operation is not "
              "possible."
           << '\n';
      return;
    }
  }

  for (Vertex *vertex : adjList) {
    if (vertex->parent) {
      cout << vertex->parent->key << " " << vertex->key << " "
           << vertex->minWeight << '\n';
    }
  }
}
