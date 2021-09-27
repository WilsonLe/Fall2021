#include <bits/stdc++.h>
#include "Set.h"
#include "Set.cpp"

using namespace std;

int main(){
	Set<int> s1 = Set<int>();
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);
	s1.insert(6);

	Set<int> s2 = Set<int>();
	s2.insert(1);
	s2.insert(2);
	s2.insert(3);
	s2.insert(4);
	s2.insert(5);
	s2.insert(69);
	s2.insert(740);

	Set<int> s3 = Set<int>();

	cout << s3;
	return 0;
}