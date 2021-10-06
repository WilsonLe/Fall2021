/*
Class: CS 271, Fall 2021
Professor: Jessen Havill
Name: Tung Luu, Wilson Le
Date: October 4, 2021
Purpose: Answers to project 3
*/
// heap.cpp

#include <sstream>

/* 
The default constructor. Allocate the array A of the heap with size n, set heapSize = 0 and capacity to n.
Preconditions: the parameter n is either missing, or n must be a non-negative integer.
Postconditions: Return a new instance of MinHeap whose heapSize is 0 and capacity is either n or DEFAULT_SIZE if no parameter n is provided
*/

template <class KeyType>
MinHeap<KeyType>::MinHeap(int n = DEFAULT_SIZE) {
    A = new KeyType[n];
    heapSize = 0;
    capacity = n;
}

/* 
Allocate new array A of the heap, copy the content from initA to A and the call buildHeap to build a correct heap from A.
Preconditions: n must be a non-negative integer
Postconditions: Return a new instance of MinHeap whose internal array is the same as initA and capacity is n.
*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(KeyType initA[], int n) {
    capacity = n;
    for(int i = 0; i < capacity; i++) {
        A[i] = initA[i];
    }
    buildHeap();
}

/*
Copy constructor
Preconditions: None
Postconditions: Return a new instance of MinHeap whose instance variables are the same as heap.
*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap) {
    copy(heap);
}

/* 
Destructor
Preconditions: None
Postconditions: Completely remove this min heap from memory.
*/
template <class KeyType>
MinHeap<KeyType>::~MinHeap() {
    destroy();
}

// Perform heapsort, return result in the sorted array
template<class KeyType>
void MinHeap<KeyType>::heapSort(KeyType sorted[]) {
    int initialHeapSize = heapSize;

    for(int i = heapSize - 1; i >= 1; i--) {
        swap(0, i);
        heapSize--;
        heapify(0);
    }

    // Change the heapSize back into its initial value
    heapSize = initialHeapSize;

    // Now A is sorted in reverse order. We just need copy A to sorted in reverse order.
    for(int i = 0; i < heapSize; i++) {
        sorted[i] = A[heapSize - i - 1];
    }

    // Reverse A to turn A back into a correct heap
    for(int i = 0; i < heapSize; i++) {
        A[i] = sorted[i];
    }

}

// Heapify subheap rooted at index
template<class KeyType>
void MinHeap<KeyType>::heapify(int index) {
    heapifyR(index);
}

// Build heap from the array A
template <class KeyType> 
void MinHeap<KeyType>::buildHeap() {
    heapSize = capacity;
    // Iterate from the node (capacity / 2) - 1 to 0, which is iterating in bottom-up method, and call heapify in each iteration
    for(int i = (capacity / 2) - 1; i >= 0; i--) {
        heapify(i);
    }
}

// Heapify subheap rooted at index using recursive method
template<class KeyType>
void MinHeap<KeyType>::heapifyR(int index) {
    int left = leftChild(index);
    int right = rightChild(index);
    int smallestChild = index;

    if(left < heapSize && A[left] < A[index]) {
        smallestChild = left;
    }

    if(right < heapSize && A[right] < A[smallestChild]) {
        smallestChild = right;
    }

    if(smallestChild != index) {
        swap(index, smallestChild);
        heapify(smallestChild);
    }
}

// Heapify subheap rooted at index using iterative method
template<class KeyType>
void MinHeap<KeyType>::heapifyR(int index) {
    while(leftChild(index) < heapSize) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallestChild = index;

        if(left < heapSize && A[left] < A[index]) {
            smallestChild = left;
        }

        if(right < heapSize && A[right] < A[smallestChild]) {
            smallestChild = right;
        }
        
        if(smallestChild != index) {
            swap(index, smallestChild);
            index = smallestChild;
        }
        else {
            break;
        }
    }
}

// Swap two elements at index1 and index2 in A
template <class KeyType>
void MinHeap<KeyType>::swap(int index1, int index2) {
    temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;
}

// Copy heap to this heap
template <class KeyType>
void MinHeap<KeyType>::copy(const MinHeap<KeyType>& heap) {
    destroy();

    heapSize = heap.heapSize;
    capacity = heap.capacity;   
    A = new KeyType[capacity];
    for(int i = 0; i < heapSize; i++) {
        A[i] = heap.A[i];
    }
}

// Destructor to deallocate heap
template <class KeyType>
void MinHeap<KeyType>::destroy() {
    delete[] A;
    heapSize = 0;
    capacity = 0;
}

// Assignment operator
template<class KeyType>
MinHeap<KeyType>& MinHeap<KeyType>::operator=(const MinHeap<KeyType>& heap) {
    if(this != &heap) {
        copy(heap);
    }
    return *this;
}

// Use the following toString() for testing purposes.
template <class KeyType>
std::string MinHeap<KeyType>::toString() const
{
	std::stringstream ss;
	
	if (capacity == 0)
		ss << "[ ]";
	else
	{
		ss << "[";
		if (heapSize > 0)
		{
			for (int index = 0; index < heapSize - 1; index++)
				ss << A[index] << ", ";
			ss << A[heapSize - 1];
		}
		ss << " | ";
		if (capacity > heapSize)
		{
			for (int index = heapSize; index < capacity - 1; index++)
				ss << A[index] << ", ";
			ss << A[capacity - 1];
		}
		ss << "]";
	}
	return ss.str();
}

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinHeap<KeyType>& heap)
{
	return stream << heap.toString();
}