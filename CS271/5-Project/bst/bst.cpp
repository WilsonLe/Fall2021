#include <string>
#include <sstream>
#include <vector>
#include "bst.h"

using namespace std;

// Default constructor
template<class K, class D>
BST<K, D>::BST(){
	this->root = nullptr;
};

// Construct with Node
template<class K, class D>
BST<K, D>::BST(Node<K, D> root){
	this->root = new Node<K, D>(root);
};

// Construct with Node pointer
template<class K, class D>
BST<K, D>::BST(Node<K, D> *root){
	this->root = root;
};

// Deconstructor
template<class K, class D>
BST<K, D>::~BST(){
	this->destroy();
};

// Deallocate all node in BST
template<class K, class D>
void BST<K, D>::destroy(){
	// iterate through all node in tree, delete each one of them
};

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
};

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
};

// return Node pointer with min key
template <class K, class D>
Node<K, D>* BST<K, D>::minimum(){
	Node<K, D>* currentNode = this->root;
	while (currentNode->left != nullptr){
		currentNode = currentNode->left;
	}
	return currentNode;
};

// return Node pointer with max key
template <class K, class D>
Node<K, D>* BST<K, D>::maximum(){
	Node<K, D>* currentNode = this->root;
	while (currentNode->right != nullptr){
		currentNode = currentNode->right;
	}
	return currentNode;
};

// return successor pointer of Node
template <class K, class D>
Node<K, D>* BST<K, D>::successor(K k){
	Node<K, D> *currentNode = this->get(k);
	if (currentNode->right != nullptr){
		Node<K, D> *min = currentNode->right;
		while (min->left != nullptr){
			min = min->left;
		}
		return min;
	}
	Node<K, D> *suc = currentNode->parent;
	while (suc != nullptr && currentNode == suc->right){
		currentNode = suc;
		suc = suc->parent;
	}
	if (suc == nullptr){
		throw SuccessorNotExist();
	}else{
		return suc;
	}
};

// return the predecessor pointer of Node
template <class K, class D>
Node<K, D>* BST<K, D>::predecessor(K k){
	Node<K, D> *currentNode = this->get(k);
	if (currentNode->left != nullptr){
		Node<K, D> *max = currentNode->left;
		while (max->right != nullptr){
			max = max->right;
		}
		return max;
	}
	Node<K, D> *pre = currentNode->parent;
	while (pre != nullptr && currentNode == pre->left){
		currentNode = pre;
		pre = pre->parent;
	}
	if (pre == nullptr){
		throw PredecessorNotExist();
	}else{
		return pre;
	}
};

// return items string from an in order traversal
template <class K, class D>
string BST<K, D>::inOrder(){
	stringstream ss;
	vector<string> a;
	this->inOrderWalk(this->root, a);
	ss << "[";
	for (int i = 0; i < a.size() - 1; i++){
		ss << a[i] << ", ";
	}
	ss << a[a.size() - 1] << "]";
	return ss.str();
};

// utility function for in order traversal
template <class K, class D>
void BST<K, D>::inOrderWalk(Node<K, D> *r, vector<string> &a){
	if (r != nullptr){
		this->inOrderWalk(r->left, a);
		a.push_back(*(r->key));
		this->inOrderWalk(r->right, a);
	}
};

// return items string from an pre order traversal
template <class K, class D>
string BST<K, D>::preOrder(){
	stringstream ss;
	vector<string> a;
	this->preOrderWalk(this->root, a);
	ss << "[";
	for (int i = 0; i < a.size() - 1; i++){
		ss << a[i] << ", ";
	}
	ss << a[a.size() - 1] << "]";
	return ss.str();
};

// utility function for pre order traversal
template <class K, class D>
void BST<K, D>::preOrderWalk(Node<K, D> *r, vector<string> &a){
	if (r != nullptr){
		a.push_back(*(r->key));
		this->preOrderWalk(r->left, a);
		this->preOrderWalk(r->right, a);
	}
};

// return items string from an post order traversal
template <class K, class D>
string BST<K, D>::postOrder(){
	stringstream ss;
	vector<string> a;
	this->postOrderWalk(this->root, a);
	ss << "[";
	for (int i = 0; i < a.size() - 1; i++){
		ss << a[i] << ", ";
	}
	ss << a[a.size() - 1] << "]";
	return ss.str();
};

// utility function for post order traversal
template <class K, class D>
void BST<K, D>::postOrderWalk(Node<K, D> *r, vector<string> &a){
	if (r != nullptr){
		this->postOrderWalk(r->left, a);
		this->postOrderWalk(r->right, a);
		a.push_back(*(r->key));
	}
};

// turn tree into readable string
template <class K, class D>
string BST<K, D>::toString(){
	string s;
	this->treeToString(this->root, s);
	return s;
};
