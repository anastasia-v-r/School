#include <iostream>
#include "LinkList.hpp"

int main() {
	LinkedList list;
	std::cout << "Populating list with 5 strings" << std::endl;
	for (int i = 1; i <= 5; i++) {
		std::cout << std::to_string(i) + "..." << std::endl;
		std::string str;
		for (int j = 0; j < i; j++) {
			str += j + '0';
		}
		list.appendNode(str);
	}
	std::cout << std::endl;
	list.displayList();
	std::cout << std::endl;
	
	// Append test
	std::cout << "+------------------------------+" << std::endl;
	std::cout << "| Appending a user made string |" << std::endl;
	std::cout << "+------------------------------+" << std::endl;
	std::string input;
	std::cout << ">> ";
	std::getline(std::cin, input, '\n');
	try {
		list.appendNode(input);
	} catch (const std::exception& msg) {
		std::cout << "ERROR" << std::endl;
		std::cout << msg.what() << std::endl;
		std::cout << "ERROR" << std::endl;
	}
	std::cout << std::endl;
	list.displayList();
	std::cout << std::endl;

	// Insert Test
	std::cout << "+------------------------------+" << std::endl;
	std::cout << "| Inserting a user made string |" << std::endl;
	std::cout << "+------------------------------+" << std::endl;
	input.clear();
	std::cout << ">> ";
	std::getline(std::cin, input, '\n');
	try {
		list.insertNode(input);
	} catch (const std::exception& msg) {
		std::cout << "ERROR" << std::endl;
		std::cout << msg.what() << std::endl;
		std::cout << "ERROR" << std::endl;
	}
	std::cout << std::endl;
	list.displayList();
	std::cout << std::endl;

	// Deletion test
	std::cout << "+-------------------------------+" << std::endl;
	std::cout << "| Deleting a user chosen string |" << std::endl;
	std::cout << "+-------------------------------+" << std::endl;
	input.clear();
	std::cout << ">> ";
	std::getline(std::cin, input, '\n');
	try {
		list.deleteNode(input);
	} catch (const std::exception& msg) {
		std::cout << "ERROR" << std::endl;
		std::cout << msg.what() << std::endl;
		std::cout << "ERROR" << std::endl;
	}
	std::cout << std::endl;
	list.displayList();
	std::cout << std::endl;
	std::cin.ignore(10);
}

/*
Due date: November 6 by 6:00 PM.

Chapter 18.

Programming Challenge.

1. Your own Linked List.

With the following modifications. Store strings instead of integers.

Implement exceptions.

Make your program robust.

Be creative with the user interface.

*/