#include <iostream>
#include <vector>
#include "hashTable.h"
#include "data.h"
using namespace std;

template <class KeyType>
HashTable<KeyType>::HashTable(){
    this->slots = 13001;
	this->table = new List<KeyType>[13001];
}

template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots){
	this->slots = numSlots;
	this->table = new List<KeyType>[numSlots];
}

template <class KeyType>
HashTable<KeyType>::~HashTable(){}

template <class KeyType>
HashTable<KeyType>::HashTable(const HashTable<KeyType>& h){
	this->copy(h);
}

template <class KeyType>
KeyType* HashTable<KeyType>::get(const KeyType& k) const{
	int slot = k.hash(this->slots);
	if (this->table[slot].get(k)){
		return this->table[slot].get(k);
	}
	else {
		throw KeyError();
	}
}

template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k){
	int slot = k->hash(this->slots);
	this->table[slot].append(k);
}

template <class KeyType>
void HashTable<KeyType>::remove(const KeyType& k){
	int slot = k.hash(this->slots);
	table[slot].remove(k);
}

template <class KeyType>
HashTable<KeyType>& HashTable<KeyType>::operator=(const HashTable<KeyType>& h){
	this->copy(h);
	return *this;
}

template <class KeyType>
string HashTable<KeyType>::toString(int slot) const{
	return this->table[slot].toString();
}

template <class KeyType>
string HashTable<KeyType>::toString() const {
	stringstream ss;
	ss << "{" << endl;
	for (int i = 0; i < slots; i++){
        if(this->table[i].length() > 0) {
		    ss << this->table[i].toString() << endl;
        }
	}
	ss << "}";
	return ss.str();
}

template <class KeyType>
void HashTable<KeyType>::copy(const HashTable<KeyType>& h){
	if (this != &h){
		this->slots = h.slots;
		this->table = new List<KeyType>[h.slots];
		// cout << this->slots << endl;
		for (int i=0; i < this->slots; i++){
			this->table[i] = h.table[i]; //deepCopy here
		}
	}
}

