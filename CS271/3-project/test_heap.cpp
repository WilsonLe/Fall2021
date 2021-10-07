#include<sstream>
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
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);
	assert(heap1.getCap() == 5);
	assert(heap1.getSize() == 5);
	cout << "Init Constructor Passed" << endl;
}

void copyConstructor(){
	int initA[5] = {0, 1, 2, 3, 4};
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);
	MinHeap<int> heap2 = MinHeap<int>(heap1);
	assert(heap1.toString() == heap2.toString());
	cout << "Copy Constructor Passed" << endl;
}

void assignmentOperator(){
	int initA[5] = {0, 1, 2, 3, 4};
	MinHeap<int> heap1 = MinHeap<int>(initA, 5);
	MinHeap<int> heap2 = heap1;
	assert(heap1.toString() == heap2.toString());
	cout << "Assignment Operator Passed" << endl;
}

void heapSort(int initA[], int n, string assert){
	MinHeap<int> heap = MinHeap<int>(initA, n);
	heap.heapSort(initA);
	stringstream s;
	s << "[";
	for (int i = 0; i < n - 1; i++){
		s << initA[i] << ", ";
	}
	s << initA[n - 1] << "]";
	assert(s.str() == assert);
	cout << "Heap Sort " << s.str() << " Passed" << endl;
}

int main(){
	defaultConstructor();
	initConstructor();
	copyConstructor();
	assignmentOperator();
	int array1[] = {4, 2, 3, 1, 0};
	heapSort(array1, 5, "[0, 1, 2, 3, 4]");
	int array2[] = {10, 8, 9, 1, 2, 4, 5, 3, 7, 6};
	heapSort(array2, 10, "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]");
	int array3[] = {0, 0, 0};
	heapSort(array3, 3, "[0, 0, 0]");
	return 0;
}