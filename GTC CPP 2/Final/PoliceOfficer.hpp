#pragma once
#include <string>
#include <set>
#include <array>
#include "ParkingMeter.hpp"

class PoliceOfficer
{
public:
	PoliceOfficer();
	PoliceOfficer(std::string /* name */);
	~PoliceOfficer();
	void examine(const ParkingMeter& /* meter and car */);
private:
	std::string m_name;
	unsigned short m_id;
	static std::set<unsigned short> taken_ids;
};

/*
The PoliceOfficer Class: This class should simulate a police officer inspecting parked cars. The class’s responsibilities are:
– To know the police officer’s name and badge number
– To examine a ParkedCar object and a ParkingMeter object, and determine whether the car’s time has expired
– To issue a parking ticket (generate a ParkingTicket object) if the car’s time has expired
Write a program that demonstrates how these classes collaborate.
*/