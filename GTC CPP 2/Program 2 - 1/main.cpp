#include <iostream>
#include <cstring>

int wordCounter(char*);

int main() {
	char input[2048];
	std::cout << "Please input a string \n";
	gets_s(input);
	int words = wordCounter(input);
	std::cout << "Words: " << words << "\n";
	system("pause");
}

int wordCounter(char* data) {
	int words = 1;
	int i = 0;
	while (data[i]) {
		std::cout << i << " : " << data[i] << "\n";
		if (data[i] == ' ') {
			words += 1;
		}
		++i;
	}
	return words;
}