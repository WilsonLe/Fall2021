#include <iostream>
#include <vector>
using namespace std;
template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots){
    this->slots = numSlots;
	List<KeyType> *hash_table  = new List<KeyType>[numSlots];
    this->table = hash_table;
}

template <class KeyType>
HashTable<KeyType>::~HashTable(){
	
}

template <class KeyType>
HashTable<KeyType>::HashTable(const HashTable<KeyType>& h){
    // this->slots = h.slots;
	// for (int i=0; i < this->slots; i++){
	// 	this->table[i] = h.table[i]; //deepCopy here
	// }
}

template <class KeyType>
KeyType* HashTable<KeyType>::get(const KeyType& k) const{
    int slot = k.hash() % slots;
    if (this->table[slot].get(k)){
        return this->table[slot].get(k);
    }
    else {
        throw KeyError();
    }
}

template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k){
    int slot = k->hash() % slots;
    this->table[slot].append(k);
}

template <class KeyType>
void HashTable<KeyType>::remove(const KeyType& k){
	int slot = k.hash() % slots;
	table[slot].remove(k);
}

template <class KeyType>
HashTable<KeyType>& HashTable<KeyType>::operator=(const HashTable<KeyType>& h){
	
}

template <class KeyType>
std::string HashTable<KeyType>::toString(int slot) const{
	return this->table[slot].toString();
}