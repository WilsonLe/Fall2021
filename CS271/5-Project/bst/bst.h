#ifndef BST_H
#define BST_H

#include <string>
#include "node.h"

class KeyNotExist{};

template <class K, class D>
class BST{
	friend void testBSTConstructors();
	friend void testBSTInsert();
	public:
		BST();
		BST(Node<K, D> root);
		BST(Node<K, D> *root);
		~BST();
		// return true if empty, false otherwise
		bool empty() ;

		// return first Node pointer with key == k
		Node<K, D> *get(K k);
		void insert(Node<K, D> *n); // insert Node into tree
		void remove(K& k); // delete first item with key == k
		Node<K, D> *maximum(); // return Node with max key
		Node<K, D> *minimum(); // return Node with min key
		Node<K, D> *successor( K& k); // return successor of Node
		Node<K, D> *predecessor( K& k); // return the predecessor of Node
		string inOrder(); // return items string from an inorder traversal
		string preOrder(); // return items string from a preorder traversal
		string postOrder(); // return items string from a postorder traversal
		// return tree in readable string format
		string toString();
		// utility method for toString method()
		void treeToString(Node<K, D> *r, string &s);
		void destroy();
	private:
		Node<K, D>* root;
};

#include "bst.cpp"
#endif