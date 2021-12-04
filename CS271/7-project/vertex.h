#include<vector>
using namespace std;


class Vertex {
    int key;
    Vertex *parent;
    vector<Edge *> edges;
};

class Edge {
    Vertex *dest;
    int weight;
};