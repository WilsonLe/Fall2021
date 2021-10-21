#ifndef DICT_H
#define DICT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InvalidKey { }; // Class when get invalid key
class InvalidValue { }; // Class when invalid value

template <class T>
class Dict{
	private:
		vector< pair<char, T> > v;
	public:
		void set(char key, T val);

		T getValue(char key);

		char getKeyByIndex(int index);

		char getKeyByValue(T val);

		bool haveValue(T val);

		bool haveKey(char key);

		void modifyValue(char key, T val);

		void remove(char key);

		T operator[] (int i);

		int size();

		vector<char> keys();

		string toString();

		string toHeader();

		void printKeys();
};

#include "dict.cpp"
#endif