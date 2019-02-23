#include <iostream>
#include <iomanip>

void validate(float& blue, float max)
{
	std::cin >> blue;
	while (blue < 15.00 || blue > max)
	{
		std::cout << "Please enter a number between or equal to " << max << " and 15.\n";
		std::cin >> blue;
	}
}


int main()
{
	const int arrSize = 7;
	long int empId[arrSize] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489 };
	float hours[arrSize];
	float payRate[arrSize];
	float wages[arrSize];
	float temp;

	for (int count = 0; count < 7; ++count)
	{
		std::cout << "Now working on Employee [" << empId[count] << "].\n\n";
		
		std::cout << "Please enter the hours of the employee.\n";
		validate(hours[count], 112.00);

		std::cout << "Please enter the pay rate of the employee.\n";
		validate(payRate[count], 32.00);

		wages[count] = ( (hours[count]) * (payRate[count]) );
		
	}

	std::cout << "\nEmployee Pay List\n" << "-------------\n";
	for (int count = 0; count < 7; ++count)
	{
		std::cout << "EmpId[" << empId[count] << "]   Pay : " << std::setw(5) << wages[count] << "\n";
	}

	std::cin.ignore(2);
}