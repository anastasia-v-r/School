#pragma once
#include <string>

class Date
{
public:
	// Structors
	Date();
	~Date();
	// Getters
	std::string getDateFormat1();
	std::string getDateFormat2();
	std::string getDateFormat3();
	// Setters
	void setMonth(int);
	void setDay(int);
	void setYear(int);
private:
	int month;
	int day;
	int year;
};
