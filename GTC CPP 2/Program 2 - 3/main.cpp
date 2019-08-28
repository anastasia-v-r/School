#include <iostream>

int main() {
	char digits[2048];
	int i = 0, total = 0, highest, lowest;

	std::cout << "Please enter a series of digits \n";
	std::cin >> digits;
	
	highest = digits[0] - '0';
	lowest = digits[0] - '0';

	while (digits[i]) {
		if (lowest > (digits[i] - '0')) {
			lowest = digits[i] - '0';
		}
		if (highest < (digits[i] - '0')) {
			highest = digits[i] - '0';
		}
		total += digits[i] - '0';
		i++;
	}

	std::cout << "|Total : " << total << " | Highest : " << highest << " | Lowest : " << lowest <<"|\n";
	std::cin.ignore(10);
}