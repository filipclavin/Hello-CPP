#include <iostream>

// Classes are ways to group data together - they can have variables and functions stored in them. A good example of a class is a player class in a multiplayer game
// In multiplayer games, there are multiple players that share the same types of attributes, just sometimes with different values
// To represent this in code, we can write a 'Player' class, with each player in the game being an 'instance' or 'object' of that class

// Objects inherit all the variables and functions that the class they belong to has, but their values can be changed so each object is unique*
// *unless the variable or function in question is marked as static

// Classes can also inherit from other classes. For instance, our 'Player' class might belong to an 'Entity' class
// Here, the 'Player' class is known as a 'subclass'. 'Player' is the child of 'Entity', and 'Entity' is the parent of 'Player'
// Classes can have multiple children/subclasses - 'Enemies' might be another subclass of 'Entity'

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// How to define a class:
class Player
{
	// Let's declare that all players have a password:
	const char* password; // This is a 'private member' of 'Player', meaning it cannot be accessed outside the scope of the class - this is part of a concept called 'visibility'

	// In classes, variables are private by default - if you don't want them to be private you have to specify that like so:
public:
	int x, y;
	float speed;
	// (in structs, the default visibility is public)

	// Below is a constructor. They run when an object is instanciated from a class, and are useful for setting the object's variables, like so:
	Player(const char* password, int x, int y, float speed, int id)
		: password(password), x(x), y(y), speed(speed), id(id) // This is an 'initializer' list, a fast and compact way to initialize variables with a constructor
	{
	}

	// Modifying an object through a method ('methods' are what functions in classes are called)
	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}

	// There is one more visibility: protected. Protected members are like, private members, except friends of the class can also access them:
protected:
	int id;

}; // <- Note the ';'


void HelloClasses()
{
	// Simple way to instanciate an object from a class with a constructor:
	Player TheLegend27("Password123", 5, 5, 1.5f, 12345);

	std::cout << "Before move: " << std::endl;
	std::cout << "x: " << TheLegend27.x << std::endl;
	std::cout << "y: " << TheLegend27.y << std::endl;

	// Moving 'TheLegend27' by 10 units towards positive x, and 10 units to negative y:
	TheLegend27.Move(10, -10);

	std::cout << "After move: " << std::endl;
	std::cout << "x: " << TheLegend27.x << std::endl;
	std::cout << "y: " << TheLegend27.y << std::endl;

}