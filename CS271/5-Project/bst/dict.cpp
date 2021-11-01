#include <sstream>
#include "dict.h"

using namespace std;

template <class K, class D>
Dict<K, D>::Dict(){
	this->bst = new BST<K, D>;
}

template <class K, class D>
void Dict<K, D>::insert(K k, D d){
	this->bst->insert(new Node<K, D>(k, d));
}

template <class K, class D>
D Dict<K, D>::get(K k){
	return *(this->bst->get(k)->data);
}

template <class K, class D>
void Dict<K, D>::remove(K k){
	this->bst->remove(k);
}

template <class K, class D>
bool Dict<K, D>::empty(){
	return this->bst->empty();
}

template <class K, class D>
string Dict<K, D>::toString(){
	stringstream ss;
	vector<Node<K, D>*> v;
	this->bst->inOrderWalk(this->bst->root, v);
	ss << "{" << endl;
	for (int i = 0; i < v.size(); i++){
		Node<K, D> *n = v[i];
		ss << "\t" << *(n->key) << ": " << *(n->data) << "," << endl;
	}
	ss << "}";
	return ss.str();
}
