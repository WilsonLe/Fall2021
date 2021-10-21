#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Node::Node(){
	key = '\0';
	left = nullptr;
	right = nullptr;
	freq = new int(0);
}

Node::Node(int n){
	key = '\0';
	left = nullptr;
	right = nullptr;
	freq = &n;
}

string Node::toString(){
	stringstream ss;
	ss << *freq;
	return ss.str();
}

bool operator > (Node left, Node right){
	return left.freq > right.freq;
}

bool operator < (Node left, Node right){
	return left.freq < right.freq;
}

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