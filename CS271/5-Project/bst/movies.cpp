#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "dict.h"

using namespace std;

vector<string> split(string s, string del){
	vector<string> v;
	int start = 0;
	int end = s.find(del);
	while (end != -1) {
		v.push_back(s.substr(start, end - start));
		start = end + del.size();
		end = s.find(del, start);
	}
	return v;
}

int main(){
	ifstream f("movies_mpaa.txt");
	Dict<string, string> movieDict;
	string line;
	stringstream c;
	while(getline(f, line)){
		vector<string> v = split(line, "\t");
		stringstream c;
		for (int i = 1; i < v.size() - 1; i++){
			c << v[i] << ", ";
		}
		c << v[v.size() - 1];
		string casts = c.str();
		string title = v[0];
		movieDict.insert(title, casts);
	}

	// "movieDict" is the dictionary that contains all movie info.
	// use .get(key: string) to get movie casts
	return 0;
}