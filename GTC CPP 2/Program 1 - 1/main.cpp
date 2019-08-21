#include <iostream>

int* intArray(int);

int main() {
	int elem;
	std::cout << "Array size? \n";
	std::cin >> elem;
	int* iArr = intArray(elem);
	for (int i = 0; i < elem; i++) {
		std::cout << iArr[i] << " ";
	}
	std::cout << "\n";
	std::cin.ignore();
}

int* intArray(int numelem) {
	int* arr = new int[numelem];
	for (int i = 0; i < numelem; i++) {
		arr[i] = i;
	}
	return arr;
}