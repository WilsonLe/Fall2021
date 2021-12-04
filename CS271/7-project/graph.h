#include <iostream>
#include "vertex.h"
using namespace std;

class Graph {
    public:
        Graph(string fileName);
        Graph(const Graph& otherGraph);
        Graph& operator=(const Graph& otherGraph);
        ~Graph();

        void dfs();
        bool cycle();
        void prim(int root);

    private:
        vector<Vertex *> adjList;
};