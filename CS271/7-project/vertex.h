#include<vector>
using namespace std;

#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
    public:
        int key;
        int dist; // distance from source vertex.
        Vertex *parent;
        vector<Edge *> edges;

        bool operator < (const Vertex& other) {
            return (this->dist < other.dist);
        } 

        bool operator > (const Vertex& other) {
            return (this->dist > other.dist);
        } 
};

class Edge {
    public:
        Vertex *dest;
        int weight;
};

#endif VERTEX_H