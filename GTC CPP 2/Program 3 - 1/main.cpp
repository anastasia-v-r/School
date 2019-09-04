#include <iostream>

void sort(int* [], int);

int main() {
	const int ARRAY_SIZE = 10;
	int* ptrArr[ARRAY_SIZE];
	int intArr[ARRAY_SIZE]{ 6, 2, 5, 4, 7, 1, 3, 9, 8, 0 };
	for (int i = 0; i < ARRAY_SIZE; i++) {
		ptrArr[i] = &intArr[i];
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << intArr[i] << " " << *ptrArr[i] << std::endl;
	}
	sort(ptrArr, ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << intArr[i] << " " << *ptrArr[i] << std::endl;
	}
	system("pause");
}

void sort(int* arr[], int size) {
	bool swap;
	int* larger = nullptr;
	int end = size - 1;
	int wholePass = 0;
	int checks = 0;
	int swaps = 0;

	do {
		swap = false;
		int thisPass = 1;
		for (int count = 0; count < end; ++count) {
			if (*arr[count] > *arr[count + 1]) {
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
