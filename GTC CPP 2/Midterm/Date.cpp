#include "Date.hpp"

// Structors

Date::Date()
	: month{ 1 }
	, day{ 1 }
	, year{ 1970 }
{
}

Date::~Date()
{
}

// Getters

std::string Date::getDateFormat1() {

}

std::string Date::getDateFormat2() {

}

std::string Date::getDateFormat3() {

}

// Setters

void Date::setMonth(int temp) {

}

void Date::setDay(int temp) {

}

void Date::setYear(int temp) {

}

// Overloads

Date& Date::operator++()
{
	// operate on object
	return *this;
}

Date& Date::operator--()
{
	// operate on object
	return *this;
}

Date Date::operator++(int)
{
	Month temp(name);
	// operate on non temp
	return temp;
}

Date Date::operator--(int)
{
	Date temp(name);
	// operate on non temp
	return temp;
}

std::ostream& operator<<(std::ostream& strm, const Date& obj)
{
	strm << "\"" << std::endl;
	return strm;
}

std::istream& operator>>(std::istream& strm, Date& obj)
{
	strm >> input;
	month = input;
	return strm;
}


/*
Date Class Modification
Modify the Date class in Programming Challenge 1 of Chapter 13. The new version should have the following overloaded operators:
++
Prefix and postfix increment operators. These operators should increment the object’s day member.
−−
Prefix and postfix decrement operators. These operators should decrement the object’s day member.
−
Subtraction operator. If one Date object is subtracted from another, the operator should give the number of days between the two dates. For example, if April 10, 2014 is subtracted from April 18, 2014, the result will be 8.
<<
cout’s stream insertion operator. This operator should cause the date to be displayed in the form
April 18, 2018
>>
cin’s stream extraction operator. This operator should prompt the user for a date to be stored in a Date object.
The class should detect the following conditions and handle them accordingly:
When a date is set to the last day of the month and incremented, it should become the first day of the following month.
When a date is set to December 31 and incremented, it should become January 1 of the following year.
When a day is set to the first day of the month and decremented, it should become the last day of the previous month.
When a date is set to January 1 and decremented, it should become December 31 of the previous year.
Demonstrate the class’s capabilities in a simple program.
Input Validation: The overloaded >> operator should not accept invalid dates. For example, the date 13/45/2018 should not be accepted.
*/
