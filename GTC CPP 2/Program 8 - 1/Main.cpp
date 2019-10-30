#include "MapData.hpp"6
#include <ctime> // time
#include <iostream> // cout and cin
#include <iterator> // std::next
#include <iomanip> // setw
#include <thread> // Sleep
#include <chrono> // milliseconds

std::pair<std::string, std::string> newQuestion();

int main() {
	std::srand(std::time(nullptr));
	std::string answerBuffer;
	std::pair<std::string, std::string> correct = newQuestion();
	int totalQuestions = 0;
	int score = 0;
	int size;
	char input;
	bool goOn = false;
	do {
		system("cls");
		do {
			std::cout << "How long many questions would you like to answer?" << std::endl;
			std::cin >> input;
		} while (!std::isdigit(input) || input - '0' > '99');
		size = input - '0';
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (true) {
			system("cls");
			int max = (correct.first.size() > correct.second.size()) ? correct.first.size() : correct.second.size();
			std::cout << '+';
			for (int i = 0; i < max + 28; i++) {
				std::cout << '-';
			}
			std::cout << '+' << std::endl;
			std::cout << "|" << std::setw(-max) << correct.first << " capital is :  | Score : " << std::setw(2) << score << "/" << std::setw(2) << totalQuestions << '|' << std::endl;
			std::cout << '+';
			for (int i = 0; i < max + 28; i++) {
				std::cout << '-';
			}
			std::cout << '+' << std::endl << std::endl;
			std::getline(std::cin, answerBuffer, '\n');
			std::cout << std::endl << "[" << answerBuffer << "]" << std::endl;
			if (answerBuffer.find("[") != std::string::npos) {
				std::cout << "REEEEEE";
				return 0;
			}
			else if (answerBuffer.find(correct.second) != std::string::npos) {
				std::cout << "Correct!" << std::endl;
				score++;
			}
			else {
				std::cout << "Wrong!" << std::endl;
			}
			answerBuffer.clear();
			totalQuestions++;
			correct = newQuestion();
			if (totalQuestions == size)
				break;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		system("cls");
		std::cout << "Your score is " << std::setw(2) << score << "/" << std::setw(2) << totalQuestions << std::endl;
		std::cout << "Would you like to go again? [y/n]" << std::endl;
		char yuh;
		std::cin.get(yuh);
		yuh = std::tolower(yuh);
		goOn = (yuh == 'y') ? true : false;
	} while (goOn);
}

std::pair<std::string, std::string> newQuestion() {
	int choice = std::rand() % User::statesMap.size();
	return *std::next(User::statesMap.begin(), choice);
}
