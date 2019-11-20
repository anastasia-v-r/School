#pragma once
#include "PoliceOfficer.hpp"
#include "ParkedCar.hpp"
#include "ParkingMeter.hpp"
#include <string>

class ParkedCar;
class PoliceOfficer;
class ParkingMeter;

class ParkingTicket 
{
public:
	// Constructors
	ParkingTicket() = default;
	ParkingTicket(const ParkedCar&, const PoliceOfficer&, const ParkingMeter&);
	// Getters
	double getFine() const;
	std::string getMake() const;
	std::string getModel() const;
	std::string getColor() const;
	std::string getPlate() const;
	std::string getName() const;
	unsigned short getBadge() const;
private:
	std::string make;
	std::string model;
	std::string color;
	std::string plate;
	double fine;
	std::string issuing_officer;
	unsigned short officer_badge;
};
