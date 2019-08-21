#include <iostream>
#include <iomanip>

void sort(float*, int);

int main() {
	int elem;
	float avg = 0;
	std::cout << "Please indicate the number of test scores. \n";
	std::cin >> elem;
	float* fArr = new float[elem];
	for (int i = 0; i < elem; i++) {
		std::cout << "Please enter the test score for test #" << (i + 1) << "\n";
		std::cin >> fArr[i];
		while (fArr[i] < 0) {
			std::cout << "Please enter a positive value.\n";
			std::cin >> fArr[i];
		}
		avg += fArr[i];
	}
	avg /= elem;
	sort(fArr, elem);

	std::cout << "\nTest Scores\n";
	std::cout << "===========\n";
	for (int i = 0; i < elem; i++) {
		std::cout << std::setprecision(2) << std::fixed << fArr[i] << "\n";
	}
	std::cout << "===========\n";
	std::cout << "Avg: " << std::setprecision(2) << std::fixed << avg << "\n";

	delete [] fArr;
}

void sort(float* arr, int size) {
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
			if (arr[count] > arr[count + 1]) {
				++swaps;
				larger = arr[count];
				arr[count] = arr[count + 1];
				arr[count + 1] = larger;
				swap = true;
			}
			++checks;
		}
		++wholePass;
		--end;
	} while (swap != false);
}
