// pq.cpp
using namespace std;
// These 3 constructors just call the corresponding MinHeap constructors.  That's all.
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue() : MinHeap<KeyType>()
{ }

/*==========================================================
MinPriorityQueue(int n)      //default constructor
Precondition: Must be given a capacity size (n)
Postcondition: An empty queue with capacity of n
============================================================*/
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(int n) : MinHeap<KeyType>(n)
{ }

/*==========================================================
MinPriorityQueue(const MinPriorityQueue<KeyType>& pq)      //construct queue from another queue 
Precondition: Must be given a priority queue
Postcondition: A queue deep copied from the given queue
============================================================*/
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(const MinPriorityQueue<KeyType>& pq) : MinHeap<KeyType>(pq)
{ }

/*==========================================================
minimum()      //Return the pointer to minimium value of the heap
Precondition: Must be given a non-empty priority queue
Postcondition: The pointer to the minimum element in the queue
============================================================*/
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::minimum() const
{
	if (this->empty())
	{
		throw EmptyError();
	}
	return this->A[0];
}

/*==========================================================
extractMin()      //Return the minimium value of the heap
Precondition: Must be given a non-empty priority queue
Postcondition: The minimum element in the queue
============================================================*/
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::extractMin()
{
	if (this->heapSize < 1)
	{
		throw EmptyError();
	}
	KeyType* minElement = this->A[0];
	this->A[0] = this->A[heapSize-1];
	this->heapSize -= 1;
	this->heapify(0);
	return minElement;
}

/*==========================================================
decreaseKey()      //Decrease value of the given index and maintain the heap
Precondition: The private array A must be a heap. The value at the given index of the heap must be larger or equal to the given key
Postcondition: The maintained heap with the new replaced key
============================================================*/
template <class KeyType>
void MinPriorityQueue<KeyType>::decreaseKey(int index, KeyType* key)
{
	if (*(key) < *(this->A[index]))
	{
		throw KeyError();
	}
	this->A[index] = key;
	while (index > 0 && *(this->A[parent(index)]) > *(this->A[index]))
	{
		this->swap(index, parent(index));
		index = parent(index);
	}	
	return;
}

/*==========================================================
insert()      //insert a new key into the heap
Precondition: The private array A must be a heap
Postcondition: The maintained heap with the new inserted key
============================================================*/
template <class KeyType>
void MinPriorityQueue<KeyType>::insert(KeyType* key)
{
	this->heapSize += 1;
	int inf = ~(1 << 31);
	KeyType* temp = new KeyType(inf);
	this->A[heapSize-1] = temp;
	this->decreaseKey(heapSize-1, key);
}

/*==========================================================
empty()      //Return true if the heap is empty
Precondition: 
Postcondition: Return true if the heap is empty and false if the heap is not empty
============================================================*/
template <class KeyType>
bool MinPriorityQueue<KeyType>::empty() const
{
	return (this->heapSize == 0);
}

/*==========================================================
length()      //Return size of the heap
Precondition: 
Postcondition: Return size of the heap
============================================================*/
template <class KeyType>
int MinPriorityQueue<KeyType>::length() const
{
	return this->heapSize;
}


template <class KeyType>
std::string MinPriorityQueue<KeyType>::toString() const
{
	std::stringstream ss;

	if (heapSize == 0)
	{
		ss << "[ ]";
	}
	else
	{
		ss << "[";
		for (int index = 0; index < heapSize - 1; index++)
			ss << *(A[index]) << ", ";
		ss << *(A[heapSize - 1]) << "]";
	}
	return ss.str();
}

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinPriorityQueue<KeyType>& pq)
{
	stream << pq.toString();

	return stream;
}
