#ifndef DICT_H
#define DICT_H
#include "hashTable.h"
#include "data.h"
template <class Key, class Value>
class Dict{
	friend void testDictDestructor();
	public:
		Dict();
		
		~Dict();

		// insert data into list
		void insert(Data<Key, Value> *d);

		// get data from list
		Data<Key, Value>* get(const Data<Key, Value>& d);

		// remove data from list
		void remove(const Data<Key, Value>& d);

		// check if dictionary empty
		bool empty();
	
		// return string representation of dictionary
		string toString();
		
	private:
		HashTable<Data<Key, Value> > *ht;
		int size;
};

#include "dict.cpp"
#endif