#pragma once
#include "PoliceOfficer.hpp"
#include "ParkedCar.hpp"
#include "ParkingMeter.hpp"
#include <string>

class ParkingTicket
{
public:
	// Constructors
	ParkingTicket() = delete;
	ParkingTicket(const ParkedCar&, const PoliceOfficer&, const ParkingMeter&);
	// Getters
	inline double getFine() const { return this->fine; };
	inline std::string getMake() const { return this->make; };
	inline std::string getModel() const { return this->model; };
	inline std::string getColor() const { return this->color; };
	inline std::string getPlate() const { return this->plate; };
	inline std::string getName() const { return this->issuing_officer; };
	inline unsigned short getBadge() const { return this->officer_badge; };
private:
	std::string make;
	std::string model;
	std::string color;
	std::string plate;
	double fine;
	std::string issuing_officer;
	unsigned short officer_badge;
};

/*
The ParkingTicket Class: This class should simulate a parking ticket. The class’s responsibilities are:
– To report the make, model, color, and license number of the illegally parked car
– To report the amount of the fine, which is $25 for the first hour or part of an hour that the car is illegally parked, plus $10
for every additional hour or part of an hour that the car is illegally parked
– To report the name and badge number of the police officer issuing the ticket
*/