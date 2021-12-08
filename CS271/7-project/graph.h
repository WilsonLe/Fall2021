/*
Tung Luu and Wilson Le
*/
#include "vertex.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
  friend void testGraphConstructor();
  friend void testGraphPrim();
  Graph(string fileName);
  Graph(const Graph &otherGraph);
  Graph &operator=(const Graph &otherGraph);
  ~Graph();

  string toString();

  void dfs();
  bool cycle();
  void prim(int root);

private:
  vector<Vertex *> adjList;
  void dfsVisit(Vertex *u);
  bool dfsCycleVisit(Vertex *u, vector<bool> &visited);
};

#include "graph.cpp"
#endif