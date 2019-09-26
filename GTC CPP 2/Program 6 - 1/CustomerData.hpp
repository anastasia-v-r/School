#pragma once
#include "PersonData.hpp"

class CustomerData : public PersonData
{
public:
	CustomerData();
	~CustomerData();
	// Getters

	// Setters

private:
	int customerNumber;
	bool mailingList;
};
