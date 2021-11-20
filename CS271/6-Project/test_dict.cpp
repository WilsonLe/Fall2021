#include "dict.h"
#include<iostream>
#include<climits>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void testDictToString(){
	Dict<str, string> d;
    Data<str, string> * test = new Data<str, string>(str("test"), "testValue");
    d.insert(test);
	cout << d.toString() << endl;
}

int main(){
	testDictToString();
	return 0;
}