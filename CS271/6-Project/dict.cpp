#include <sstream>
#include "hashTable.h"
#include "dict.h"
using namespace std;

template <class Key, class Value>
Dict<Key, Value>::Dict(){
	this->size = 13001;
	this->ht = HashTable<Data<Key, Value>>(size);
}

template <class Key, class Value>
void Dict<Key, Value>::insert(Data<Key, Value> *d){
	this->ht.insert(d);
}

template <class Key, class Value>
Data<Key, Value> * Dict<Key, Value>::get(const Data<Key, Value>& k) const {
    return this->ht.get(k);
}

template <class Key, class Value>
void Dict<Key, Value>::remove(const Data<Key, Value>& k){

	this->ht.remove(k);
}

template <class Key, class Value>
bool Dict<Key, Value>::empty() const {

	return this->ht.empty();
}

template <class Key, class Value>
string Dict<Key, Value>::toString(){
    return ht.toString();
}
