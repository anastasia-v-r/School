#include <iostream>

int main() {
	char first[512], middle[512], last[512], all[2048]{""};
	
	std::cout << "Please input your first name \n";
	std::cin >> first;
	
	std::cout << "Please input your middle name \n";
	std::cin >> middle;
	
	std::cout << "Please input your last name \n";
	std::cin >> last;
	
	strcat(all, last);
	strcat(all, ", ");
	strcat(all, first);
	strcat(all, " ");
	strcat(all, middle);
	std::cout << all << std::endl;
	system("pause");
	std::cin.ignore(1);
}