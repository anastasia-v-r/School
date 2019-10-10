#include <iostream>
#include "Date.hpp"

int main() {
	Date later(4, 30, 2000);
	Date earlier(6, 22, 1950);
	int i = later - earlier;
	system("cmd /k");
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

/*
12/25/2018
December 25, 2018
25 December 2018
3 formats
*/