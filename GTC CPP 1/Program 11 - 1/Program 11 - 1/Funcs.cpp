// Includes
#pragma once
#include <iostream>
#include <Windows.h>

//Bodys
void printArr(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << "[" << arr[i] << "]";
	}
	std::cout << "\n\n";
}


void sort(int* arr, int size) {
	bool swap;
	int larger;
	int end = size - 1;
	int wholePass = 0;
	int checks = 0;
	int swaps = 0;

	do {
		swap = false;
		int thisPass = 1;
		for (int count = 0; count < end; ++count) {
			//Sleep(100); //Debug
			//std::cout << "Whole Passes :" << wholePass << " | This Pass :" << thisPass << "\n"; //Debug
			//std::cout << "Scanning Elem : [" << count << "/" << end << "]\n"; //Debug
			if (arr[count] > arr[count + 1]) {
				++swaps;
				larger = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = larger;
				swap = true;
			}
			//printArr(arr, size); //Debug
			++checks;
		}
		++wholePass;
		--end;
	} while (swap != false);
	//std::cout << "Total Passes :" << wholePass << " | Checks : " << checks << " | Swaps : " << swaps << "\n"; //Debug
}

void median(int* arr,int size) {
	if (size % 2 == 0) {
		float a = arr[(size / 2) - 1];
		float b = arr[(size / 2)];
		//std::cout << "A / B " << a << "/" << b << "\n"; //Debug
		std::cout << "Median : " << (a + b) / 2 << "\n";
	}
	else {
		std::cout << "Median : " << arr[size / 2] << "\n";
	}
}

void mean(int* arr, int size) {
	float total = 0;
	for (int i = 0; i < size; ++i) {
		total += arr[i];
	}
	std::cout << "Mean : " << total / size << "\n";
}

void mode(int* arr, int size) {
	int currMode = arr[0];
	int currModeFreq = 0;
	int possMode = 0;
	int possModeFreq;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == currMode) {
			++currModeFreq;
		}
		else if (arr[i] == possMode) {
			++possModeFreq;
			if (possModeFreq > currModeFreq) {
				currMode = possMode;
				currModeFreq = possModeFreq;
			}
		}
		else {
			possMode = arr[i];
			possModeFreq = 1;
		}
	}
	std::cout << "Mode : " << currMode;
}
