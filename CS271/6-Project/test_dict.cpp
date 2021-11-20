#include "dict.h"
#include<iostream>
#include<climits>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void testDictToString(){
	Dict<str, string> d;
	cout << d.toString() << endl;
}

int main(){
	testDictToString();
	return 0;
}