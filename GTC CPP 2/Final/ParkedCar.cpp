#include "ParkedCar.hpp"
#include "Funcs.hpp"
#include <set>

std::set<unsigned short> ParkedCar::known_plates;

ParkedCar::ParkedCar(MAKE_MODEL make_and_model, COLOR color)
	: make{ MAKE_MODEL_DICT[make_and_model].first }
		, model{ MAKE_MODEL_DICT[make_and_model].second }
		, color{ COLOR_DICT[color] }
		, plate{ getFreshId(ParkedCar::known_plates) }
		, time_parked{ 0.0 }
	{};

void ParkedCar::passTime(double minutes) { 
	time_parked += minutes;
};

void ParkedCar::giveTicket(ParkingTicket ticket) { 
	tickets.push_back(ticket); 
};