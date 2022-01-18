#include <iostream>
#include "PointersAndReferences.h"

int main()
{
	std::cout << "Pointers" << std::endl;
	HelloPointers();
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "References" << std::endl;
	HelloReferences();

	std::cin.get();
}