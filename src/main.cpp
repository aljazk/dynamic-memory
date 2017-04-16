#include <iostream>

#include "LinkedList.cpp"

int main(){
	LinkedList<int> l;
	l.add(0);
	l.add(1);
	l.add(2);
	l.printAll();
	std::cout << l.remove(1) << std::endl;
	return 0;
}
