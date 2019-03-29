#include <iostream>
#include <Windows.h>
#include <time.h>
#include <thread>

void threadFunc(int tn) {
	std::cout << tn << std::endl;
	for (int i = 0; i < INT_MAX; i++) {
		char* asdf = new char;
	}
}

int main() {
	for (int i = 0; i < 8; i++) {
		std::thread tempthread(threadFunc, i);
		tempthread.detach();
	}
	system("pause > NUL");
	return 0;
}

