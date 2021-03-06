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
MinHeap<KeyType>::MinHeap(int n) {
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
    A = new KeyType[n];
    capacity = n;
    for(int i = 0; i < capacity; i++) {
        A[i] = initA[i];
    }
    buildHeap();
}

/*
Copy constructor
Preconditions: The parameter heap is a correct min heap
Postconditions: Return a new instance of MinHeap which is a copy of the parameter heap
*/
template <class KeyType>
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap) {
    // Set A = nullptr so that copy method doesn't delete[] A
    A = nullptr;
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

/* 
Perform heapsort, return result in the sorted array
Preconditions: This heap is a correct min heap.
Postconditions: The array sorted is sorted
*/

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

/* 
Heapify subheap rooted at index
Preconditions: Two subtrees at root index are correct min heaps
Post conditions: The tree at root index is a correct min heap.
*/
template<class KeyType>
void MinHeap<KeyType>::heapify(int index) {
    heapifyR(index);
}

/*
Build heap from the array A
Preconditions: None
Postconditions: This heap is a correct min heap.
*/
template <class KeyType> 
void MinHeap<KeyType>::buildHeap() {
    heapSize = capacity;
    // Iterate from the node (capacity / 2) - 1 to 0, which is iterating in bottom-up method, and call heapify in each iteration
    for(int i = (capacity / 2) - 1; i >= 0; i--) {
        heapify(i);
    }
}

/* 
Heapify subheap rooted at index using recursive method
Preconditions: Two subtrees at root index are correct min heaps
Post conditions: The tree at root index is a correct min heap.
*/
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
        heapifyR(smallestChild);
    }
}

/*
Heapify subheap rooted at index using iterative method
Preconditions: Two subtrees at root index are correct min heaps
Post conditions: The tree at root index is a correct min heap.
*/
template<class KeyType>
void MinHeap<KeyType>::heapifyI(int index) {
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

/*
Swap two elements at index1 and index2 in A
Preconditions: index1 and index2 are valid element in the array A
Postconditions: two elements at index1 and index2 are swapped
*/
template <class KeyType>
void MinHeap<KeyType>::swap(int index1, int index2) {
    KeyType temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;
}

/* 
Copy the parameter heap to this heap
Preconditions: The parameter heap is a correct min heap
Postconditions: This heap becomes a copy of the parameter heap
*/
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

/* 
Destroy is a function to deallocate this heap.
Preconditions: None.
Postconditions: The array A of this heap is removed from memory and instance variables heapSize and capacity are set to 0.
*/
template <class KeyType>
void MinHeap<KeyType>::destroy() {
    if(A != nullptr) {
        delete[] A;
    }
    heapSize = 0;
    capacity = 0;
}

/* 
Assignment operator.
Preconditions: The parameter heap is a correct min heap.
Postconditions: if this heap and the parameter heap is not the same (having the same address), this heap becomes a copy of the parameter heap
*/
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