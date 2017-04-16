#include "Stack.hpp"

using namespace Dynamic;

template <class T>
Stack<T>::Stack(){
	vrh = nullptr;
	_size = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& s) : Stack(){
	std::cout << "Copy constructor" << std::endl;
	StackNode<T>* sn = s.vrh;
	//std::cout << "vrh value: " << s.vrh->getValue() << std::endl;
	std::cout << "creating array in size: " << s._size-1 << std::endl;
	T *v = new T[s._size-1];
	std::cout << "array created" << std::endl;
	unsigned int i = 0;
	while(sn != nullptr){
		v[i] = sn->getValue();
		i++;
		sn = sn->getNext();
		if (i > 10) break;
	}
	for(unsigned int j=s._size-1; j>0; j--){
		push(v[j]);
	}
	push(v[0]);
	delete[] v;
}

template <class T>
Stack<T>::~Stack(){
	if (size() > 0){
		std::cout << "Emptying the stack with size " << size() << std::endl;
	}
	while (vrh != nullptr){
		pop();
	}
	std::cout << "Stack size: " << size() << std::endl;
	if (size() == 0){
		std::cout << "Stack empty and removed" << std::endl;
	} else {
		std::cout << "Stack didnt empty corectly" << std::endl;
	}
}

template <class T>
void Stack<T>::push(const T value){
	std::cout << "Push object " << value << std::endl;
	vrh = new StackNode<T>(value, vrh);
	std::cout << "New node created " << peek() << std::endl;
	_size++;
}

template <class T>
void Stack<T>::push(T* value){
	vrh = new StackNode<T>(value, vrh);
	
	_size++;
}

template <class T>
void Stack<T>::pop(){
	StackNode<T>* d = vrh;
	vrh = vrh->getNext();
	delete d;
	_size--;
}

template <class T>
T Stack<T>::popr(){
	T e;
	if (vrh == nullptr) return e;
	T r = vrh->getValue();
	StackNode<T>* d = vrh;
	vrh = vrh->getNext();
	delete d;
	_size--;
	return r;
}

template <class T>
T Stack<T>::peek(){
	std::cout << "Peeking" << std::endl;
	T e;
	std::cout << "e made" << std::endl;
	if (vrh == nullptr) return e;
	std::cout << "not null" << std::endl;
	return vrh->getValue();
}

template <class T>
unsigned int Stack<T>::size(){
	return _size;
}

template <class T>
bool Stack<T>::empty(){
	return vrh == nullptr;
}

template <class T>
void Stack<T>::printAll(){
	if (vrh != nullptr)
		vrh->printAll();
}