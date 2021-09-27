#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>

using namespace std;

template <class T>
class Node { 
	public:
		Node(T data);
		~Node();
		Node* next;
		T data;
};

#endif