#include <string>
#include <sstream>
#include "bst.h"

using namespace std;

// Default constructor
template<class K, class D>
BST<K, D>::BST(){
	this->root = nullptr;
}

// Construct with Node
template<class K, class D>
BST<K, D>::BST(Node<K, D> root){
	this->root = new Node<K, D>(root);
}

// Construct with Node pointer
template<class K, class D>
BST<K, D>::BST(Node<K, D> *root){
	this->root = root;
}

// Deconstructor
template<class K, class D>
BST<K, D>::~BST(){
	this->destroy();
}

// Deallocate all node in BST
template<class K, class D>
void BST<K, D>::destroy(){
	// iterate through all node in tree, delete each one of them
}

// return true if empty, false otherwise
template <class K, class D>
bool BST<K, D>::empty(){
	return this->root == nullptr;
};

// return first Node pointer with key == k
template <class K, class D>
Node<K, D>* BST<K,D>::get(K k){
	Node<K, D> *currentNode = this->root;
	while(currentNode != nullptr && *(currentNode->key) != k){
		if (*(currentNode->key) < k){
			currentNode = currentNode->right;
		}else{
			currentNode = currentNode->left;
		}
	}
	if (currentNode == nullptr){
		throw KeyNotExist();
	}else{
		return currentNode;
	}
};

// insert Node into tree
template <class K, class D>
void BST<K, D>::insert(Node<K, D> *n){
	Node<K, D> *y = nullptr;
	Node<K, D> *x(this->root);
	while (x != nullptr){
		y = x;
		if (*(n->key) < *(x->key)){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	n->parent = y;
	if (y == nullptr){
		this->root = n;
	}else if (*(n->key) < *(y->key)){
		y->left = n;
	}else{
		y->right = n;
	}
}

// utility method for toString method()
template <class K, class D>
void BST<K, D>::treeToString(Node<K, D> *r, string &s){
	if (r == nullptr)
		return;
 
	// push the root key as character
	stringstream ss;
	ss << *(r->key);
	s = s + ss.str();

	// if leaf node, then return
	if (r->left == nullptr && r->right == nullptr)
		return;
	
	if (r->left != nullptr){
		s.push_back('(');
		this->treeToString(r->left, s);
		s.push_back(')');
	}
	if (r->right != nullptr){
		s.push_back('(');
		this->treeToString(r->right, s);
		s.push_back(')');
	}
}

// turn tree into readable string
template <class K, class D>
string BST<K, D>::toString(){
	string s;
	this->treeToString(this->root, s);
	return s;
}