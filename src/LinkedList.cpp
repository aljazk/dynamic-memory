#include "LinkedList.hpp"


template <class T>
LinkedList<T>::LinkedList(){
	start = nullptr;
	_size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
	clean();
}

template <class T>
void LinkedList<T>::getNeighbors(LinkedListNode<T>*& prev, LinkedListNode<T>*& next, unsigned int index){
	find(prev, index);
	if (prev != nullptr){
		next = prev->next;
	} else {
		next = nullptr;
	}
}

template <class T>
void LinkedList<T>::find(LinkedListNode<T>*& n, unsigned int index){
	n = start;
	if (!empty()){
		for(unsigned int i=0; i<index; i++){
			if (n->next != nullptr){
				n = n->next;
			} else {
				break;
			}
		}
	}
}

template <class T>
unsigned int LinkedList<T>::size(){
	return _size;
}

//adds value at the inedex
template <class T>
void LinkedList<T>::add(unsigned int index, T value){
	std::cout << "add ";
	if (empty()){
		std::cout << "empty" << std::endl;
		start = new LinkedListNode<T>(nullptr, nullptr, value);
	} else if(index == 0){
		std::cout << "index 0" << std::endl;
		start = new LinkedListNode<T>(nullptr, start, value);
		start->next->prev = start;
	} else {
		std::cout << "normal" << std::endl;
		LinkedListNode<T> *prev = nullptr;
		LinkedListNode<T> *next = nullptr;
		getNeighbors(prev, next, index);
		LinkedListNode<T>* curr = new LinkedListNode<T>(prev, next, value);
		if (prev != nullptr){
			prev->next = curr;
		}
		if (next != nullptr){
			next->prev = curr;
		}
	}
	_size++;
}

template <class T>
//adds value at the end
void LinkedList<T>::add(T value){
	add(_size, value);
}

template <class T>
T LinkedList<T>::remove(unsigned int index){
	LinkedListNode<T>* n = nullptr;
	find(n, index);
	if(n != nullptr){
		std::cout << "Remove: " << n->getValue() << std::endl;
		LinkedListNode<T>* prev = n->prev;
		LinkedListNode<T>* next = n->next;
		if(prev != nullptr){
			prev->next = next;
		} else {
			start = next;
		}
		if(next != nullptr){
			next->prev = prev;
		}
		T value = n->getValue();
		delete n;
		_size--;
		return value;
	}
	return *(new T());
}

template <class T>
void LinkedList<T>::clean(){
	while(!empty()){
		remove(0);
	}
	std::cout << "Size after cleaning: " << size() << std::endl;
}

template <class T>
bool LinkedList<T>::empty(){
	return start == nullptr;
}

template <class T>
void LinkedList<T>::printAll(){
	std::cout << "Printing" << std::endl;
	if (!empty()){
		LinkedListNode<T>* n = start;
		while(n != nullptr){
			std::cout << n->getValue() << std::endl;
			n = n->next;
		}
	}
}

		