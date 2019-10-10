#include <iostream>
#include <chrono>
#include "Date.hpp"

int main() {
	try {
		//Date fail(2, 30, 1999); // Intentionally fails program
		int mon = 0, day = 0, yr = 0;
		Date later;
		do {
			std::cout << "This data is for your later date" << std::endl;
			std::cout << "Please enter the month [1-12]" << std::endl;
			std::cin >> mon;
			std::cout << "Please enter the day [1-31]" << std::endl;
			std::cin >> day;
			std::cout << "Please enter the year [1-Inf]" << std::endl;
			std::cin >> yr;
		} while (std::cin.bad() || mon < 0 || day < 0 || yr < 0);
		later = Date(mon, day, yr);
		Date earlier;
		do {
			std::cout << "This data is for your earlier date" << std::endl;
			std::cout << "Please enter the month [1-12]" << std::endl;
			std::cin >> mon;
			std::cout << "Please enter the day [1-31]" << std::endl;
			std::cin >> day;
			std::cout << "Please enter the year [1-Inf]" << std::endl;
			std::cin >> yr;
		} while (std::cin.bad() || mon < 0 || day < 0 || yr < 0);
		earlier = Date(mon, day, yr);
		std::cout << later << std::endl;
		std::cout << ++later << " Prefix ++ " << std::endl;
		std::cout << --later << " Prefix -- " << std::endl;
		Date temp = later++;
		std::cout << temp;
		std::cout << " Postfix ++ " << later << std::endl;
		temp = later--;
		std::cout << temp;
		std::cout << " Postfix -- " << later << std::endl;
		auto funcStart = std::chrono::high_resolution_clock::now();
		std::cout << later << " - " << earlier << " = " << (later - earlier) << " days" << std::endl;
		auto funcEnd = std::chrono::high_resolution_clock::now();
		double elapTime = std::chrono::duration<double, std::milli>(funcEnd - funcStart).count();
		std::cout << "Time elapsed [" << (elapTime / 1000) << "s]" << std::endl;
		std::cout << later.dayMonthFormat() << " dayMonthFormat" << std::endl;
		std::cout << later.monthDayFormat() << " monthDayFormat" << std::endl;
		std::cout << later.numberedFormat() << " numberedFormat" << std::endl;
		std::cout << std::endl;
		std::cin.ignore(2);
	} catch (std::string msg) {
		std::cout << std::endl;
		std::cout << "*************";
		for (const auto& letter : msg) {
			std::cout << '*';
		}
		std::cout << '*' << std::endl;
		std::cerr << "*EXCEPTION : " << msg << '*' << std::endl;
		std::cout << "*************";
		for (const auto& letter : msg) {
			std::cout << '*';
		}
		std::cout << '*' << std::endl;
		std::cout << std::endl;
	}
}
