#include "StackNode.hpp"	

using namespace Dynamic;

template <class T>
StackNode<T>::StackNode(T* value, StackNode<T>* next){
	std::cout << "New node with pointer" << std::endl;
	this->value = new T(*value);
	this->next = next;
}

template <class T>
StackNode<T>::StackNode(T value, StackNode<T>* next){
	std::cout << "New node with object " << value << std::endl;
	this->value = new T(value);
	this->next = next;
}

template <class T>
StackNode<T>::~StackNode(){
	std::cout << "Node destroyed" << std::endl;
}

template <class T>
StackNode<T>* StackNode<T>::getNext(){
	return next;
}

template <class T>
T StackNode<T>::getValue(){
	std::cout << "returning value" << std::endl;
	T v = *value;
	std::cout << "got value" << std::endl;
	return v;
}

template <class T>
void StackNode<T>::print(){
	//std::cout << "address: " << value << ", value" << *value << std::endl;
}

template <class T>
void StackNode<T>::printAll(){
	print();
	if (next != nullptr)
		next->printAll();
}