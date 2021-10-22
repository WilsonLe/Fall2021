#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "pq.h"
#include "node.h"
#include "dict.h"

using namespace std;

Dict<int> countFrequency(string input){
	Dict<int> dictionary;
	stringstream s;
	ifstream inputFile (input);
	s << inputFile.rdbuf();
	string fileString = s.str();
	for (int i = 0; i < fileString.size(); i++){
		char character = fileString[i];
		if (dictionary.haveKey(character)){
			int currentFreq = dictionary.getValue(character);
			dictionary.modifyValue(character, currentFreq + 1);
		}else {
			dictionary.set(character, 1);
		}
	}
	return dictionary;
}

Node* huffman(Dict<int> dict){
	int n = dict.size();
	MinPriorityQueue<Node> q;
	for (int i = 0; i < n; i++){
		Node* tempNode = new Node;
		tempNode->key = dict.getKeyByIndex(i);
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

Dict<string> treeToDict(Node* node, Dict<string> dictionary, string current){
	if (node!= NULL){
		if (node->left == nullptr && node->right == nullptr){
			dictionary.set(node->key, current);
			return dictionary;
		}
		current.push_back('0');
		dictionary = treeToDict(node->left, dictionary, current);
		current.pop_back();
		current.push_back('1');
		dictionary = treeToDict(node->right, dictionary, current);
	}
	return dictionary;
}

void encode(string input, string output, Dict<string> dictionary){
	// Remember to read the input file to 
	ifstream inputFile(input);
	ofstream outputFile(output);
	stringstream s;
	s << inputFile.rdbuf();
	string inputString = s.str();
	outputFile << dictionary.toHeader();
	for (int i = 0; i < inputString.size(); i++){
		char character = inputString[i];
		string encodedString = dictionary.getValue(character);
		outputFile << encodedString;
	}
}

void decode(string input, string output){
	ifstream inputFile(input);
	ofstream outputFile(output);

	// read inputFile to text
	stringstream s;
	s << inputFile.rdbuf();
	string inputString = s.str();

	// extract header
	stringstream hs;
	int i = 0;
	while (inputString[i] != ',' || inputString[i+1] != ','){
		hs << string(1, inputString[i]);
		i++;
	}
	string headerString = hs.str();
	i = i + 2;

	// extract data
	stringstream ds;
	while (i < inputString.size()){
		ds << string(1, inputString[i]);
		i++;
	}
	string dataString = ds.str();

	// parse header to dict
	Dict<string> dictionary;
	int j = 0;
	while (j < headerString.size()){
		char key = headerString[j];
		j++;
		stringstream val;
		while (j < headerString.size() && headerString[j] != ','){
			val << string(1, headerString[j]);
			j++;
		}
		j++;
		dictionary.set(key,val.str());
	}

	// decode based on dict
	stringstream code;
	for (int i = 0; i < dataString.size(); i++){
		code << string(1, dataString[i]);
		if(dictionary.haveValue(code.str())){
			outputFile << dictionary.getKeyByValue(code.str());
			code.str("");
		}
	}
}
void encode2bit(string encoded_string, string output){
	// Pipieline: encode (get original string, return the 010101 string) => encode2bit (get 010101 string, translate to bit-string and write to file)
	ofstream outputFile(output);

	char byte = 0;
	int count = 0;
	for (int i=0; i<encoded_string.size(); i++){
		if (encoded_string[i] == '0'){
			byte = byte << 1;
		}
		else if (encoded_string[i] == '1'){
			byte = (byte << 1) | 1;
		}
		count += 1;
		if (count == 8){
			outputFile << byte;
			byte = 0;
			count = 0;
		}
	}

	byte = byte << (8-count);
	outputFile << byte;
	return;
}

string bit2encode(string bit_string){
	//Pipeline: bit2encode(should read file, return string) => decode(write file)
	char decode_key = 1;
	int count = 0;
	string encoded_string;
	for (int i=0; i < bit_string.size(); i ++){
		for (int count=7; count>0; count--){
			if (bit_string[i] & (1<<count)){
				encoded_string.push_back('1');
			}
			else{
				encoded_string.push_back('0');
			}
		}
	}
	return encoded_string;
}
int main(int argc, char* argv[]){
	string action = argv[1];
	string inputFile = argv[2];
	string outputFile = argv[3];

	if (action == "-c"){
		Dict<int> dictFreq = countFrequency(inputFile);
		Node* root = huffman(dictFreq);
		Dict<string> dictHuffman;
		string current;
		dictHuffman = treeToDict(root, dictHuffman, current);
		encode(inputFile, outputFile, dictHuffman);
	} else if (action == "-d"){
		decode(inputFile, outputFile);
	} else{
		cout << "Invalid argument" << endl;
	}
	return 0;
}