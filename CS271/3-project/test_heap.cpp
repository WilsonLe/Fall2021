#include<ostream>
#include <assert.h>
#include "heap.h"
using namespace std;



void defaultConstructor(){
	MinHeap<int> heap1 = MinHeap<int>();
	assert(heap1.getCap() == 100);
	assert(heap1.getSize() == 0);
	MinHeap<int> heap2 = MinHeap<int>(50);
	assert(heap2.getCap() == 50);
	assert(heap2.getSize() == 0);
	cout << "Default Constructor Passed" << endl;
}

void initConstructor(){
	int initA[5] = {0, 1, 2, 3, 4};
	// this line cause malloc error
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);

	assert(heap1.getCap() == 5);
	assert(heap1.getSize() == 5);
	cout << "Init Constructor Passed" << endl;
}

void copyConstructor(){
	int initA[5] = {0, 1, 2, 3, 4};
	// this line cause malloc error
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);

	MinHeap<int> heap2 = MinHeap<int>(heap1);
	assert(heap1.toString() == heap2.toString());
	cout << "Copy Constructor Passed" << endl;
}

void assignmentOperator(){
	int initA[5] = {0, 1, 2, 3, 4};
	// this line cause malloc error
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);

	MinHeap<int> heap2 = heap1;
	assert(heap1.toString() == heap2.toString());
	cout << "Assignment Operator Passed" << endl;
}

void heapSort(){
	int initA[5] = {0, 1, 2, 3, 4};
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);
}

int main(){
	defaultConstructor();
	// // call the functions below resulted in malloc error
	initConstructor();
	copyConstructor();
	assignmentOperator();

	return 0;
}