#ifndef SET_H
#define SET_H
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

template <class T>
class Set {
	public:
		Set();
		~Set();
		void insert(T data);
		void remove(T data);
		int cardinality() const;
		bool empty() const;
		bool contains(T data) const;
		string toString() const;
		Node<T>* head;
		Node<T>* tail;
	private:
		void removeAtIndex(int index);
};

#endif