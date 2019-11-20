#include "ParkedCar.hpp"

ParkedCar::ParkedCar(std::string make, std::string model, std::string color, std::string plate)
	: make{ make }
		, model{ model }
		, color{ color }
		, plate{ plate }
		, time_parked{ 0.0 }
	{};

void ParkedCar::passTime(double minutes) { 
	time_parked += minutes;
};

void ParkedCar::giveTicket(ParkingTicket ticket) { 
	tickets.push_back(ticket); 
};