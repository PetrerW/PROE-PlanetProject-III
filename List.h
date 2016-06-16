#pragma once
#include "Planet.h"
#include "Node.h"
#include <time.h>

template <class T>
class Node;

template <class T>
class List
{
public:
	List();
	List(const List &L);
	~List();
	Node<T>* First;
	Node<T>* Last = NULL;

	void add(Node<T>* Added, int index);
	void deleteNode(int deleted_index);
	void show();
	List<T>& operator=(const List<T>& L);
	Node<T>* operator[](int index) const;
	int getLastNodeIndex();

private:
	int last_node_index = -1;
};

#include "List.cpp"
