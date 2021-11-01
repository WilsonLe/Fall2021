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

void testBSTDestructor(){
	cout << "Testing BST Constructors" << endl;
	BST<string, int> *bst1 = new BST<string, int>(new Node<string, int>(string("hello"), int(100)));
	bst1->destroy();
	cout << "\tTest 1 Passed" << endl;
	BST<string, int> *bst2 = new BST<string, int>(new Node<string, int>(string("world"), int(200)));
	bst2->destroy();
	cout << "\tTest 2 Passed" << endl;
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
	bst2.insert(new Node<string, int>(string("key4"), int(4)));
	assert(bst2.toString() == "key3(key2(key1))(key4(key4))");
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

void testBSTMax(){
	cout << "Testing BST Max" << endl;
	BST<string, int> bst1;
	bst1.insert(new Node<string, int>(string("key1"), int(1)));
	bst1.insert(new Node<string, int>(string("key2"), int(2)));
	bst1.insert(new Node<string, int>(string("key3"), int(3)));
	bst1.insert(new Node<string, int>(string("key4"), int(4)));
	bst1.insert(new Node<string, int>(string("key0"), int(0)));

	Node<string, int> *min1 = bst1.maximum();
	assert(*(min1->key) == "key4");
	assert(*(min1->data) == 4);
	cout << "\tTest 1 Passed" << endl;

	BST<string, int> bst2;
	bst2.insert(new Node<string, int>(string("key1"), int(1)));
	bst2.insert(new Node<string, int>(string("key2"), int(2)));
	bst2.insert(new Node<string, int>(string("key3"), int(3)));
	bst2.insert(new Node<string, int>(string("key4"), int(4)));
	bst2.insert(new Node<string, int>(string("key5"), int(5)));

	Node<string, int> *min2 = bst2.maximum();
	assert(*(min2->key) == "key5");
	assert(*(min2->data) == 5);
	cout << "\tTest 2 Passed" << endl;
}

void testBSTMin(){
	cout << "Testing BST Min" << endl;
	BST<string, int> bst1;
	bst1.insert(new Node<string, int>(string("key1"), int(1)));
	bst1.insert(new Node<string, int>(string("key2"), int(2)));
	bst1.insert(new Node<string, int>(string("key3"), int(3)));
	bst1.insert(new Node<string, int>(string("key4"), int(4)));
	bst1.insert(new Node<string, int>(string("key0"), int(0)));

	Node<string, int> *min1 = bst1.minimum();
	assert(min1->toString() == "key0: 0");
	cout << "\tTest 1 Passed" << endl;

	BST<string, int> bst2;
	bst2.insert(new Node<string, int>(string("key1"), int(1)));
	bst2.insert(new Node<string, int>(string("key2"), int(2)));
	bst2.insert(new Node<string, int>(string("key3"), int(3)));
	bst2.insert(new Node<string, int>(string("key4"), int(4)));

	Node<string, int> *min2 = bst2.minimum();
	assert(min2->toString() == "key1: 1");
	cout << "\tTest 2 Passed" << endl;
}

void testBSTSuccessor(){
	cout << "Testing BST Successor" << endl;
	BST<string, int> bst;
	bst.insert(new Node<string, int>(string("key3"), int(3)));
	bst.insert(new Node<string, int>(string("key5"), int(5)));
	bst.insert(new Node<string, int>(string("key2"), int(2)));
	bst.insert(new Node<string, int>(string("key4"), int(4)));
	bst.insert(new Node<string, int>(string("key1"), int(1)));
	bst.insert(new Node<string, int>(string("key0"), int(0)));
	Node<string, int> *suc1 = bst.successor("key4");
	assert(suc1->toString() == "key5: 5");
	cout << "\tTest 1 Passed" << endl;
	Node<string, int> *suc2 = bst.successor("key2");
	assert(suc2->toString() == "key3: 3");
	cout << "\tTest 2 Passed" << endl;
	Node<string, int> *suc3 = bst.successor("key3");
	assert(suc3->toString() == "key4: 4");
	cout << "\tTest 3 Passed" << endl;
	Node<string, int> *suc4 = bst.successor("key1");
	assert(suc4->toString() == "key2: 2");
	cout << "\tTest 4 Passed" << endl;
}

void testBSTPredecessor(){
	cout << "Testing BST Predecessor" << endl;
	BST<string, int> bst;
	bst.insert(new Node<string, int>(string("key3"), int(3)));
	bst.insert(new Node<string, int>(string("key5"), int(5)));
	bst.insert(new Node<string, int>(string("key2"), int(2)));
	bst.insert(new Node<string, int>(string("key4"), int(4)));
	bst.insert(new Node<string, int>(string("key1"), int(1)));
	bst.insert(new Node<string, int>(string("key0"), int(0)));
	Node<string, int> *pre1 = bst.predecessor("key4");
	assert(pre1->toString() == "key3: 3");
	cout << "\tTest 1 Passed" << endl;
	Node<string, int> *pre2 = bst.predecessor("key1");
	assert(pre2->toString() == "key0: 0");
	cout << "\tTest 2 Passed" << endl;
	Node<string, int> *pre3 = bst.predecessor("key5");
	assert(pre3->toString() == "key4: 4");
	cout << "\tTest 3 Passed" << endl;
	Node<string, int> *pre4 = bst.predecessor("key1");
	assert(pre4->toString() == "key0: 0");
	cout << "\tTest 4 Passed" << endl;
}

void testBSTInOrder(){
	cout << "Testing BST In Order" << endl;
	BST<string, int> bst1;
	bst1.insert(new Node<string, int>(string("key3"), int(3)));
	bst1.insert(new Node<string, int>(string("key5"), int(5)));
	bst1.insert(new Node<string, int>(string("key2"), int(2)));
	bst1.insert(new Node<string, int>(string("key4"), int(4)));
	bst1.insert(new Node<string, int>(string("key1"), int(1)));
	bst1.insert(new Node<string, int>(string("key0"), int(0)));
	assert(bst1.inOrder() == "[key0, key1, key2, key3, key4, key5]");
	cout << "\tTest 1 Passed" << endl;
	BST<string, int> bst2;
	bst2.insert(new Node<string, int>(string("key2"), int(3)));
	bst2.insert(new Node<string, int>(string("key1"), int(5)));
	bst2.insert(new Node<string, int>(string("key6"), int(2)));
	bst2.insert(new Node<string, int>(string("key2"), int(4)));
	bst2.insert(new Node<string, int>(string("key4"), int(1)));
	bst2.insert(new Node<string, int>(string("key9"), int(0)));
	assert(bst2.inOrder() == "[key1, key2, key2, key4, key6, key9]");
	cout << "\tTest 2 Passed" << endl;
	BST<string, int> bst3;
	bst3.insert(new Node<string, int>(string("hello"), int(3)));
	bst3.insert(new Node<string, int>(string("world"), int(5)));
	bst3.insert(new Node<string, int>(string("CS"), int(2)));
	bst3.insert(new Node<string, int>(string("271"), int(4)));
	bst3.insert(new Node<string, int>(string("Wilson"), int(1)));
	bst3.insert(new Node<string, int>(string("Le"), int(0)));
	bst3.insert(new Node<string, int>(string("Minh"), int(1)));
	bst3.insert(new Node<string, int>(string("Nguyen"), int(0)));
	assert(bst3.inOrder() == "[271, CS, Le, Minh, Nguyen, Wilson, hello, world]");
	cout << "\tTest 3 Passed" << endl;
}

void testBSTPreOrder(){
	cout << "Testing BST Pre Order" << endl;
	BST<string, int> bst1;
	bst1.insert(new Node<string, int>(string("key3"), int(3)));
	bst1.insert(new Node<string, int>(string("key5"), int(5)));
	bst1.insert(new Node<string, int>(string("key2"), int(2)));
	bst1.insert(new Node<string, int>(string("key4"), int(4)));
	bst1.insert(new Node<string, int>(string("key1"), int(1)));
	bst1.insert(new Node<string, int>(string("key0"), int(0)));
	assert(bst1.preOrder() == "[key3, key2, key1, key0, key5, key4]");
	cout << "\tTest 1 Passed" << endl;
	BST<string, int> bst2;
	bst2.insert(new Node<string, int>(string("key2"), int(3)));
	bst2.insert(new Node<string, int>(string("key1"), int(5)));
	bst2.insert(new Node<string, int>(string("key6"), int(2)));
	bst2.insert(new Node<string, int>(string("key2"), int(4)));
	bst2.insert(new Node<string, int>(string("key4"), int(1)));
	bst2.insert(new Node<string, int>(string("key9"), int(0)));
	assert(bst2.preOrder() == "[key2, key1, key6, key2, key4, key9]");
	cout << "\tTest 2 Passed" << endl;
	BST<string, int> bst3;
	bst3.insert(new Node<string, int>(string("hello"), int(3)));
	bst3.insert(new Node<string, int>(string("world"), int(5)));
	bst3.insert(new Node<string, int>(string("CS"), int(2)));
	bst3.insert(new Node<string, int>(string("271"), int(4)));
	bst3.insert(new Node<string, int>(string("Wilson"), int(1)));
	bst3.insert(new Node<string, int>(string("Minh"), int(1)));
	assert(bst3.preOrder() == "[hello, CS, 271, Wilson, Minh, world]");
	cout << "\tTest 3 Passed" << endl;
}

void testBSTPostOrder(){
	cout << "Testing BST Post Order" << endl;
	BST<string, int> bst1;
	bst1.insert(new Node<string, int>(string("key3"), int(3)));
	bst1.insert(new Node<string, int>(string("key5"), int(5)));
	bst1.insert(new Node<string, int>(string("key2"), int(2)));
	bst1.insert(new Node<string, int>(string("key4"), int(4)));
	bst1.insert(new Node<string, int>(string("key1"), int(1)));
	bst1.insert(new Node<string, int>(string("key0"), int(0)));
	assert(bst1.postOrder() == "[key0, key1, key2, key4, key5, key3]");
	cout << "\tTest 1 Passed" << endl;
	BST<string, int> bst2;
	bst2.insert(new Node<string, int>(string("key2"), int(3)));
	bst2.insert(new Node<string, int>(string("key1"), int(5)));
	bst2.insert(new Node<string, int>(string("key6"), int(2)));
	bst2.insert(new Node<string, int>(string("key2"), int(4)));
	bst2.insert(new Node<string, int>(string("key4"), int(1)));
	bst2.insert(new Node<string, int>(string("key9"), int(0)));
	assert(bst2.postOrder() == "[key1, key4, key2, key9, key6, key2]");
	cout << "\tTest 2 Passed" << endl;
	BST<string, int> bst3;
	bst3.insert(new Node<string, int>(string("hello"), int(3)));
	bst3.insert(new Node<string, int>(string("world"), int(5)));
	bst3.insert(new Node<string, int>(string("CS"), int(2)));
	bst3.insert(new Node<string, int>(string("271"), int(4)));
	bst3.insert(new Node<string, int>(string("Wilson"), int(1)));
	bst3.insert(new Node<string, int>(string("Minh"), int(1)));
	assert(bst3.postOrder() == "[271, Minh, Wilson, CS, world, hello]");
	cout << "\tTest 3 Passed" << endl;
}

void testBSTRemove(){
	cout << "Testing BST Delete" << endl;
	BST<string, int> bst1;
	bst1.insert(new Node<string, int>(string("key3"), int(3)));
	bst1.insert(new Node<string, int>(string("key5"), int(5)));
	bst1.insert(new Node<string, int>(string("key2"), int(2)));
	bst1.insert(new Node<string, int>(string("key4"), int(4)));
	bst1.insert(new Node<string, int>(string("key1"), int(1)));
	bst1.insert(new Node<string, int>(string("key0"), int(0)));
	bst1.remove("key4");
	assert(bst1.toString() == "key3(key2(key1(key0)))(key5)");
	cout << "\tTest 1 Passed" << endl;
	bst1.remove("key3");
	assert(bst1.toString() == "key5(key2(key1(key0)))");
	cout << "\tTest 2 Passed" << endl;
	bst1.remove("key1");
	assert(bst1.toString() == "key5(key2(key0))");
	cout << "\tTest 3 Passed" << endl;
	bst1.remove("key2");
	assert(bst1.toString() == "key5(key0)");
	cout << "\tTest 4 Passed" << endl;
	bst1.remove("key5");
	assert(bst1.toString() == "key0");
	cout << "\tTest 5 Passed" << endl;
	bst1.remove("key0");
	assert(bst1.toString() == "");
	cout << "\tTest 6 Passed" << endl;
};

int main(){
	testNodeConstructors();
	testNodeDestructor();
	testBSTConstructors();
	testBSTDestructor();
	testBSTInsert();
	testBSTGet();
	testBSTMax();
	testBSTMin();
	testBSTSuccessor();
	testBSTPredecessor();
	testBSTInOrder();
	testBSTPreOrder();
	testBSTPostOrder();
	testBSTRemove();
	return 0;
}
