#pragma once
#include "List.h" 
#include "Planet.h"

template <class T> 
class List;

template <class T>
class Node
{
public:
	Node();
	Node(T* P);
	Node(const Node& N);
	~Node();

	T* Object;
	Node<T>* Next;

	double getTime();
	void changeTime(double t);
	int getIndex();
	void changeIndex(int i);
	Node<T>& operator=(const Node<T>& N);
private:
	double cr_time = 0; //creation time
	int index = 0;
};

#include "Node.cpp"



template <class T>
Node<T>::Node() {
    Next = nullptr;
    Object = NULL;
}

template <class T>
Node<T>::Node(T* P)
{
    Next = nullptr;
    Object = P;
}

template <class T>
Node<T>::Node(const Node& N) {
    //this->Next = new Node(N);
    this->Next = nullptr;
    *(this->Object) = *(N.Object);
    this->cr_time = N.cr_time;
}

template <class T>
Node<T>::	~Node() {
}

template <class T>
double Node<T>::getTime() { return  cr_time; }
template <class T>
void Node<T>::changeTime(double t) { cr_time = t; }
template <class T>
int Node<T>::getIndex() { return index; }
template <class T>
void Node<T>::changeIndex(int i) { index = i; }

template<class T>
Node<T>& Node<T>::operator=(const Node<T> & N)
{
    *(this->Object) = *(N.Object);
    this->Next = nullptr;
    return *this;
}
