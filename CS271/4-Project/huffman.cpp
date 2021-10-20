#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "pq.h"
using namespace std;

class Node{
	public:
		Node(){
			left = nullptr;
			right = nullptr;
			freq = new int(0);
		}
		Node(int n){
			left = nullptr;
			right = nullptr;
			freq = &n;
		}

		bool operator > (Node node){
			return freq > node.freq;
		}

		bool operator < (Node node){
			return freq < node.freq;
		}

		Node* left;
		Node* right;
		int* freq;

		string toString(){
			stringstream ss;
			ss << *freq;
			return ss.str();
		}
};
std::stringstream& operator<<(std::stringstream& stream, Node node)
{
	stream << node.toString();
	return stream;
}
std::ostream& operator<<(std::ostream& stream, Node node)
{
	stream << node.toString();
	return stream;
}
std::stringstream& operator<<(std::stringstream& stream, Node* node)
{
	if (node != nullptr){
		stream << node->toString();
		return stream;
	}else{
		return stream;
	}
}
std::ostream& operator<<(std::ostream& stream, Node* node)
{
	if (node != nullptr){
		stream << node->toString();
		return stream;
	}else {
		return stream;
	}
}

template <class T>
class Dict{
	public:
		vector< pair<char, T> > v;
		void set(char key, T val){
			pair<char, T> temp (key, val);
			v.push_back(temp);
		}
		T getValue(char key){
			for (int i = 0; i < v.size(); i++){
				if (v[i].first == key){
					return v[i].second;
				}
			}
		}

		char getKey(T val){
			for (int i = 0; i < v.size(); i++){
				if (v[i].second == val){
					return v[i].first;
				}
			}
		}
		bool have(T val){
			for (int i = 0; i < v.size(); i++){
				if (v[i].second == val){
					return true;
				}
			}
			return false;
		}
		void remove(char key){
			for (int i = 0; i < v.size(); i++){
				if (v[i].first == key){
					v.erase(v.begin() + i);
				}
			}
		}
		T operator[] (int i){
			return v[i].second;
		}
		int size(){
			return keys().size();
		}
		vector<string> keys(){
			vector<string> out;
			for (int i = 0; i < v.size(); i++){
				out.push_back(v[i].first);
			}
			return out;
		}
};

Node* huffman(Dict<int> dict){
	int n = dict.size();
	MinPriorityQueue<Node> q;
	for (int i = 0; i < dict.size(); i++){
		Node* tempNode = new Node;
		int* tempInt = new int(dict[i]);
		tempNode->freq = tempInt;
		q.insert(tempNode);
	}
	for (int i = 0; i < dict.size() - 1; i++){
		Node* tempNode = new Node;
		Node* x = q.extractMin();
		Node* y = q.extractMin();
		tempNode->left = x;
		tempNode->right = y;
		*(tempNode->freq) = *(x->freq) + *(y->freq);
		q.insert(tempNode);
	}
	return q.extractMin();
}

Dict<string> treeToDict(Node* node){
	Dict<string> d;
	while (node->left != nullptr && node->right != nullptr){
		
	}
}

string DataToCode(string data, Dict<string> dictionary){
	// Remember to read the input file to 
	string code;
	for (int i=0; i < data.length(); i ++){
		code += dictionary.getValue(data[i]);
	}
	return code;
}
string CodeToData(string code, Dict<string> dictionary){
	// Remember to read the input file to 
	string data;
	string subcode;

	for (int i=0; i < code.length(); i ++){
		subcode.push_back(code[i]);
		if (dictionary.have(subcode)){
			data.push_back(dictionary.getKey(subcode));
			subcode = "";
		}
	}
	return data;
}

int main(int argc, char* argv[]){
	string action = argv[1];
	string inputFile = argv[2];
	string outputFile = argv[3];
	Dict<string> c;
	c.set('a', "10");
	c.set('b', "20");
	c.set('c', "30");

	if (action == "-c"){
		Node* node = huffman(c);
		cout << node << endl;
	} else if (action == "-d"){

	} else{
		cout << "Invalid argument" << endl;
	}
	return 0;
}