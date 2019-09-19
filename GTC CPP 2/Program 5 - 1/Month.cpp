#include "Month.hpp"

Month::Month() 
	: name{ "Januray" }
	, monthNumber{ 1 }
{
}
;

Month::Month(std::string name) {
	SetMonth(name);
}

Month::Month(int num) {
	SetMonth(num);
}

bool Month::SetMonth(std::string str) {
	auto name = ([str] {
		for (const auto& letter : str) {
			letter = std::tolower(letter);
		}
		str[0] = std::toupper(str[0]);
		return str;
	});
	if (MonthMap.count(str)) {
		name = str;
		return true;
	} else {
		return false;
	}
}

bool Month::SetMonth(int num) {
	std::iterator it = MonthMap.begin();
	for (  )
}

std::pair<int, std::string> Month::GetMonth() {

}

Month Month::operator++()
{
	++;
	simplify();
	return *this;
}

void Month::operator++(int)
{
	FeetInches temp(feet, inches);
	inches++;
	simplify();
	return temp;
}
/*
A constructor that accepts the name of the month as an argument. It should set name to the value passed as the 
argument and set monthNumber to the correct value.

A constructor that accepts the number of the month as an argument. It should set monthNumber to the value passed 
as the argument and set name to the correct month name.

Appropriate set and get functions for the name and monthNumber member variables.

Prefix and postfix overloaded ++ operator functions that increment monthNumber and set name to the name of next month.
If monthNumber is set to 12 when these functions execute, they should set monthNumber to 1 and name to “January.”

Prefix and postfix overloaded −− operator functions that decrement monthNumber and set name to the name of previous month. 
If monthNumber is set to 1 when these functions execute, they should set monthNumber to 12 and name to “December.”

Also, you should overload cout’s << operator and cin’s >> operator to work with the Month class. Demonstrate the class in a program.
*/