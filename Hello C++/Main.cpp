#include <iostream>
#include "PointersAndReferences.h"

int main()
{
	std::cout << "POINTERS:" << std::endl;
	HelloPointers();
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "REFERENCES" << std::endl;
	HelloReferences();

	std::cin.get();
}