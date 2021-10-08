#include<sstream>
#include<string>
#include <assert.h>
#include "heap.h"
using namespace std;

void testDefaultConstructor(){
	MinHeap<int> heap1 = MinHeap<int>();
	assert(heap1.capacity == 100);
	assert(heap1.heapSize == 0);
	MinHeap<int> heap2 = MinHeap<int>(50);
	assert(heap2.capacity == 50);
	assert(heap2.heapSize == 0);
	cout << "Default Constructor Passed" << endl;
}

void testInitConstructor(){
	int initA[5] = {0, 1, 2, 3, 4};
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);
	assert(heap1.capacity == 5);
	assert(heap1.heapSize == 5);
	cout << "Init Constructor Passed" << endl;
}

void testCopyConstructor(){
	int initA[5] = {0, 1, 2, 3, 4};
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);
	MinHeap<int> heap2 = MinHeap<int>(heap1);
	assert(heap1.toString() == heap2.toString());
	cout << "Copy Constructor Passed" << endl;
}

void testAssignmentOperator(){
	int initA[5] = {0, 1, 2, 3, 4};
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);
	MinHeap<int> heap2 = heap1;
	assert(heap1.toString() == heap2.toString());
	cout << "Assignment Operator Passed" << endl;
}

void testHeapSort(){
	int initA[10] = {10, 8, 9, 1, 2, 4, 5, 3, 7, 6};
	int n = 10;
	MinHeap<int> heap = MinHeap<int>(initA, n);
	heap.heapSort(initA);
	stringstream s;
	s << "[";
	for (int i = 0; i < n - 1; i++){
		s << initA[i] << ", ";
	}
	s << initA[n - 1] << "]";
	assert(s.str() == "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]");
	cout << "Heap Sort " << s.str() << " Passed" << endl;
}

void testHeapify(){
	int n = 4;
	int initA[4] = {0, 1, 2, 3};
	MinHeap<int> heap = MinHeap<int>(initA, n);
	heap.capacity++;
	heap.A[n] = 4;
	heap.heapSize++;
	heap.heapify(1);
	stringstream s;
	s << "[";
	for (int i = 0; i < heap.heapSize - 1; i++){
		s << heap.A[i] << ", ";
	}
	s << heap.A[heap.heapSize - 1] << "]";
	assert(s.str() == "[0, 1, 2, 3, 4]");
	cout << "Heapify " << s.str() << " Passed" << endl;
}

void testBuildHeap(){
	int n = 5;
	int initA[5] = {0, 2, 3, 5, 7};
	MinHeap<int> heap = MinHeap<int>(initA, n);
	heap.capacity++;
	heap.A[n] = 1;
	heap.heapSize++;
	heap.buildHeap();
	stringstream s;
	s << "[";
	for (int i = 0; i < heap.heapSize - 1; i++){
		s << heap.A[i] << ", ";
	}
	s << heap.A[heap.heapSize - 1] << "]";
	assert(s.str() == "[0, 2, 1, 5, 7, 3]");
	cout << "Build Heap " << s.str() << " Passed" << endl;
}

void testParentChilds(){
	int initA[3] = {0, 1, 2};
	MinHeap<int> heap = MinHeap<int>(initA, 3);
	assert(heap.parent(1) == 0);
	assert(heap.parent(2) == 0);
	assert(heap.leftChild(0) == 1);
	assert(heap.rightChild(0) == 2);
	cout << "Test Parent Childs Passed" << endl;
}

int main(){
	testDefaultConstructor();
	testInitConstructor();
	testCopyConstructor();
	testAssignmentOperator();
	testHeapSort();
	testBuildHeap();
	testHeapify();
	testParentChilds();
	return 0;
}