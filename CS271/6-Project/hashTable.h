#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include "list.h"
template <class KeyType>
class HashTable
{
public:
    HashTable(int numSlots);
    HashTable(const HashTable<KeyType>& h);
    ~HashTable();
    KeyType* get(const KeyType& k) const;
    void insert(KeyType *k);
    void remove(const KeyType& k);
    HashTable<KeyType>& operator=(const HashTable<KeyType>& h);
    std::string toString(int slot) const;
private:
    int slots;
    List<KeyType> *table;  // an array of List<KeyType>’s
};

class KeyError { };
#include "hashTable.cpp"
#endif