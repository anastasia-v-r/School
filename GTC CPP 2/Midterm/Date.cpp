#include "Date.hpp"
#include <iostream>
#include <sstream>

// Month list
std::vector<std::string> monthNames{
	"None",
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

Date::Date(int month, int day, int year) {
	if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31) {
		throw "Invalid parameters for date creation";
	} else {
		switch (month)
		{
		case 2: // February Edge Case
			if (year % 4) {
				if (day > 29) {
					throw "February max days are 29 on leap years";
				}
			} else {
				if (day > 28) {
					throw "February max days are 27 on non-leap years";
				}
			}
		case 1: // 31 day months
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 31) {
				std::ostringstream temp;
				temp << monthNames[month] << " max days are 31";
				throw temp.str();
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30) {
				std::ostringstream temp;
				temp << monthNames[month] << " max days are 30";
				throw temp.str();
			}
		default:
			break;
		}
	}
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{
}

// Outputters

std::string Date::numberedFormat() {
	std::ostringstream temp;
	temp << month << "/" << day << "/" << year;
	return temp.str();
}

std::string Date::monthDayFormat() {
	std::ostringstream temp;
	temp << monthNames[month] << " " << day << ", " << year;
	return temp.str();
}

std::string Date::dayMonthFormat() {
	std::ostringstream temp;
	temp << day << " " << monthNames[month] << " " << year;
	return temp.str();
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
		if (this->day == 30) {
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
	if (month == 1 && day == 1 && year == 1) {
		throw "Dates before the current era are not supported";
	}
	if (day == 1) {
		switch (month)
		{
		case 3: // March Special case
			if (year % 4)
				day = 29;
			else
				day = 28;
			break;
		case 1: // Into 31 days
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			day = 31;
			break;
		case 5: // Into 30 days
		case 7:
		case 10:
		case 12:
			day = 30;
		default:
			break;
		}
		if (month == 1) {
			month = 12;
			year--;
		} else {
			month--;
		}
	} else {
		day--;
	}
	return *this;
}

Date& Date::operator++(int)
{
	Date temp(month, day, year);
	// operate on non temp
	switch (month)
	{
	case 2: // February Special Case
		if ((year % 4 && day == 29) || (day == 28)) {
		month++;
		day = 1;
		}
		else {
			day++;
		}
		break;
	case 1: // 31 day months
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day == 31) {
			day = 1;
			if (month == 12) {
				year++;
				month = 1;
			} else {
				month++;
			}
		} else {
			day++;
		}
		break;
	case 4: // 30 day months
	case 6:
	case 9:
	case 11:
		if (day == 31) {
			day = 1;
			month++;
		}
		else {
			day++;
		}
		break;
	default:
		break;
	}
	return temp;
}

Date& Date::operator--(int)
{
	Date temp(month, day, year);
	// operate on non temp
	if (month == 1 && day == 1 && year == 1) {
		throw "Dates before the current era are not supported";
	}
	if (day == 1) {
		switch (month)
		{
		case 3: // March Special case
			if (year % 4)
				day = 29;
			else
				day = 28;
			break;
		case 1: // Into 31 days
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			day = 31;
			break;
		case 5: // Into 30 days
		case 7:
		case 10:
		case 12:
			day = 30;
		default:
			break;
		}
		if (month == 1) {
			month = 12;
			year--;
		} else {
			month--;
		}
	} else {
		day--;
	}
	return temp;
}

int Date::operator-(const Date& otherDate)
{
	unsigned long long int dayDiff = 0;
	auto temp = *this;
	if ((temp.year < otherDate.year) ||
		(temp.year == otherDate.year && temp.month < otherDate.month) ||
		(temp.year == otherDate.year && temp.month == otherDate.month && temp.day < otherDate.day)) {
		std::cout << "Negative Date Error" << std::endl;
		return 0;
	}
	while (temp.year != otherDate.year || temp.month != otherDate.month || temp.day != otherDate.day) {
		temp--;
		dayDiff++;
		
		// std::cout << temp << "\nCurrent Diff (" << dayDiff << ")" << std::endl;
	}
	return dayDiff;
}

std::ostream& operator<<(std::ostream& strm, const Date& obj)
{
	strm << monthNames[(int)obj.month] << " " << obj.day << ", " << obj.year;
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
