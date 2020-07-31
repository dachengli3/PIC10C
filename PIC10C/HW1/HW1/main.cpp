#include "Header.h"
#include <string>
#include <ostream>
#include <iostream>

int main()
{
	//check default constructor
	BinarySearchTree mybst;

	//Creating BST w data
	mybst.insert("Hi");
	mybst.insert("Hello");
	mybst.insert("Hey");
	mybst.insert("Hola");

	//check copy constructor
	BinarySearchTree mybst2(mybst);

	//check assign operator
	mybst = mybst2;

	//test for printability and functionality
	mybst.print();
	std::cout << std::endl;
	mybst2.print();
	std::cout << std::endl;
	mybst2.printRev();
	std::cout << std::endl;
	std::cout << mybst2.findText("Cat");
	return 0;
}