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
		void insert(Key k, Value v);

		// get data from list
		Value* get(Key k);

		// remove data from list
		void remove(Key k);

		// check if dictionary empty
		bool empty();
	
		// return string representation of dictionary
		string toString();
		
	private:
		HashTable<Data<Key, Value> > *ht;
};

#include "dict.cpp"
#endif