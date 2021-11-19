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
	assert(s1.hash(numSlots) == 1821);
	cout << "\tTest 1 Passed ✔︎" << endl;
	str s2("Wilson Le");
	assert(s2.hash(numSlots) == 3402);
	cout << "\tTest 2 Passed ✔︎" << endl;
}

void testHtTostring(){
	cout << "Test Hash Table toString" << endl;
	int numSlots = 13001; //prime
	HashTable<Data<str, int> > ht(numSlots);
	assert(ht.toString(0) == "[]");
	cout << "\tTest 1 Passed ✔︎" << endl;
	assert(ht.toString(2) == "[]");
	cout << "\tTest 2 Passed ✔︎" << endl;
	assert(ht.toString(13001) == "[]");
	cout << "\tTest 3 Passed ✔︎" << endl;
}

void testHtConstructor(){
	cout << "Test Hash Table Constructor" << endl;
	int numSlots1 = 13001; //prime
	HashTable<Data<str, int> > ht1(numSlots1);
	assert(ht1.slots == numSlots1);
	cout << "\tTest 1 Passed ✔︎" << endl;
	assert(ht1.table->length() == 0);
	cout << "\tTest 2 Passed ✔︎" << endl;
	assert(ht1.table->toString() == "[]");
	cout << "\tTest 3 Passed ✔︎" << endl;
	int numSlots2 = 13381; //prime
	HashTable<Data<str, int> > ht2(numSlots2);
	assert(ht2.slots == numSlots2);
	cout << "\tTest 4 Passed ✔︎" << endl;
	assert(ht2.table->length() == 0);
	cout << "\tTest 5 Passed ✔︎" << endl;
	assert(ht2.table->toString() == "[]");
	cout << "\tTest 6 Passed ✔︎" << endl;
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
	cout << "\tTest 1 Passed ✔︎" << endl;
	assert(ht1.toString(d2->hash(numSlots)) == "[Wilson Le, Tung Luu]");
	cout << "\tTest 2 Passed ✔︎" << endl;
	assert(ht1.toString(d3->hash(numSlots)) == "[Wilson Le, Tung Luu]");
	cout << "\tTest 3 Passed ✔︎" << endl;
}

void testHtRemove(){
	cout << "Test Hash Table Remove" << endl;
	int numSlots = 13001; //prime
	HashTable<Data<str, string> > ht1(numSlots);
	Data<str, string> *d1 = new Data<str, string>(str("Hello"), "world");
	Data<str, string> *d2 = new Data<str, string>(str("CS271"), "Wilson Le");
	Data<str, string> *d3 = new Data<str, string>(str("CS271"), "Tung Luu");
	ht1.insert(d1);
	ht1.insert(d2);
	ht1.insert(d3);
	ht1.remove(*d1);
	assert(ht1.toString(d1->hash(numSlots)) == "[]");
	cout << "\tTest 1 Passed ✔︎" << endl;
	ht1.remove(*d2);
	assert(ht1.toString(d2->hash(numSlots)) == "[Tung Luu]");
	cout << "\tTest 2 Passed ✔︎" << endl;
	ht1.remove(*d3);
	assert(ht1.toString(d3->hash(numSlots)) == "[]");
	cout << "\tTest 3 Passed ✔︎" << endl;
}

void testHtClone(){
	cout << "Test Hash Table Clone" << endl;
	int numSlots = 11; //prime
	HashTable<Data<str, string> > ht1(numSlots);
	Data<str, string> *d1 = new Data<str, string>(str("Hello"), "world");
	Data<str, string> *d2 = new Data<str, string>(str("CS271"), "Wilson Le");
	Data<str, string> *d3 = new Data<str, string>(str("CS271"), "Tung Luu");
	ht1.insert(d1);
	ht1.insert(d2);
	ht1.insert(d3);
	HashTable<Data<str, string> > ht2 = ht1;
	HashTable<Data<str, string> > ht3(ht1);
	ht2.remove(*d1);
	ht3.remove(*d2);
	assert(ht1.toString(d1->hash(numSlots)) == "[world]");
	cout << "\tTest 1 Passed ✔︎" << endl;
	assert(ht1.toString(d2->hash(numSlots)) == "[Wilson Le, Tung Luu]");
	cout << "\tTest 2 Passed ✔︎" << endl;
	assert(ht1.toString(d3->hash(numSlots)) == "[Wilson Le, Tung Luu]");
	cout << "\tTest 3 Passed ✔︎" << endl;
	assert(ht2.toString(d1->hash(numSlots)) == "[]");
	cout << "\tTest 4 Passed ✔︎" << endl;
	assert(ht2.toString(d2->hash(numSlots)) == "[Wilson Le, Tung Luu]");
	cout << "\tTest 5 Passed ✔︎" << endl;
	assert(ht3.toString(d1->hash(numSlots)) == "[world]");
	cout << "\tTest 6 Passed ✔︎" << endl;
	assert(ht3.toString(d2->hash(numSlots)) == "[Tung Luu]");
	cout << "\tTest 7 Passed ✔︎" << endl;
}

int main(){
	testHash();
	testHtTostring();
	testHtConstructor();
	testHtInsert();
	testHtRemove();
	testHtClone();

	return 0;
}