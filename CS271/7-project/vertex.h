/*
Tung Luu and Wilson Le
*/
#include <string>
#include <vector>

using namespace std;

#ifndef VERTEX_H
#define VERTEX_H

class Vertex;

class Edge {
public:
  Vertex *dest;
  int weight;

  Edge(Vertex *dest, int weight) : dest(dest), weight(weight){};
};

class Vertex {
public:
  int key;
  int minWeight; // minimum weight of any edge connecting v to a vertex in the
                 // tree
  Vertex *parent;
  vector<Edge *> edges;
  bool visited;

  bool operator<(const Vertex &other) {
    return (this->minWeight < other.minWeight);
  }

  bool operator<=(const Vertex &other) {
    return (this->minWeight <= other.minWeight);
  }

  bool operator>(const Vertex &other) {
    return (this->minWeight > other.minWeight);
  }

  Vertex(int key) : key(key){};
};
#endif