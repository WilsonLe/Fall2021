#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class NullKey{};
class NullData{};
class NullKeyAndData{};

template <class K, class D>
class Node{
	public:
		Node();
		~Node();
		Node(K key, D data);
		Node(K* key, D* data);
		K* key;
		D* data;
		Node* left;
		Node* right;
		Node* parent;
		string toString();
		void destroy();
};

#include "node.cpp"

#endif