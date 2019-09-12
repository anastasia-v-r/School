#pragma once
#include <string>
#include "Name.hpp"

class Patient
{
public:
	// Constructor
	Patient(Name pName, std::string pStreet, std::string pCity, std::string pState, short pZip, long double pPhone, Name conName, long double conNum)
		: fullName{ pName }
		, street{ pStreet }
		, city{ pCity }
		, state{ pState }
		, zipCode{ pZip }
		, phoneNumber{ pPhone }
		, contactName{ conName }
		, contactNumber{ conNum }
	{
	};
	// Setters
	void setFullname(Name afullName) { fullName = afullName; };
	void setStreet(std::string astreet) { street = astreet; };
	void setCity(std::string acity) { city = acity; };
	void setState(std::string astate) { state = astate; };
	void setZipCode(short azip) { zipCode = azip; };
	void setPhoneNumber(long double aphone) { phoneNumber = aphone; };
	void setContactName(Name afullName) { contactName = afullName; };
	void setContactNumber(long double aphone) { contactNumber = aphone; };
	// Getters
	Name getFullName() { return fullName; };
	std::string getStreet() { return street; };
	std::string getCity() { return city; };
	std::string getState() { return state; };
	short getZip() { return zipCode; };
	long double getPhone() { return phoneNumber; };
	Name getContactName() { return contactName; };
	long double getContactNumber() { return contactNumber; };
private:
	// Patient Full Name
	Name fullName;
	// Patient Home Address
	std::string street, city, state;
	short zipCode;
	// Phone number
	long double phoneNumber;
	// Emergency Contact
	Name contactName;
	long double contactNumber;
};