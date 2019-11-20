#pragma once
#include <string>
#include <vector>
#include "ParkingTicket.hpp"

class ParkedCar
{
public:
	// Constructors
	ParkedCar() = delete;
	inline ParkedCar(std::string make, std::string model, std::string color, std::string plate)
		: make{make}
		, model{model}
		, color{color}
		, plate{plate}
		, time_parked{ 0.0 }
	{};
	// Processors
	inline void passTime(double minutes) { time_parked += minutes; };
	inline void ticket(ParkingTicket ticket) { tickets.push_back(ticket); };
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
