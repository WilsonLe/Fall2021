#include <iostream>
#include <string>
#include <sstream>
#include "node.h"

using namespace std;

template <class K, class D>
Node<K, D>::Node(K key, D data){
	this->key = new K(key);
	this->data = new D(data);
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

template <class K, class D>
Node<K, D>::Node(K *key, D *data){
	this->key = key;
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

template <class K, class D>
Node<K, D>::Node(){
	this->key = nullptr;
	this->data = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}
template <class K, class D>
Node<K, D>::~Node(){
	this->destroy();
}

template <class K, class D>
string Node<K, D>::toString(){
	stringstream s;
	if (this->key == nullptr && this->data == nullptr){
		throw NullKeyAndData();
	} else if (this->data == nullptr){
		throw NullData();
	} else if (this->data == nullptr){
		throw NullData();
	}else{
		s << *(this->key) << ": " << *(this->data);
	}
	return s.str();
}

template <class K, class D>
void Node<K, D>::destroy(){
	this->key = nullptr;
	this->data = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}