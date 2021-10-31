#include <iostream>
#include <string>
#include <assert.h>
#include "bst.h"

using namespace std;

void testNodeConstructors(){
	cout << "Testing Node Constructors" << endl;

	Node<string, int> n1;
	n1.key = new string("hello");
	n1.data = new int(100);
	assert(n1.toString() == "hello: 100");
	cout << "\tTest 1 Passed" << endl;

	Node<string, int> n2(new string("hello"), new int(100));
	assert(n2.toString() == "hello: 100");
	cout << "\tTest 2 Passed" << endl;

	Node<string, int> n3(string("hello"), int(100));
	assert(n3.toString() == "hello: 100");
	cout << "\tTest 3 Passed" << endl;
}

void testNodeDestructor(){
	cout << "Testing Node Destructors" << endl;
	Node<string, int> n1(string("hello"), int(123));
	n1.destroy();
	assert(n1.data == nullptr);
	cout << "\tTest 1 Passed" << endl;
	assert(n1.key == nullptr);
	cout << "\tTest 2 Passed" << endl;
	assert(n1.left == nullptr);
	cout << "\tTest 3 Passed" << endl;
	assert(n1.right == nullptr);
	cout << "\tTest 4 Passed" << endl;
	assert(n1.parent == nullptr);
	cout << "\tTest 5 Passed" << endl;
}

void testBSTConstructors(){
	cout << "Testing BST Constructors" << endl;
	BST<string, int> bst1(new Node<string, int>(string("hello"), int(100)));
	assert(bst1.root->toString() == "hello: 100");
	cout << "\tTest 1 Passed" << endl;
	BST<string, int> bst2(Node<string, int>(string("hello"), int(100)));
	assert(bst2.root->toString() == "hello: 100");
	cout << "\tTest 2 Passed" << endl;
	BST<string, int> bst3;
	bst3.root = new Node<string, int>(string("hello"), int(100));
	assert(bst3.root->toString() == "hello: 100");
	cout << "\tTest 3 Passed" << endl;
	assert(bst1.toString() == "hello");
	cout << "\tTest 4 Passed" << endl;
}

void testBSTInsert(){
	cout << "Testing BST Insert" << endl;
	BST<string, int> bst1;
	bst1.insert(new Node<string, int>(string("key1"), int(1)));
	bst1.insert(new Node<string, int>(string("key2"), int(2)));
	bst1.insert(new Node<string, int>(string("key3"), int(3)));
	bst1.insert(new Node<string, int>(string("key4"), int(4)));
	assert(bst1.toString() == "key1(key2(key3(key4)))");
	cout << "\tTest 1 Passed" << endl;
	BST<string, int> bst2;
	bst2.insert(new Node<string, int>(string("key3"), int(1)));
	bst2.insert(new Node<string, int>(string("key2"), int(2)));
	bst2.insert(new Node<string, int>(string("key1"), int(3)));
	bst2.insert(new Node<string, int>(string("key4"), int(4)));
	assert(bst2.toString() == "key3(key2(key1))(key4)");
	cout << "\tTest 2 Passed" << endl;
}

void testBSTGet(){
	cout << "Testing BST Get" << endl;
	BST<string, int> bst1;
	bst1.insert(new Node<string, int>(string("key1"), int(1)));
	bst1.insert(new Node<string, int>(string("key2"), int(2)));
	bst1.insert(new Node<string, int>(string("key3"), int(3)));
	bst1.insert(new Node<string, int>(string("key4"), int(4)));
	bst1.insert(new Node<string, int>(string("key1"), int(4)));

	Node<string, int> *n1 = bst1.get("key1");
	assert(*(n1->key) == "key1");
	assert(*(n1->data) == 1);
	cout << "\tTest 1 Passed" << endl;

	Node<string, int> *n2 = bst1.get("key4");
	assert(*(n2->key) == "key4");
	assert(*(n2->data) == 4);
	cout << "\tTest 2 Passed" << endl;
}

int main(){
	testNodeConstructors();
	testNodeDestructor();
	testBSTConstructors();
	testBSTInsert();
	testBSTGet();
	return 0;
}
