#pragma once
#include <string>

class PersonData
{
public:
	PersonData();
	~PersonData();
	// Getters
	std::string getLastName()	{ return mLastName;};
	std::string getFirstName()	{ return mFirstName; };
	std::string getAddress()	{ return mAddress; };
	std::string getCity()		{ return mCity; };
	std::string getState()		{ return mState; };
	std::string getZip()		{ return mZip; };
	std::string getPhone()		{ return mPhone; };
	// Setters
	void setLastName(std::string temp)	{ mLastName = temp; };
	void setFirstName(std::string temp) { mFirstName = temp; };
	void setAddress(std::string temp)	{ mAddress = temp; };
	void setCity(std::string temp)		{ mCity = temp; };
	void setState(std::string temp)		{ mState = temp; };
	void setZip(std::string temp)		{ mZip = temp; };
	void setPhone(std::string temp)		{ mPhone = temp; };
private:

protected:
	std::string mLastName;
	std::string	mFirstName;
	std::string	mAddress;
	std::string	mCity;
	std::string	mState;
	std::string	mZip;
	std::string	mPhone;
};
