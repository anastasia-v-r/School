#pragma once
#include <string>
#include <vector>
#include <iostream>

class Date;

std::ostream& operator<<(std::ostream&, const Date&);
std::istream& operator>>(std::istream&, Date&);

class Date
{
public:
	// Structors
	Date();
	Date(int, int, int);
	~Date();
	// Outputters
	std::string numberedFormat();
	std::string monthDayFormat();
	std::string dayMonthFormat();
	// Getters
	int getMonth();
	int getDay();
	int getYear();
	// Setters
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	// Overloads
	Date& Date::operator++();
	Date& Date::operator++(int);
	Date& Date::operator--();
	Date& Date::operator--(int);
	int Date::operator-(const Date&);
	// Overload Friends :D
	friend std::ostream& operator<<(std::ostream&, const Date&);
	friend std::istream& operator>>(std::istream&, Date&);
private:
	int month;
	int day;
	int year;
};

std::ostream& operator<<(std::ostream&, const Date&);
std::istream& operator>>(std::istream&, Date&);