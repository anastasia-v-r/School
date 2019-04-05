#include "smallPrint.h"
#include <string>
#include <iostream>

void smallPrint(std::string msg) {
	for (int i = 0; i < (msg.length + 4); ++i) {
		std::cout << "#";
	}
	std::cout << "\n";
	std::cout << "# " << msg << " #\n";
	for (int i = 0; i < (msg.length + 4); ++i) {
		std::cout << "#";
	}
	std::cout << "\n";
}