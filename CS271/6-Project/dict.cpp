#include <sstream>
#include "dict.h"

using namespace std;

template <class K, class V>
Dict<K, V>::Dict(){
	this->ht = new HashTable<Data<K, V> >;
}

template <class K, class V>
Dict<K, V>::~Dict(){
	delete this->ht;
}

template <class K, class V>
void Dict<K, V>::insert(K k, V V){
	this->ht->insert(new Node<K, V>(k, V))
}

template <class K, class V>
V Dict<K, V>::get(K k){
	
	return *(this->ht->get(new Data<k,)->value)
}

template <class K, class V>
void Dict<K, V>::remove(K k){
	this->ht->remove(k)
}

template <class K, class V>
bool Dict<K, V>::empty(){
	return this->bst->empty();
}

template <class K, class V>
string Dict<K, V>::toString(){
	stringstream ss;
	vector<Node<K, V>*> v;
	this->bst->inOrderWalk(this->bst->root, v);
	ss << "{" << endl;
	for (int i = 0; i < v.size(); i++){
		Node<K, V> *n = v[i];
		ss << "\t" << *(n->key) << ": " << *(n->data) << "," << endl;
	}
	ss << "}";
	return ss.str();
}
