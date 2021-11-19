#include "hashTable.h"
#include<iostream>
#include<climits>
#include<fstream>
#include<vector>
#include<string>

using namespace std;



void testHash(){
	cout << "Test Hash Function" << endl;
	int numSlots = 13001; //prime
	str s1("Tung Luu");
	assert(s1.hash(numSlots) == 5012);
	cout << "\tTest 1 Passed 👍" << endl;
	str s2("Wilson Le");
	assert(s2.hash(numSlots) == 4329);
	cout << "\tTest 2 Passed 👍" << endl;
}

void testHtConstructor(){
	cout << "Test Hash Table Constructor" << endl;
	int numSlots1 = 13001; //prime
	HashTable<Data<str, int> > ht1(numSlots1);
	assert(ht1.slots == numSlots1);
	cout << "\tTest 1 Passed 👍" << endl;
	assert(ht1.table->length() == 0);
	cout << "\tTest 2 Passed 👍" << endl;
	assert(ht1.table->toString() == "[]");
	cout << "\tTest 3 Passed 👍" << endl;
	int numSlots2 = 13381; //prime
	HashTable<Data<str, int> > ht2(numSlots2);
	assert(ht2.slots == numSlots2);
	cout << "\tTest 4 Passed 👍" << endl;
	assert(ht2.table->length() == 0);
	cout << "\tTest 5 Passed 👍" << endl;
	assert(ht2.table->toString() == "[]");
	cout << "\tTest 6 Passed 👍" << endl;
}

void testHtInsert(){
	cout << "Test Hash Table Insert" << endl;
	int numSlots = 13001; //prime
	HashTable<Data<str, string> > ht1(numSlots);
	Data<str, string> *d1 = new Data<str, string>(str("Hello"), "world");
	Data<str, string> *d2 = new Data<str, string>(str("CS271"), "Wilson Le");
	Data<str, string> *d3 = new Data<str, string>(str("CS271"), "Tung Luu");
	ht1.insert(d1);
	ht1.insert(d2);
	ht1.insert(d3);
	assert(ht1.toString(d1->hash(numSlots)) == "[world]");
	cout << "\tTest 1 Passed 👍" << endl;
	assert(ht1.toString(d2->hash(numSlots)) == "[Wilson Le, Tung Luu]");
	cout << "\tTest 2 Passed 👍" << endl;
	assert(ht1.toString(d3->hash(numSlots)) == "[Wilson Le, Tung Luu]");
	cout << "\tTest 3 Passed 👍" << endl;
}

void testHtClone(){
	cout << "Test Hash Table Clone" << endl;
	int numSlots = 13001; //prime
	HashTable<Data<str, int> > ht1(numSlots);
	HashTable<Data<str, int> > ht2(ht1);
	assert(ht2.slots == numSlots);
	cout << "\tTest 1 Passed 👍" << endl;
}

int main(){
	testHash();
	testHtConstructor();
	testHtInsert();
	// testHtClone();

	return 0;
}