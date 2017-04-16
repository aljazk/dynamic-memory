#include "LinkedListNode.hpp"
	
template <class T>	
LinkedListNode<T>::LinkedListNode(LinkedListNode<T>* prev, LinkedListNode<T>* next, T* value){
	this->prev = prev;
	this->next = next;
	this->value = new T(*value);
}

template <class T>
LinkedListNode<T>::LinkedListNode(LinkedListNode<T>* prev, LinkedListNode<T>* next, T value){
	this->prev = prev;
	this->next = next;
	this->value = new T(value);
}

template <class T>
LinkedListNode<T>::~LinkedListNode(){
	delete value;
}

template <class T>
T LinkedListNode<T>::getValue(){
	return *value;
}