#include "Date.hpp"
#include <iostream>

// Month list
std::vector<std::string> monthNames{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

// Structors

Date::Date()
	: month{ 1 }
	, day{ 1 }
	, year{ 1970 }
{
}

Date::Date(int month, int day, int year)
	: month{ month }
	, day{day}
	, year{year}
{
}

Date::~Date()
{
}

// Outputters

std::string Date::getDateFormat1() {
	return "DateFormat1";
}

std::string Date::getDateFormat2() {
	return "DateFormat2";
}

std::string Date::getDateFormat3() {
	return "DateFormat3";
}

// Getters

int Date::getMonth() {
	return this->month;
}

int Date::getDay() {
	return this->day;
}

int Date::getYear() {
	return this->year;
}

// Setters

void Date::setMonth(int temp) {
	this->month = temp;
}

void Date::setDay(int temp) {
	this->day = temp;
}

void Date::setYear(int temp) {
	this->year = temp;
}

// Overloads

Date& Date::operator++()
{
	// operate on object
	switch (this->month)
	{
	case 2: // February Special Case
		if ((this->year % 4 && this->day == 29) || (this->day == 28)) {
			this->month++;
			this->day = 1;
		} else {
			this->day++;
		}
		break;
	case 1: // 31 day months
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (this->day == 31) {
			this->day = 1;
			if (this->month == 12) {
				this->year++;
				this->month = 1;
			} else {
				this->month++;
			}
		} else {
			this->day++;
		}
		break;
	case 4: // 30 day months
	case 6:
	case 9:
	case 11:
		if (this->day == 31) {
			this->day = 1;
			this->month++;
		} else {
			this->day++;
		}
		break;
	default:
		break;
	}
	return *this;
}

Date& Date::operator--()
{
	// operate on object
	if (this->day == 1) {
		if (this->month == 1)
			this->year--;
		switch (this->month)
		{
		case 3: // March Special case
			if (this->year % 4)
				this->day = 29;
			else
				this->day = 28;
			break;
		case 1: // Into 31 days
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			this->day = 31;
			break;
		case 5: // Into 30 days
		case 7:
		case 10:
		case 12:
			this->day = 30;
		default:
			break;
		}
	}
	return *this;
}

Date& Date::operator++(int)
{
	Date temp(*this);
	// operate on non temp
	switch (this->month)
	{
	case 2: // February Special Case
		if ((this->year % 4 && this->day == 29) || (this->day == 28)) {
		this->month++;
		this->day = 1;
		}
		else {
			this->day++;
		}
		break;
	case 1: // 31 day months
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (this->day == 31) {
			this->day = 1;
			if (this->month == 12) {
				this->year++;
				this->month = 1;
			}
			else {
				this->month++;
			}
		}
		else {
			this->day++;
		}
		break;
	case 4: // 30 day months
	case 6:
	case 9:
	case 11:
		if (this->day == 31) {
			this->day = 1;
			this->month++;
		}
		else {
			this->day++;
		}
		break;
	default:
		break;
	}
	return temp;
}

Date& Date::operator--(int)
{
	Date temp(*this);
	// operate on non temp
	if (this->day == 1) {
		if (this->month == 1)
			this->year--;
		switch (this->month)
		{
		case 3: // March Special case
			if (this->year % 4)
				this->day = 29;
			else
				this->day = 28;
			break;
		case 1: // Into 31 days
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			this->day = 31;
			break;
		case 5: // Into 30 days
		case 7:
		case 10:
		case 12:
			this->day = 30;
		default:
			break;
		}
	}
	return temp;
}

int Date::operator-(const Date& otherDate)
{
	int dayDiff = 0;
	auto temp = otherDate;
	while (temp.year != this->year || temp.month != this->month || temp.day != this->day) {
		temp--;
		dayDiff++;
		std::cout << temp << "\nCurrent Diff (" << dayDiff << ")" << std::endl;
	}
	std::cout << "Day difference is [" << dayDiff << "]" << std::endl;
	return dayDiff;
}

std::ostream& operator<<(std::ostream& strm, const Date& obj)
{
	strm << monthNames[(int)obj.month + 1] << " " << obj.day << ", " << obj.year << std::endl;
	return strm;
}

std::istream& operator>>(std::istream& strm, Date& obj)
{
	int month;
	int year;
	int day;
	int dayMax;
	do {
		std::cout << "Please enter the year [0-∞]" << std::endl;
		strm >> year;
	} while (year < 0);
	obj.year = year;
	do {
		std::cout << "Please enter the month [1-12]" << std::endl;
		strm >> month;
	} while (month < 1 || month > 12);
	obj.month = month;
	switch (month)
	{
	case 2: // February Special Case
		if (year % 4)
			dayMax = 29;
		else
			dayMax = 28;
		break;
	case 1: // 31 day months
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		dayMax = 31;
		break;
	case 4: // 30 day months
	case 6:
	case 9:
	case 11:
		dayMax = 30;
		break;
	default:
		break;
	}
	do {
		std::cout << "Please enter the day [0-(28/29/30/31)]" << std::endl;
		strm >> day;
	} while (day < 1 || day > dayMax);
	obj.day = day;
	return strm;
}


/*
Date Class Modification
Modify the Date class in Programming Challenge 1 of Chapter 13. The new version should have the following overloaded operators:

−
Subtraction operator. If one Date object is subtracted from another, the operator should give the number of days between the two dates. \
For example, if April 10, 2014 is subtracted from April 18, 2014, the result will be 8.

The class should detect the following conditions and handle them accordingly:

*/
