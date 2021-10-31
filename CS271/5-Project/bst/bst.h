#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
#include "node.h"

// error when get(key) does not exist in BST
class KeyNotExist{};

// error when tree node has no predecessor
class PredecessorNotExist{};

// error when tree node has no successor
class SuccessorNotExist{};

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

		// insert Node into tree
		void insert(Node<K, D> *n);

		// delete first item with key == k
		void remove(K& k); 

		// return Node with max key
		Node<K, D> *maximum();

		// return Node with min key
		Node<K, D> *minimum();

		// return successor pointer of Node
		Node<K, D> *successor(K k);

		// return the predecessor pointer of Node
		Node<K, D> *predecessor(K k);

		// return items string from an in order traversal
		string inOrder();

		// return items string from a preorder traversal
		string preOrder(); 

		// return items string from a postorder traversal
		string postOrder(); 

		// return tree in readable string format
		string toString();
	private:
		Node<K, D>* root;
		// utility function for in order traversal
		void inOrderWalk(Node<K, D> *r, vector<string> &a);
		// utility function for in preorder traversal
		void preOrderWalk(Node<K, D> *r, vector<string> &a);
		// utility function for in postorder traversal
		void postOrderWalk(Node<K, D> *r, vector<string> &a);
		// utility method for toString method()
		void treeToString(Node<K, D> *r, string &s);
		// utility method for deallocating bst
		void destroy();
};

#include "bst.cpp"
#endif