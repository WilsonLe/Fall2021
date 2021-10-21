#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
void Dict<T>::set(char key, T val){
	pair<char, T> temp (key, val);
	v.push_back(temp);
}

template <class T>
T Dict<T>::getValue(char key){
	for (int i = 0; i < v.size(); i++){
		if (v[i].first == key){
			return v[i].second;
		}
	}
	throw InvalidKey();
}

template <class T>
char Dict<T>::getKeyByIndex(int index){
	return v[index].first;
}

template <class T>
char Dict<T>::getKeyByValue(T val){
	for (int i = 0; i < v.size(); i++){
		if (v[i].second == val){
			return v[i].first;
		}
	}
	throw InvalidValue();
}

template <class T>
bool Dict<T>::haveValue(T val){
	for (int i = 0; i < v.size(); i++){
		if (v[i].second == val){
			return true;
		}
	}
	return false;
}

template <class T>
bool Dict<T>::haveKey(char key){
	for (int i = 0; i < v.size(); i++){
		if (v[i].first == key){
			return true;
		}
	}
	return false;
}

template <class T>
void Dict<T>::modifyValue(char key, T val){
	for (int i = 0; i < v.size(); i++){
		if (v[i].first == key){
			v[i].second = val;
		}
	}
}

template <class T>
void Dict<T>::remove(char key){
	for (int i = 0; i < v.size(); i++){
		if (v[i].first == key){
			v.erase(v.begin() + i);
		}
	}
}

template <class T>
T Dict<T>::operator[] (int i){
	return v[i].second;
}

template <class T>
int Dict<T>::size(){
	return keys().size();
}

template <class T>
vector<char> Dict<T>::keys(){
	vector<char> out;
	for (int i = 0; i < v.size(); i++){
		out.push_back(v[i].first);
	}
	return out;
}

template <class T>
string Dict<T>::toString(){
	stringstream ss;
	for (int i = 0; i < v.size(); i++){
		string character = string(1, v[i].first);
		if (character == " "){
			ss << "\\" << "s" << ": " << v[i].second << "\n";
		}else if(character == "\n"){
			ss << "\\" << "n" << ": " << v[i].second << "\n";
		}else{
			ss << character << ": " << v[i].second << "\n";
		}
	}
	return ss.str();
}

template <class T>
string Dict<T>::toHeader(){
	std::stringstream ss;
	for (int i = 0; i < v.size(); i++){
		string character = string(1, v[i].first);
		ss << character << v[i].second<<",";
	}
	ss << ",";
	return ss.str();
}

template <class T>
void Dict<T>::printKeys(){
	for (int i = 0; i < v.size(); i++){
		cout<<(v[i].first) <<","<<v[i].second<<endl;
	}
}
