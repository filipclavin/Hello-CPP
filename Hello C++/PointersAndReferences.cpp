#include <iostream>
#include "PointersAndReferences.h"

// All variables and the like have memory addresses
// Pointers are intergers that represent those memory addresses
// Pointer variables have their own memory addresses
// Pointers are declared by putting a '*' after the type

// The type of a pointer variable does not actually matter as far as the pointer is concerned
// It only indicates to the compiler and the developer the type of the data that is stored in the memory address

void HelloPointers()
{
	// Simplest possible valid pointer:
	void* ptr = nullptr; // Here, void means we do not care what type of data the pointer is pointing to, nullptr evaluates to 0x0000000000000000
	std::cout << "ptr: " << ptr << std::endl;

	// 0 is not a valid memory address:
	void* invalid_ptr = 0; // <- Ff we try to access this "memory address", the program WILL crash

	// How to store a memory address of a variable into a pointer:
	int num = 8;
	int* num_ptr = &num; // Here, '&' gets the memory address of num, and we store it into num_ptr
	std::cout << "num_ptr: " << num_ptr << std::endl;

	// Despite types not mattering to a pointer, for the purposes of the compiler knowing how to handle the data at that address,
	// the compiler WILL throw an error if you mismatch a type like so:
	// double* bad_num_ptr = &num
	// However, we can cast the reference the pointer is pointing to to the correct type, like so:
	double* casted_num_ptr = (double*)&num;
	std::cout << "casted_num_ptr: " << casted_num_ptr << std::endl;

	// Pointers pointing to other pointers (called double pointers / triple pointers / etc.) are declared by putting 2 stars ('*') after the type.
	// The type of the pointer variable should be the same as the type of the variable at the end of the pointer chain:
	// char** double_ptr = &ptr; <- This is bad
	void** double_ptr = &ptr; // <- This is good
	std::cout << "double_ptr: " << double_ptr << std::endl;
	std::cout << "Dereferenced double_ptr: " << *double_ptr << std::endl;

	// Above, we 'dereferenced' the double pointer
	// In order to access something stored in a memory address, we dereference a pointer by putting a '*' in front of it, like so:
	std::cout << "Dereferenced num_ptr: " << *num_ptr << std::endl;

	(*num_ptr)++; // This increments the variable that the pointer is pointing at (num)
	// Because of order of operations, we needed to enclose *num_ptr in '()' in order to increment the variable it's pointing at

	std::cout << "Changed dereferenced num_ptr: " << *num_ptr << std::endl;
	// This is essentially the same as using the variable name of the variable that the pointer is pointing to

	// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	// Pointers are useful for allocating memory on the heap, rather than the stack.
	// The heap can allocate more memory than the stack
	// Memory allocated to a variable on the heap does not get freed once the program exits the scope that the variable was declared in (unlike on the stack)
	// We can ask the heap to allocate a specific amount of memory to a variable
	char* buffer = new char[8]; // A char is ordinarily only 1 byte, but here we asked the heap to allocate 8 bytes of memory to it. This returns a pointer to that block of memory

	// The memset function fills a block of memory with data that we specify. As parameters, it takes:
	memset(
		buffer, // a pointer to the beginning of the block of memory,
		'A',	// a value (what to put inside the memory block),
		8		// and a size (how many bytes of memory it should fill)
	);
	std::cout << "Heap-allocated char: " << *buffer << std::endl;

	// We then need to free those bytes of memory manually since it was allocated on the heap
	// delete needs to know the address of the memory to be freed
	// delete also needs '[]' to be put after it if we specified an amount of data to allocate when we declared the variable (like we did above)
	delete[] buffer;

}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// References are technically more or less the same thing, as far as what the computer will do with them
// However, semantically, there are some differences:
// References are made to be easier to read and follow than pointers, and there are some cool things we can do with references to avoid copying and wasting memory

// A reference is a way to 'reference' another variable. You can for instance create aliases, which is another way to access the same variable, stored in the same memory address
// Unlike pointers, references have to reference existing variables. This is because, unlike pointers, references are not their own variables.
// There is nothing you can do with a reference that you cannot do with a pointer (in fact pointers are great and can do even more things than references)
// However, references are much easier to use and read, so use them when you can.


// *Passing by Value VS Passing by Reference*
// Here's an example of why references are important and save memory:
// This first function takes an int as an argument, and puts it into a variable called x, which is scoped to IncrementByValue
// This function doesn't do anything, because it doesn't actually change the variable that we put in as an argument, it changes the temporary variable 'x'
void IncrementByValue(int x) { x++; } // Passing by value

// If we wanted to change the value of the variable that we pass in as an argument, we would need to do something like this:
// 
// int IncrementByValue(int x) { return x++; }
// int increment_me = 5;
// increment_me = IncrementByValue(increment_me)
// 
// This is bad and inefficient, not just because it looks horrendus, but also because it's slow;
// It needs to copy the value of 'increment_me', put it in a new variable 'x', return that variable and set 'increment_me' to it, and finally delete 'x'

// If we wanted to increment the actual variable that we put in as the argument, we should write the function like this:
void IncrementByReference(int& x) { x++; } // Passing by reference

// Instead of creating a new variable and setting it to the value of what we put in, it creates a reference to the variable, meaning no copying on the machine level

void HelloReferences()
{
	// Creating a reference:
	int a = 5;
	int& ref = a; // Here, we put the '&' after the type in order to tell the compiler that this is a reference - not its own varaible

	// Now, using 'ref', we can access 'a':
	std::cout << "ref: " << ref << " = " << 'a: ' << a << std::endl;
	// Note that the memory address of 'ref' is the same as that of 'a', since 'ref' actually means 'a';
	std::cout << "ref address: " << &ref << " = " << "a address :" << &a << std::endl;
	// And if we change the value of 'ref', we also change the value of 'a':
	ref = 2;
	std::cout << "ref: " << ref << " = " << 'a: ' << a << std::endl;

	// Below is a demonstration of passing by value vs passing by reference, explained and defined in lines 85 - 103:
	int increment_me = 1;
	IncrementByValue(increment_me);
	std::cout << increment_me << std::endl;
	IncrementByReference(increment_me);
	std::cout << increment_me << std::endl;

	// Important thing to note: You cannot change which variable a reference is referencing. It will simply change the value of the original variable to that of the new value

}