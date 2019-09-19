#include <string>
#include <map>
#include <iostream>

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
	std::pair<int, std::string> GetMonth();
	// Setters
	bool SetMonth(std::string);
	bool SetMonth(int);
	// Overloads
	Month& operator++();
	Month& operator--();
	Month operator++(int);
	Month operator--(int);
	friend std::ostream& operator<<(std::ostream&, const Month&);
	friend std::istream& operator>>(std::istream&, Month&);
private:
	std::string name;
	int monthNumber;
	std::map<int, std::string> MonthMap{
		{ 1, "january"	},
		{ 2, "febuary"	},
		{ 3, "march"	},
		{ 4, "april"	},
		{ 5, "may"		},
		{ 6, "june"		},
		{ 7, "july"		},
		{ 8, "august"	},
		{ 9, "september"},
		{10, "october"  },
		{11, "november" },
		{12, "december" }
	};
};