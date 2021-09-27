#include <bits/stdc++.h>
#include "Set.h"
#include "Node.h"
#include "Node.cpp"

using namespace std;

template <class T>
Set<T>::Set(){
	this->head = nullptr;
	this->tail = nullptr;
}

template <class T>
Set<T>::~Set(){}

template <class T>
void Set<T>::insert(T data){
	if (this->contains(data)) return;
	Node<T>* newNode = new Node<T>(data);
	if (this->empty()){
		this->head = newNode;
		this->tail = newNode;
	} else {
		Node<T>* curNode = this->head;
		while (curNode->next != nullptr){
			curNode = curNode->next;
		}
		curNode->next = newNode;
		this->tail = newNode;
	}
}

template <class T>
void Set<T>::remove(T data){
	int index = 0;
	Node<T>* curNode = this->head;
	while (curNode != nullptr){
		if (curNode->data == data){
			this->removeAtIndex(index);
			return;
		}
		index++;
		curNode = curNode->next;
	}
}

template <class T>
void Set<T>::removeAtIndex(int index){
	int size = this->cardinality();
	if (index == 0) this->head = this->head->next;
	else if (index == size - 1){
		Node<T>* subLastNode = this->head;
		for (int i = 0; i < size - 2; i++) subLastNode = subLastNode->next;
		subLastNode->next = nullptr;
		this->tail = subLastNode;
	}else{
		Node<T>* prevNode = this->head;
		Node<T>* nextNode = this->head;
		for (int i = 0; i < index - 1; i++) prevNode = prevNode->next;
		for (int i = 0; i < index + 1; i++) nextNode = nextNode->next;
		prevNode->next = nextNode;
	}
}

template <class T>
int Set<T>::cardinality() const {
	int size = 0;
	Node<T>* curNode = this->head;
	while (curNode != nullptr){
		size++;
		curNode = curNode->next;
	}
	return size;
}

template <class T>
bool Set<T>::empty() const {
	return this->head == nullptr && this->tail == nullptr;
}

template <class T>
bool Set<T>::contains(T data) const {
	Node<T>* curNode = this->head;
	while (curNode != nullptr){
		if (curNode->data == data){
			return true;
		}
		curNode = curNode->next;
	}
	return false;
}

template <class T>
string Set<T>::toString() const {
	string setString = "";
	Node<T>* curNode = this->head;
	if (curNode == nullptr) return "{}";
	setString = setString + '{';
	while (curNode->next != nullptr){
		setString = setString + std::to_string(curNode->data) + ", ";
		curNode = curNode->next;
	}
	setString = setString + std::to_string(curNode->data) + '}';
	return setString;
}

template <class T>
bool operator== (const Set<T>& s1, const Set<T>& s2){
	if (s1.cardinality() != s2.cardinality()) return false;
	Node<T>* s1Node = s1.head;
	while (s1Node != nullptr){
		if (!s2.contains(s1Node->data)){
			return false;
		}
		s1Node = s1Node->next;
	}
	return true;
}

template <class T>
bool operator<= (const Set<T>& s1, const Set<T>& s2){
	if (s1.cardinality() > s2.cardinality()) return false;
	Node<T>* s1Node = s1.head;
	while (s1Node != nullptr){
		if (!s2.contains(s1Node->data)){
			return false;
		}
		s1Node = s1Node->next;
	}
	return true;
}

template <class T>
Set<T> operator+ (const Set<T>& s1, const Set<T>& s2){
	Set<T> unionSet = Set<T>();
	Node<T>* s1Node = s1.head;
	Node<T>* s2Node = s2.head;
	while (s1Node != nullptr){
		unionSet.insert(s1Node->data);
		s1Node=s1Node->next;
	}
	while (s2Node != nullptr){
		unionSet.insert(s2Node->data);
		s2Node = s2Node->next;
	}
	return unionSet;
}

template <class T>
Set<T> operator- (const Set<T>& s1, const Set<T>& s2){
	Set<T> diff = Set<T>();
	Node<T>* s1Node = s1.head;
	while (s1Node != nullptr){
		if (!s2.contains(s1Node->data)){
			diff.insert(s1Node->data);
		}
		s1Node = s1Node->next;
	}
	return diff;
}

template <class T>
Set<T> operator& (const Set<T>& s1, const Set<T>& s2){
	Set<T> intersection = Set<T>();
	Node<T>* s1Node = s1.head;
	while (s1Node != nullptr){
		if (s2.contains(s1Node->data)){
			intersection.insert(s1Node->data);
		}
		s1Node = s1Node->next;
	}
	return intersection;
}

template <class T>
ostream& operator<<(ostream& os, const Set<T>& s){
    os << s.toString();
    return os;
}