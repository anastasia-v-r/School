#include <iostream>

int main()
{

	float loan = 0, insur = 0, gas = 0, oil = 0, tires = 0, maint = 0;

	std::cout << "Please enter your monthly cost for Car loan, Car Insurance, Gas, Oil, Tires, and Maintenance.\n";
	std::cin >> loan >> insur >> gas >> oil >> tires >> maint;
	
	float monthly = loan + insur + gas + oil + tires + maint;
	float yearly = monthly * 12;
	
	std::cout << "Your monthly expenses are, " << monthly << " while your yearly costs are, " << yearly << ".\n";
	std::cin.ignore(2);

}