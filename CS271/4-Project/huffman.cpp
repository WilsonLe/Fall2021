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

MinPriorityQueue<Node> huffman(vector< pair<char, int> > c){
	int n = c.size();
	MinPriorityQueue<Node> q;
	for (int i = 0; i < c.size(); i++){
		Node* tempNode = new Node;
		int* tempInt = new int;
		tempInt = &c[i].second;
		tempNode->freq = tempInt;
		q.insert(tempNode);
	}
	Node* tempNode = new Node;
	// cout << tempNode;
	cout << q << endl;
	return q;
}

int main(int argc, char* argv[]){
	string action = argv[1];
	string inputFile = argv[2];
	string outputFile = argv[3];
	vector< pair<char, int> > c;
	pair<char, int> p1 ('a', 10);
	c.push_back(p1);
	pair<char, int> p2 ('b', 20);
	c.push_back(p2);
	pair<char, int> p3 ('c', 30);
	c.push_back(p3);

	if (action == "-c"){
		huffman(c);
	} else if (action == "-d"){

	} else{
		cout << "Invalid argument" << endl;
	}
	return 0;
}