#include "CustomerData.hpp"

CustomerData::CustomerData(std::string LastName, std::string FirstName, std::string Address, std::string City, std::string State, std::string Zip, std::string Phone, int number, bool mailing)
	{
	mLastName  = LastName;
	mFirstName = FirstName;
	mAddress   = Address;
	mCity	   = City;
	mState	   = State;
	mZip	   = Zip;
	mPhone	   = Phone;
	mCustomerNumber = number;
	mMailingList = mailing;
}

CustomerData::~CustomerData()
{
}