#ifndef STACK_H
#define STACK_H

#include "StackNode.cpp"

namespace Dynamic{

template <class T>
class Stack{
		StackNode<T> *vrh;
		unsigned int _size;
	public:
		Stack();
		Stack(const Stack<T>& s);
		~Stack();
		void push(const T value);
		void push(T* value);
		void pop();
		T popr();
		T peek();
		unsigned int size();
		bool empty();
		void printAll();
};

}

#endif