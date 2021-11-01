#ifndef DICT_H
#define DICT_H
#include "bst.h"

template <class K, class D>
class Dict{
	friend void testDictDestructor();
	public:
		Dict();
		
		~Dict();

		// insert data into list
		void insert(K k, D d);

		// get data from list
		D get(K k);

		// remove data from list
		void remove(K k);

		// check if dictionary empty
		bool empty();
	
		// return string representation of dictionary
		string toString();
		
	private:
		BST<K, D> *bst;
};

#include "dict.cpp"
#endif