#include <iostream>
#include <vector>
#include "hashTable.h"
#include "data.h"
using namespace std;

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
	int slot = k.hash();
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
std::string HashTable<KeyType>::toString(int slot) const{
	return this->table[slot].toString();
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

