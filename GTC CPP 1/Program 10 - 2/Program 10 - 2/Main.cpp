// Includes
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>
// Usings
using str_t = std::string;
// Structs
struct speaker
{
	str_t name;
	str_t phone;
	str_t topic;
	float fee;
};
// Variables
speaker defSpkr = {
	"John Doe",
	"555-555-5555",
	"Talking",
	100
};
char progress;
bool end;
char choice;
// Vector
std::vector<speaker> spkrBureau(10, defSpkr);
//Entry Point
int main() {

	do {
		std::cout << "Please enter which option you'd like to choose,\n";
		std::cout << "(A) -";
		std::cout << "(B) -";
		std::cout << "(c) -";
		std::cout << "(F) -";
		std::cin >> choice;

		switch (choice)
		{
		case('A'):

		case('B'):

		case('C'):

		case('F'):
			end = true;
			break;
		}
		std::cout << "Would you like to progress? [y/n]\n";
		std::cin >> progress;
	} while (progress == 'y' || end == true);

	for (int i = 0; i < spkrBureau.size(); ++i) {
		std::cout << spkrBureau[i].name << spkrBureau[i].phone << spkrBureau[i].topic << spkrBureau[i].fee << "\n";
	}

	for (int count = 5; count > 0; --count) {
		std::cout << "Exiting in " << count;
		Sleep(500);
		std::cout << ".";
		Sleep(500);
		std::cout << ".\n";

	}

}