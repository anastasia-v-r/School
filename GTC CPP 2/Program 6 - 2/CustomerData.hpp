#pragma once
#include "PersonData.hpp"

class CustomerData : public PersonData
{
public:
	CustomerData(std::string, std::string, std::string, std::string, std::string, std::string, std::string, int, bool);
	~CustomerData();
	// Getters
	int getCustomerNumber() { return mCustomerNumber; };
	bool getMailingList() {	return mMailingList; };
	// Setters
	void setCustomerNumber(int temp) { mCustomerNumber = temp; };
	void setMailingList(bool temp) { mMailingList = temp; };
private:
	int mCustomerNumber;
	bool mMailingList;
};
