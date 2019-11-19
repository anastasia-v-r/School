#include <iostream>
#include <string>

bool hasLetter(const std::string& /* string */, const char& /* letter */);

int main() {
	std::string test;
	char letter;
	std::cout << "Please enter a string to test" << std::endl;
	std::cout << ">> " << std::flush;
	std::getline(std::cin, test);
	std::cout << "Please enter a single character for the string to be checked for" << std::endl;
	std::cout << ">> " << std::flush;
	std::cin >> letter;
	std::cout << "String [" << test << (hasLetter(test, letter) ? "] contains ['" : "] does not contain ['") << (char)std::toupper(letter) << "'/'" << (char)std::tolower(letter) << "']" << std::endl;
}

bool hasLetter(const std::string& string, const char& letter) {
	static unsigned int position = 0;
	if (std::tolower(string[position]) == std::tolower(letter)) {
		return true;
	} else {
		if (position < string.size() - 1) {
			position++;
			return hasLetter(string, letter);
		} else {
			return false;
		}
	}
}
