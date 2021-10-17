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
minimum()      //construct queue from another queue 
Precondition: Must be given a non-empty priority queue
Postcondition: The pointer to the minimum element in the queue
============================================================*/
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::minimum() const
{
	if (this->empty())
	{
		// EmptyError here
	}
	return this->A[0];
}

template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::extractMin()
{
	if (this->heapSize < 1)
	{
		// Empty Error here
	}
	KeyType* minElement = this->A[0];
	this->A[0] = this->A[heapSize-1];
	this->heapSize -= 1;
	this->heapify(0);
	return minElement;

}

template <class KeyType>
void MinPriorityQueue<KeyType>::decreaseKey(int index, KeyType* key)
{
	// cout<<"decrease"<<endl;
	if (*(key) < *(this->A[index]))
	{
		// KeyError here
	}
	this->A[index] = key;
	while (index > 0 && *(this->A[parent(index)]) > *(this->A[index]))
	{
		this->swap(index, parent(index));
		index = parent(index);
	}	
	return;
}

template <class KeyType>
void MinPriorityQueue<KeyType>::insert(KeyType* key)
{
	this->heapSize += 1;
	// cout<<heapSize<<endl;
	int inf = ~(1 << 31);
	int* pointer = &inf;
	this->A[heapSize-1] = pointer;
	this->decreaseKey(heapSize-1, key);
}

template <class KeyType>
bool MinPriorityQueue<KeyType>::empty() const
{
	return (this->heapSize == 0);
}

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