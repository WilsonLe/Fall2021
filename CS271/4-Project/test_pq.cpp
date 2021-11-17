#include <iostream>
#include "pq.h"
#include <assert.h>
using namespace std;

void testDefaultConstructor()
{
	cout << "Test Default Constructor:"<<endl;
	MinPriorityQueue<int>queue(5);
	cout<<"\tTest1: Passed"<<endl;

	return;

}

void testInsert()
{
	cout << "Test Insert function:"<<endl;
	MinPriorityQueue<int>queue(5);
	int* pointer1 = new int(10);
	queue.insert(pointer1);
	assert (queue.toString() == "[10]");
	cout<<"\tTest1: Passed"<<endl;

	int* pointer2 = new int(1);
	queue.insert(pointer2);
	assert (queue.toString() == "[1, 10]");
	cout<<"\tTest2: Passed"<<endl;
	int* pointer3 = new int(3);
	queue.insert(pointer3);

	int* pointer4 = new int(5);
	queue.insert(pointer4);

	int* pointer5 = new int(0);
	queue.insert(pointer5);
	assert(queue.toString() == "[0, 1, 3, 10, 5]");
	cout<<"\tTest3: Passed"<<endl;

}

void testExtractMinimum()
{
	cout<< "Test Extract-Minimum and Minimum:"<<endl;
	MinPriorityQueue<int>queue(5);
	int* pointer1 = new int(10);
	queue.insert(pointer1);

	int* pointer2 = new int(1);
	queue.insert(pointer2);

	int* pointer3 = new int(3);
	queue.insert(pointer3);

	int* pointer4 = new int(5);
	queue.insert(pointer4);

	int* pointer5 = new int(0);
	queue.insert(pointer5);

	assert(*(queue.minimum()) == 0);
	assert(*(queue.extractMin()) == 0);
	assert(queue.toString() == "[1, 5, 3, 10]");
	cout<<"\tTest1: Passed"<<endl;
	assert(*(queue.minimum()) == 1);
	assert(*(queue.extractMin()) == 1);
	cout<<"\tTest2: Passed"<<endl;
	assert(*(queue.minimum()) == 3);
	assert(*(queue.extractMin()) == 3);
	cout<<"\tTest3: Passed"<<endl;
	assert(*(queue.minimum()) == 5);
	assert(*(queue.extractMin()) == 5);
	assert(*(queue.minimum()) == 10);
	assert(*(queue.extractMin()) == 10);
	cout<<"\tTest4: Passed"<<endl; 
}

void testEmptyandLength()
{
	cout<< "Test Empty and Length:"<<endl;
	MinPriorityQueue<int>queue(5);
	assert(queue.empty());
	assert(queue.length() == 0);
	cout<< "\tTest1: Passed"<<endl;

	int* pointer1 = new int(10);
	queue.insert(pointer1);
	assert(!(queue.empty()));
	assert(queue.length() == 1);
	cout<< "\tTest2: Passed"<<endl;

	queue.extractMin();
	assert(queue.empty());
	assert(queue.length() == 0);
	cout<< "\tTest3: Passed"<<endl;
	
}

void testCopyConstructor()
{
	cout<< "Test Copy Constructor:"<<endl;
	
	MinPriorityQueue<int>queue(5);
	MinPriorityQueue<int>test_queue1(queue);
	assert(test_queue1.toString() == "[ ]");
	cout<< "\tTest1: Passed"<< endl;
	int* pointer1 = new int(10);
	queue.insert(pointer1);

	int* pointer2 = new int(1);
	queue.insert(pointer2);

	int* pointer3 = new int(3);
	queue.insert(pointer3);

	int* pointer4 = new int(5);
	queue.insert(pointer4);

	int* pointer5 = new int(0);
	queue.insert(pointer5);

	MinPriorityQueue<int>test_queue2(queue);
	assert(test_queue2.toString() == "[0, 1, 3, 10, 5]");
	cout<< "\tTest2: Passed"<< endl;
}

void testDecreaseKey()
{
	cout<< "Test Decrease Key:"<<endl;
	MinPriorityQueue<int>queue(5);
	int* pointer1 = new int(10);
	queue.insert(pointer1);

	int* pointer2 = new int(1);
	queue.insert(pointer2);

	int* pointer3 = new int(3);
	queue.insert(pointer3);

	int* pointer4 = new int(5);
	queue.insert(pointer4);

	int* pointer5 = new int(0);
	queue.insert(pointer5);
	
	assert(queue.toString() == "[0, 1, 3, 10, 5]");
	queue.decreaseKey(3, new int(-1));
	assert(queue.toString() == "[-1, 0, 3, 1, 5]");
	cout<<"\tTest1: Passed"<<endl;
}
int main()
{
	testDefaultConstructor();
	testInsert();
	testExtractMinimum();
	testEmptyandLength();
	testCopyConstructor();
	testDecreaseKey();
}