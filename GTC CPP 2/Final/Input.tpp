#pragma once
#include <iostream>
#include <string>
#include <type_traits>
#include "RandomNumber.tpp"

namespace Custom {
	// Arithmetic Types
	template < typename T,
		std::enable_if_t<
		std::is_arithmetic_v<T> && !std::is_same_v<T, bool>
	> * = nullptr>
	T input(T min, T max) {
		// Adjust min and max based on types
		min = (std::is_signed_v<T>) ? -std::numeric_limits<T>::max() : std::numeric_limits<T>::min();
		max = (std::is_same_v<T, char>) ? '~' : std::numeric_limits<T>::max();

		// Data
		unsigned int trys = 1u;
		T temp;
		
		// Grab input the first time
		std::cout << ">> " << std::flush;
		std::cin >> temp;
		std::cout << std::endl; 

		if (temp > min&& temp < max) {
			return temp;
		} else {
			do {
				if (trys > 5)
					return Custom::randNum<T>(min, max);

				trys++;
				std::cout << "That input was invalid [" << min << "-" << max << "]" << std::endl;
				std::cout << ">> " << std::flush;
				std::cin >> temp;
				std::cout << std::endl;
			} while (temp < min || temp > max);
			return temp;
		}
	}

	// Strings
	template < typename T,
		std::enable_if_t<
		std::is_convertible_v<T, std::string>
	> * = nullptr>
	T input(char string_temrinator = '\n') {
		// Data
		unsigned int trys = 0u;
		std::string temp = "";
		bool correct;
		
		// Get input first try
		std::cout << ">> " << std::flush;
		std::getline(std::cin, temp, string_temrinator);
		std::cout << std::endl;

		// Check said input
		if (temp.empty() || temp[0] == ' ') {
			correct = false;
		} else {
			bool space = false;
			for (const auto& letter : temp) {
				if (!std::isalpha(letter) && !std::isspace(letter)) {
					correct = false;
					break;
				} else if (std::isspace(letter)) {
					if (space) {
						correct = false;
						break;
					} else {
						space = true;
					}
				}
			}
			correct = true;
		}

		if (correct) {
			return temp;
		} else {
			do {
				// Get new input
				trys++;
				std::cout << "That input was invalid [first last]" << std::endl;
				std::cout << ">> " << std::flush;
				std::getline(std::cin, temp, string_temrinator);
				std::cout << std::endl;

				// Check input
				if (temp.empty() || temp[0] == ' ') { // Space too early or empty
					correct = false;
				} else {
					bool space = false;
					for (const auto& letter : temp) {
						if (!std::isalpha(letter) && !std::isspace(letter)) { // only allow letters and space
							correct = false;
							break;
						} else if (std::isspace(letter)) { // if theres a space make sure its the only one
							if (space) { // if more than one space, name is invalid
								correct = false;
								break;
							} else {
								space = true;
							}
						}
					}
					correct = true;
				}
			} while (!correct && trys < 5); // If still incorrect after 5 trys, default to garbage value name
		}

		if (correct) { // If correct, return checked input
			return temp;
		} else { // if no good input was given, generate trash name
			return std::string{
				static_cast<char>(randNum<unsigned int>(static_cast<short>('a'),static_cast<short>('z'))),
				static_cast<char>(randNum<unsigned int>(static_cast<short>('a'),static_cast<short>('z'))),
				static_cast<char>(randNum<unsigned int>(static_cast<short>('a'),static_cast<short>('z'))),
				static_cast<char>(randNum<unsigned int>(static_cast<short>('a'),static_cast<short>('z'))),
				' ',
				static_cast<char>(randNum<unsigned int>(static_cast<short>('a'),static_cast<short>('z'))),
				static_cast<char>(randNum<unsigned int>(static_cast<short>('a'),static_cast<short>('z'))),
				static_cast<char>(randNum<unsigned int>(static_cast<short>('a'),static_cast<short>('z'))),
				static_cast<char>(randNum<unsigned int>(static_cast<short>('a'),static_cast<short>('z'))),
			};
		}
	}

	// Booleans
	template < typename T,
		std::enable_if_t<
		std::is_same_v<T, bool>
	> * = nullptr>
	T input() {
		// Data
		char temp;
		bool correct;
		unsigned int trys = 1u;

		// Get first input
		std::cout << ">> " << std::flush;
		std::cin >> temp;
		std::cout << std::endl;

		if (std::tolower(temp) == 'y' || std::tolower(temp) == 'n') {
			return (temp == 'y') ? true : false;
		} else {
			do {
				trys++;
				// Get input again
				std::cout << ">> " << std::flush;
				std::cin >> temp;
				std::cout << std::endl;

				// Check input
				if (std::tolower(temp) == 'y' || std::tolower(temp) == 'n')
					return (temp == 'y') ? true : false;
			} while (trys < 5);
			return false; // default if input is failed 5 times
		}
	}
}