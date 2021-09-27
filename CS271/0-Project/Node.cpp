#include <bits/stdc++.h>
#include "Node.h"

using namespace std;

template <class T>
Node<T>::Node(T data){
	this -> data = data;
}

template <class T>
Node<T>::~Node(){
	cout << "Node deconstructed";
}