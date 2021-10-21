#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node{
	public:
		Node();
		Node(int n);
		string toString();
		Node* left;
		Node* right;
		int* freq;
		char key;
};
#include "node.cpp"
#endif