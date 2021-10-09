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

void testParentChilds(){
	int initA[3] = {0, 1, 2};
	MinHeap<int> heap = MinHeap<int>(initA, 3);
	assert(heap.parent(1) == 0);
	assert(heap.parent(2) == 0);
	assert(heap.leftChild(0) == 1);
	assert(heap.rightChild(0) == 2);
	cout << "Test Parent Childs Passed" << endl;
}

void testHeapify(){
	int n = 5;
	int initA[5] = {0, 1, 2, 3, 4};
	MinHeap<int> heap = MinHeap<int>(n);
    for(int i = 0; i < n; i++) {
        heap.A[i] = initA[i];
    }
    heap.heapSize = n;
    heap.A[0] = 9;
	heap.heapify(0);
	assert(heap.toString() == "[1, 3, 2, 9, 4 | ]");
	cout << "Heapify " << heap.toString() << " Passed" << endl;
}

void testBuildHeap(){
	int n = 5;
	int initA[5] = {4,3,2,1,0};
	MinHeap<int> heap = MinHeap<int>(initA, n);
    for(int i = 0; i < n; i++) {
        heap.A[i] = initA[i];
    }
	heap.buildHeap();
	assert(heap.toString() == "[0, 1, 2, 4, 3 | ]");
	cout << "Build Heap " << heap.toString() << " Passed" << endl;
}

void testInitConstructor(){
	int initA[5] = {4,3,2,1,0};
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);
	assert(heap1.capacity == 5);
	assert(heap1.heapSize == 5);
    assert(heap1.toString() == "[0, 1, 2, 4, 3 | ]");
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
	assert(heap.toString() == "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10 | ]");
	cout << "Heap Sort " << heap.toString() << " Passed" << endl;
}

int main(){
	testDefaultConstructor();
	testParentChilds();
	testHeapify();
	testBuildHeap();
    
	testInitConstructor();
	testCopyConstructor();
	testAssignmentOperator();
	testHeapSort();
	return 0;
}