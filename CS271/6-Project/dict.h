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
		void insert(KeyValue *kv);

		// get data from list
		KeyValue* get(const KeyValue& kv);

		// remove data from list
		void remove(const KeyValue& kv);

		// check if dictionary empty
		bool empty();
	
		// return string representation of dictionary
		string toString();
		
	private:
		HashTable<Data<Key, Value> > *ht;
};

#include "dict.cpp"
#endif