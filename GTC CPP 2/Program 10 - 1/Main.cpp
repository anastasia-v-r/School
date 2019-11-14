#include <iostream>
#include <stack>
#include <string>

int main() {
	std::stack<int> parenStack;
	std::string input;
	std::cout << "Please enter a string containing parenthesis, afterwards the string will be processed and you will be told if your parenthesis usage was balanced" << std::endl;
	std::getline(std::cin, input, '\n');
	if (input.find('(') == std::string::npos && input.find(')') == std::string::npos) {
		std::cout << "There are no parenthesis in this string" << std::endl;
		return;
	}
	for (const auto& letter : input) {
		if (letter == '(') {
			parenStack.push(0);
		} else if (letter == ')') {
			if (!parenStack.empty()) {
				parenStack.pop();
			} else {
				parenStack.push(100);
				break;
			}
		}
	}
	if (!parenStack.empty()) {
		if (parenStack.top() == 100) {
			std::cout << "Your string had a ')' without a '(' before it" << std::endl;
		} else {
			std::cout << "Your string had one or more unclosed ('s" << std::endl;
		}
	} else {
		std::cout << "Your string was perfectly balanced!" << std::endl;
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