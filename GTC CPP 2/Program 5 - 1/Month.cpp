#include "Month.hpp"
#include <algorithm>

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

Month::~Month() {

}

bool Month::SetMonth(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	std::map<int, std::string>::iterator it = MonthMap.begin();
	for (const auto& element : MonthMap) {
		if (element.second == str) {
			name = element.second;
			monthNumber = element.first;
			return true;
		}
	}
	return false;
}

bool Month::SetMonth(int num) {
	std::map<int, std::string>::iterator it = MonthMap.begin();
	for (const auto& element : MonthMap) {
		if (element.first == num) {
			name = element.second;
			monthNumber = element.first;
			return true;
		}
	}
	return false;
}

std::pair<int, std::string> Month::GetMonth() {
	return std::make_pair( monthNumber, name );
}

Month& Month::operator++()
{
	if (monthNumber == 12) {
		monthNumber = 1;
		name = MonthMap[monthNumber];
	} else {		   
		monthNumber++; 
		name = MonthMap[monthNumber];
	}
	return *this;
}

Month& Month::operator--()
{
	if (monthNumber == 1) {
		monthNumber = 12;
		name = MonthMap[monthNumber];
	}
	else {
		monthNumber--;
		name = MonthMap[monthNumber];
	}
	return *this;
}

Month Month::operator++(int)
{
	Month temp(name);
	if (monthNumber == 12) {
		monthNumber = 1;
		name = MonthMap[monthNumber];
	}
	else {
		monthNumber++;
		name = MonthMap[monthNumber];
	}
	return temp;
}

Month Month::operator--(int)
{
	Month temp(name);
	if (monthNumber == 1) {
		monthNumber = 12;
		name = MonthMap[monthNumber];
	}
	else {
		monthNumber--;
		name = MonthMap[monthNumber];
	}
	return temp;
}

std::ostream& operator<<(std::ostream& strm, const Month& obj)
{
	strm << "Month [" << obj.monthNumber << "] : \"" << (char)std::toupper(obj.name[0]);
	for (int i = 1; i < obj.name.length(); i++) {
		strm << obj.name[i];
	}
	strm << "\"" << std::endl;
	return strm;
}

std::istream& operator>>(std::istream& strm, Month& obj)
{
	std::cout << "Please enter the month name or number [1-12]" << std::endl;
	std::string input;
	strm >> input;
	if (std::isdigit(input[0])) {
		obj = Month(std::stoi(input));
	} else {
		obj = Month(input);
	}
	return strm;
}
