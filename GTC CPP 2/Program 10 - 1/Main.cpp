#include <iostream> // cout, cin
#include <iomanip> // setw
#include <string> // string, getline
#include <thread> // this_thread::sleep_for
#include <chrono> // milliseconds
#include "Stack.hpp" // Stack<T>

void checkInput(std::string, Stack<std::string>&, Stack<int>&);

int main() {
	Stack<int> parenStack; // Parenthesis tracking
	Stack<std::string> messages; // Store error messages
	std::string input; // Hold user input

	std::cout << "+=============================================================================+\n"
			  << "| Please enter a string containing parenthesis, afterwards the string will be |\n"
			  << "| processed and you will be told if your parenthesis usage was balanced       |\n" 
			  << "+=============================================================================+\n" <<std::endl;

	std::cout << ">> ";
	std::getline(std::cin, input, '\n');
	try {
		checkInput(input, messages, parenStack); // Process user input
	} catch (std::exception msg) {
		std::cout << '+';
		for (int i = 0; i < ((std::string)msg.what()).size() + 2; i++) {
			std::cout << '=';
		}
		std::cout << '+' << std::endl;
		std::cout << "| " << msg.what() << " |" << std::endl;
		std::cout << '+';
		for (int i = 0; i < ((std::string)msg.what()).size() + 2; i++) {
			std::cout << '=';
		}
		std::cout << '+' << std::endl;
		return 0;
	}
	std::cout << std::endl;

	try {
		while (!messages.empty()) { // Process error messages
			std::cout << '+';
			static unsigned int messageSize = 45;
			for (int i = 0; i < messageSize + 2; i++) {
				std::cout << '=';
			}
			std::cout << '+' << std::endl;
			std::cout << "| " << std::setw(messageSize) << messages.top() << " |" << std::endl;
			if (messages.size() == 1) {
				std::cout << '+';
				for (int i = 0; i < messageSize + 2; i++) {
					std::cout << '=';
				}
				std::cout << '+';
			}
			messages.pop();
		}
		std::cout << std::endl;
	} catch (std::exception msg) {
		std::cout << '+';
		for (int i = 0; i < ((std::string)msg.what()).size() + 2; i++) {
			std::cout << '=';
		}
		std::cout << '+' << std::endl;
		std::cout << "| " << msg.what() << " |" << std::endl;
		std::cout << '+';
		for (int i = 0; i < ((std::string)msg.what()).size() + 2; i++) {
			std::cout << '=';
		}
		std::cout << '+' << std::endl;
		return 0;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(5 * 1000)); // Don't quit before user can take in information
}

void checkInput(std::string input, Stack<std::string>& messages, Stack<int>& parenStack) {
	if (input.find('(') == std::string::npos && input.find(')') == std::string::npos) {
		messages.push("There are no parenthesis in this string");
		return;
	}
	for (const auto& letter : input) {
		if (letter == '(') {
			parenStack.push(0);
		}
		else if (letter == ')') {
			if (!parenStack.empty()) {
				parenStack.pop();
			}
			else {
				messages.push("Your string had a ')' without a '(' before it");
			}
		}
	}
	if (!parenStack.empty()) {
		messages.push("Your string had " + std::to_string(parenStack.size()) + " unclosed '('");
	}
	if (messages.empty()) {
		messages.push("Your string was perfectly balanced!");
	}
}
/*
Due date: November 13.
Programming Challenge.
Chapter 19.
Prob14. Balance Parenthesis.
Be creative with the interphase.
Implement exceptions.
Use your own data structures. (Not built in, for this project)

Balanced Parentheses
A string of characters has balanced parentheses if each right parenthesis
occurring in the string is matched with a preceding left parenthesis, in 
the same way that each right brace in a C++ program is matched with a 
preceding left brace. Write a program that uses a stack to determine 
whether a string entered at the keyboard has balanced parentheses.
*/