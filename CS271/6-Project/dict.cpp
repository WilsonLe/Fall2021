#include <sstream>
#include "hashTable.h"
#include "dict.h"
using namespace std;

template <class Key, class Value>
Dict<Key, Value>::Dict(){
	this->size = 13001;
	this->ht = new HashTable<Data<Key, Value> >(this->size);
}

template <class Key, class Value>
Dict<Key, Value>::~Dict(){
	delete this->ht;
}

template <class Key, class Value>
void Dict<Key, Value>::insert(Data<Key, Value> *d){
	this->ht->insert(d);
}

// template <class Key, class V>
// V Dict<Key, V>::get(Key k){

// 	// return *(this->ht->get(new Data<k,)->value)
// }

// template <class Key, class V>
// void Dict<Key, V>::remove(Data<K, V>& d){

// 	this->ht->remove(k);
// }

// template <class K, class V>
// bool Dict<K, V>::empty(){

// 	return this->bst->empty();
// }

template <class Key, class Value>
string Dict<Key, Value>::toString(){
	stringstream ss;
	ss << "{" << endl;
	for (int i = 0; i < this->size; i++){
		cout << this->ht[i].length() << endl;
	}
	ss << "}";
	return ss.str();
}
