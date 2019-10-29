#pragma once
#include <assert.h>
#include <string>
#include <iostream>
#include <iomanip>

namespace Screen {
	void Clear();
	void Draw(const std::string& /* buffer */, const std::pair<std::string, std::string>& /* answer */);
#ifdef WIN32
	void Clear() {
		system("cls");
	}
	void Draw(const std::string& buffer, const std::pair<std::string, std::string>& answer) {
		static int width = 46;
		// Top
		std::cout << '+';
		for (int i = 1; i < width; i++) {
			std::cout << '-';
		}
		std::cout << '+' << std::endl;
		// Show state
		std::cout << "| Please name that capital of \"" << std::setw(14) << (std::string)answer.first << "\" |" << std::endl;
		// Split
		std::cout << '|';
		for (int i = 1; i < width; i++) {
			std::cout << '-';
		}
		std::cout << '|' << std::endl;
		// Show Typing
		std::cout << "| Your answer : " << buffer;
		for (int i = 16 + buffer.size(); i < width - 1; i++) {
			std::cout << ' ';
		}
		std::cout << '|' << std::endl;
		// Bottom
		std::cout << '+';
		for (int i = 1; i < width; i++) {
			std::cout << '-';
		}
		std::cout << '+';
	}
#elif UNIX
#endif
}