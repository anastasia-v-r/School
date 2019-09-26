#pragma once
#include "CustomerData.hpp"

class PreferredCustomer : public CustomerData
{
public:
	PreferredCustomer();
	~PreferredCustomer();
	// Getters
	double getPurchasesAmount() { return mPurchasesAmount; };
	double getDiscountLevel() { return mDiscountLevel; };
	// Setters
	void setPurchasesAmount(double temp) { mPurchasesAmount = temp; };
	void setDiscountLevel(double temp) { mDiscountLevel = temp; };
private:
	double mPurchasesAmount;
	double mDiscountLevel;
};

PreferredCustomer::PreferredCustomer()
{
}

PreferredCustomer::~PreferredCustomer()
{
}