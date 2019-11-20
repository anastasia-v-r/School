#pragma once
#include <string>
#include <vector>
#include "ParkingTicket.hpp"

class ParkingTicket;

class ParkedCar
{
public:
	// Constructors
	ParkedCar() = default;
	ParkedCar(std::string /*make*/, std::string /*model*/, std::string /*color*/, std::string /*plate*/);
	// Processors
	void passTime(double /*minutes*/);
	void giveTicket(ParkingTicket /*ticket*/);
	// Getters
	inline std::string getMake() const { return this->make; };
	inline std::string getModel() const { return this->model; };
	inline std::string getColor() const { return this->color; };
	inline std::string getPlate() const { return this->plate;};
	inline double getTime() const { return this->time_parked; };
private:
	std::string make;
	std::string model;
	std::string color;
	std::string plate;
	double time_parked;
	std::vector<ParkingTicket> tickets;
};
