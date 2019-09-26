#include "PreferredCustomer.hpp"

PreferredCustomer::PreferredCustomer()
	: CustomerData("Doe", "Jane", "5555 Jane Street", "Atlanta", "GA", "20001", "5559992323", 0, true)
	, mPurchasesAmount{ 0.0 }
	, mDiscountLevel{ 0.0 }
{

}