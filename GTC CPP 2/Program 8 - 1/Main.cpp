#include "MapData.hpp"
#include "Rendering.hpp"
#include <vector>
#include <conio.h>
#include <ctime>
#include <iterator>
#include <thread>
#include <mutex>
#include <atomic>

bool checkAnswer(const std::string&, const std::string&);
std::pair<std::string, std::string> newQuestion();

int main() {
	std::srand(std::time(nullptr));
	std::string answerBuffer;
	std::pair<std::string, std::string> correct = newQuestion();
	int totalQuestions = 0;
	int score = 0;
	static std::mutex mu;
	std::atomic<bool> isRunning = true;
	std::thread RenderThread([&isRunning, &correct, &answerBuffer] {
		while (isRunning) {
			mu.lock();
			Screen::Clear();
			Screen::Draw(answerBuffer, correct);
			mu.unlock();
		}
	});
	while (isRunning) {
		std::cout << std::flush;
		if (_kbhit()) {
			mu.lock();
			if (_getch() == 27) {
				isRunning = false;
			} else if (_getch() == '\n') {
				if (checkAnswer(answerBuffer, correct.second)) {
					score++;
					answerBuffer.clear();
					correct = newQuestion();
				} else {
					answerBuffer.clear();
				}
			} else if (_getch() == 127 || _getch() == 8) {
				answerBuffer.pop_back();
			} else {
				if (!(answerBuffer.size() < 15)) {
					answerBuffer.pop_back();
					answerBuffer.push_back(_getch());
				} else {
					answerBuffer.push_back(_getch());
				}
			}
			mu.unlock();
		}
	}
}

bool checkAnswer(const std::string& answer, const std::string& correct) {
	if (answer == correct)
		return true;
	else
		return false;
}

std::pair<std::string, std::string> newQuestion() {
	int choice = std::rand() % User::statesMap.size();
	return *std::next(User::statesMap.begin(), choice);
}
/*
Capital Quiz
Write a program that creates a map containing the U.S. states as keys, and their capitals as values. 
(Use the Internet to get a list of the states and their capitals.) The program should then randomly 
quiz the user by displaying the name of a state and ask the user to enter that state’s capital. The 
program should keep a count of the number of correct and incorrect responses. (As an alternative to 
the U.S. states, the program can use the names of countries and their capitals.)
*/