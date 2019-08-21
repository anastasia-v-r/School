#pragma once
#include <string>
#include <vector>

// Structs
struct drink {
	std::string name;
	float cost;
	int quantity;
};

struct machine {
	std::vector<drink> inventory;
	float revenue;
};
