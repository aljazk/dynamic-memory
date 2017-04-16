#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

namespace Dynamic{

template <class T>
class StackNode{
		StackNode<T> *next;
		T *value;
	public:
		StackNode(T* value, StackNode<T>* next);
		StackNode(T value, StackNode<T>* next);
		~StackNode();
		StackNode* getNext();
		T getValue();
		void print();
		void printAll();
};

}

#endif