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

pair<string, int> encode2bit(string encoded_string){
	// Pipieline: encode (get original string, return the 010101 string) => encode2bit (get 010101 string, translate to bit-string and write to file)
	stringstream bs;

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
			bs << byte;
			byte = 0;
			count = 0;
		}
	}

	byte = byte << (8-count);
	bs << byte;
	pair<string, int> result (bs.str(), 8 - count);
	return result;
}

string bit2encode(string bit_string){
	char decode_key = 1;
	int count = 0;
	stringstream es;
	// string encoded_string;
	for (int i=0; i < bit_string.size(); i ++){
		for (int count=7; count>=0; count--){
			if (bit_string[i] & (1<<count)){
				es << '1';
			}
			else{
				es << '0';
			}
		}
	}
	return es.str();
}

void encode(string input, string output, Dict<string> dictionary){
	// read input file to inputString
	ifstream inputFile(input);
	ofstream outputFile(output);
	stringstream s;
	s << inputFile.rdbuf();
	string inputString = s.str();

	// encode inputString to encodedString
	stringstream es;
	for (int i = 0; i < inputString.size(); i++){
		char character = inputString[i];
		string encodedChar = dictionary.getValue(character);
		es << encodedChar;
	}
	string encodedString = es.str();
	// encode
	pair<string,int> temp = encode2bit(encodedString);
	string bits = temp.first;
	int pad = temp.second;

	// append dictionary for decode purposes
	outputFile << dictionary.toHeader();

	// append padding to outputFile
	outputFile << pad;

	// convert encodedString to bits and write to outputfile
	outputFile << bits;
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
		const char temp = inputString[i];
		hs << temp;
		i++;
	}
	string headerString = hs.str();
	i = i + 2;

	// extract padding
	int pad = inputString[i] - '0';
	i++;

	// extract data
	stringstream ds;
	while (i < inputString.size()){
		ds << inputString[i];
		i++;
	}
	string dataBitString = ds.str();

	// parse header to dict
	Dict<string> dictionary;
	int j = 0;
	while (j < headerString.size()){
		char key = headerString[j];
		j++;
		stringstream val;
		while (j < headerString.size() && headerString[j] != ','){
			val << headerString[j];
			j++;
		}
		j++;
		dictionary.set(key,val.str());
	}
	string dataString = bit2encode(dataBitString);

	// depadding last bit
	dataString = dataString.substr(0, dataString.size() - pad);

	// decode based on dict
	stringstream code;
	for (int i = 0; i < dataString.size(); i++){
		code << dataString[i];
		if(dictionary.haveValue(code.str())){
			outputFile << dictionary.getKeyByValue(code.str());
			code.str("");
		}
	}
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