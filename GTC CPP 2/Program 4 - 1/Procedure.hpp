#pragma once
#include <string>
#include "Name.hpp"

class Procedure
{
public:
	// Constructor
	Procedure(std::string patName, std::string date, std::string pracName, float num)
		: procedureName{ patName }
		, Date{ date }
		, practitionerName{ pracName }
		, Cost{ num }
	{

	};
	// Setters
	void setProcedureName(std::string name) { procedureName = name; };
	void setDate(std::string date) { Date = date; };
	void setPractitionerName(std::string name) { practitionerName = name; };
	void setCost(float cost) { Cost = cost; };
	// Getters
	std::string getProcedureName() { return procedureName; };
	std::string getDate() { return Date; };
	std::string getPractitionerName() { return practitionerName; };
	float getCost() { return Cost; };
private:
	std::string procedureName;
	std::string Date;
	std::string practitionerName;
	float Cost;
};