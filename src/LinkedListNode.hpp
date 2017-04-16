#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <iostream>

template <class T>
class LinkedListNode{
		T* value;
	public:
		LinkedListNode<T>* prev;
		LinkedListNode<T>* next;
		
		LinkedListNode(LinkedListNode<T>*, LinkedListNode<T>*, T* );
		LinkedListNode(LinkedListNode<T>*, LinkedListNode<T>*, T);
		~LinkedListNode();
		T getValue();
};

#endif