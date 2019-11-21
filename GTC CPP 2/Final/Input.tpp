#pragma once
#include <iostream>
#include <string>
#include <type_traits>
#include "RandomNumber.tpp"

namespace Custom {
	// Arithmetic Types
	template < typename T,
		std::enable_if_t<
		std::is_arithmetic_v<T>
	> * = nullptr>
		T input(T min, T max) {
		min = (std::is_signed_v<T>) ? -std::numeric_limits<T>::max() : std::numeric_limits<T>::min();
		max = (std::is_same_v<T, char>) ? '~' : std::numeric_limits<T>::max();
		unsigned int trys = 1u;
		T temp;
		std::cout << ">> " << std::flush;
		std::cin >> temp;
		std::cout << std::endl;
		if (temp > min&& temp < max) {
			return temp;
		}
		else {
			do {
				if (trys > 5) {
					return Custom::randNum<T>(min, max);
				}
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
		unsigned int trys = 1u;
		std::string temp;
		std::cout << ">> " << std::flush;
		std::getline(std::cin, temp);
		std::cout << std::endl;
		bool correct;
		do {
			trys++;
			correct = ([]() -> bool {
				if (temp[0] == ' ') {
					return false;
				}
				bool space = false;
				for (const auto& letter : temp) {
					if (!std::isalpha(letter) && !std::isspace(letter)) {
						return false;
					} else if (std::isspace(letter)) {
						if (space) {
							return false;
						}
						else {
							space = true;
						}
					}
				}
				return true;
			})();
			std::cout << ">> " << std::flush;
			std::getline(std::cin, temp);
			std::cout << std::endl;
		} while (!correct && trys < 5);
		if (correct) {
			return temp
		} else {
			return std::string{
				randNum<char>('a','z'),
				randNum<char>('a','z'),
				randNum<char>('a','z'),
				randNum<char>('a','z'),
				randNum<char>('a','z'),
				randNum<char>('a','z'),
				randNum<char>('a','z'),
				randNum<char>('a','z'),
			};
		}
	}
}