#include "ParkedCar.hpp"
#include "Funcs.hpp"
#include <set>

std::set<unsigned short> ParkedCar::known_plates;

ParkedCar::ParkedCar(std::string make, std::string model, std::string color)
	: make{ make }
		, model{ model }
		, color{ color }
		, plate{ getFreshId(ParkedCar::known_plates) }
		, time_parked{ 0.0 }
	{};

void ParkedCar::passTime(double minutes) { 
	time_parked += minutes;
};

void ParkedCar::giveTicket(ParkingTicket ticket) { 
	tickets.push_back(ticket); 
};