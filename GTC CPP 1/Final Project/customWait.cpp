#include "customWait.h"
#include <chrono>
#include <thread>

void wait(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}