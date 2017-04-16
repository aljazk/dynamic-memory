#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListNode.cpp"

template <class T>
class LinkedList{
		LinkedListNode<T>* start;
		unsigned int _size;
		void getNeighbors(LinkedListNode<T>*&, LinkedListNode<T>*&, unsigned int);
		void find(LinkedListNode<T>*&, unsigned int);
	public:
		LinkedList();
		~LinkedList();
		unsigned int size();
		//adds value at the inedex
		void add(unsigned int, T);
		//adds value at the end
		void add(T);
		T remove(unsigned int);
		void clean();
		bool empty();
		void printAll();
		
};

#endif