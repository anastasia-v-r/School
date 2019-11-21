#include "Funcs.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include "RandomNumber.tpp"


namespace Custom {
	unsigned short getFreshId(const std::set<unsigned short>& knownIds) {
		auto id = randNum<unsigned short>();
		return (knownIds.count(id)) ? getFreshId(knownIds) : id;
	}

	unsigned short getFreshId(const std::map<unsigned short, std::string>& knownIds) {
		auto id = randNum<unsigned short>();
		return (knownIds.count(id)) ? getFreshId(knownIds) : id;
	}

	std::string output(std::string message) {
		std::stringstream temp;
		for (int i = 0; i < message.length() + 4; i++) {
			temp << "=";
		}
		temp << std::endl;
		temp << "= " << message << " =" << std::endl;
		for (int i = 0; i < message.length() + 4; i++) {
			temp << "=";
		}
		temp << std::endl << std::endl;
		std::cout << temp.str();
		return temp.str();
	}
}