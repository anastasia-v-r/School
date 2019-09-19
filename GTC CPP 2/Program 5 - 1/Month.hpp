#include <string>
#include <map>

class Month
{
public:
	// Constructors
	Month(); // Default
	Month(std::string); // Use name to set
	Month(int); // Use number to set
	// Destructors
	~Month();
	// Getters
	std::pair<std::string, int> GetMonth();
	// Setters
	void SetMonth(std::string);
	void SetMonth(int);
	// Overloads
	friend void Month::operator++();
	friend void Month::operator++(int);
private:
	std::string name;
	int monthNumber;
	std::map<std::string, int> MonthMap{
		{"January"	,  1},
		{"Febuary"	,  2},
		{"March"	,  3},
		{"April"	,  4},
		{"May"		,  5},
		{"June"		,  6},
		{"July"		,  7},
		{"August"	,  8},
		{"September",  9},
		{"October"  , 10},
		{"November" , 11},
		{"December" , 12}
	};
};