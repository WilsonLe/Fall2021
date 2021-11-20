#include "dict.h"
#include<iostream>
#include<climits>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void testDictToString(){
	cout << "Test Dict toString" << endl;
	Dict<str, string> d;
	d.insert(new Data<str, string>(str("test"), "testValue1"));
	assert(d.toString() == "{\n[test: testValue1]\n}");
	cout << "\tTest 1 Passed ✔︎" << endl;
	d.insert(new Data<str, string>(str("test"), "testValue2"));
	assert(d.toString() == "{\n[test: testValue1, test: testValue2]\n}");
	cout << "\tTest 2 Passed ✔︎" << endl;
	d.insert(new Data<str, string>(str("test1"), "testValue2"));
	assert(d.toString() == "{\n[test1: testValue2]\n[test: testValue1, test: testValue2]\n}");
	cout << "\tTest 3 Passed ✔︎" << endl;
}

void testDictInsert(){
	cout << "Test Dict Insert" << endl;
	Dict<str, string> d;
	d.insert(new Data<str, string>(str("test"), "testValue1"));
	assert(d.toString() == "{\n[test: testValue1]\n}");
	cout << "\tTest 1 Passed ✔︎" << endl;
	d.insert(new Data<str, string>(str("test"), "testValue2"));
	assert(d.toString() == "{\n[test: testValue1, test: testValue2]\n}");
	cout << "\tTest 2 Passed ✔︎" << endl;
	d.insert(new Data<str, string>(str("test1"), "testValue2"));
	assert(d.toString() == "{\n[test1: testValue2]\n[test: testValue1, test: testValue2]\n}");
	cout << "\tTest 3 Passed ✔︎" << endl;
}

void testDictGet(){
	cout << "Test Dict Insert" << endl;
	Dict<str, string> d;
	d.insert(new Data<str, string>(str("A"), "hello"));
	assert(d.get(Data<str, string>(str("A"), ""))->toString() == "A: hello");
	cout << "\tTest 1 Passed ✔︎" << endl;
	d.insert(new Data<str, string>(str("B"), "world"));
	assert(d.get(Data<str, string>(str("B"), ""))->toString() == "B: world");
	cout << "\tTest 2 Passed ✔︎" << endl;
}

void testDictRemove(){
	cout << "Test Dict Insert" << endl;
	Dict<str, string> d;
	d.insert(new Data<str, string>(str("A"), "hello"));
	d.insert(new Data<str, string>(str("A"), "helloo"));
	d.insert(new Data<str, string>(str("B"), "world"));
	d.insert(new Data<str, string>(str("B"), "worldd"));
	d.remove(Data<str, string>(str("A"), ""));
	d.remove(Data<str, string>(str("B"), ""));
	assert(d.get(Data<str, string>(str("A"), ""))->toString() == "A: helloo");
	cout << "\tTest 1 Passed ✔︎" << endl;
	assert(d.get(Data<str, string>(str("B"), ""))->toString() == "B: worldd");
	cout << "\tTest 2 Passed ✔︎" << endl;
}

int main(){
	testDictToString();
	testDictInsert();
	testDictGet();
	testDictRemove();
	return 0;
}