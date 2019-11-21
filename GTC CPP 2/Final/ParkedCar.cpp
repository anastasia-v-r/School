#include "ParkedCar.hpp"
#include "Funcs.hpp"
#include <set>

std::set<unsigned short> ParkedCar::known_plates;

std::map<MAKE_MODEL, std::pair<std::string, std::string>> ParkedCar::MAKE_MODEL_DICT = {
	{MAKE_MODEL::TOYOTA_CAMRY	, { "Toyota", "Camry" } },
	{MAKE_MODEL::TOYOTA_COROLLA	, { "Toyota", "Corolla" } },
	{MAKE_MODEL::HONDA_CIVIC	, { "Honda", "Civic" } },
	{MAKE_MODEL::HONDA_ACCORD	, { "Honda", "Accord" } },
	{MAKE_MODEL::DODGE_RAM		, { "Dodge", "Ram" } },
	{MAKE_MODEL::DODGE_CHARGER	, { "Dodge", "Charger" } }
};

std::map<COLOR, std::string> ParkedCar::COLOR_DICT = {
	{ COLOR::RED	, "Red"   },
	{ COLOR::ORANGE	, "Orange"},
	{ COLOR::YELLOW	, "Yellow"},
	{ COLOR::GREEN	, "Green" },
	{ COLOR::BLUE	, "Blue"  },
	{ COLOR::INDIGO	, "Indigo"},
	{ COLOR::VIOLET	, "Violet"},
	{ COLOR::WHITE	, "White" },
	{ COLOR::SILVER	, "Silver"},
	{ COLOR::BLACK	, "Black" }
};

ParkedCar::ParkedCar(MAKE_MODEL make_and_model, COLOR color)
	: make{ MAKE_MODEL_DICT[make_and_model].first }
		, model{ MAKE_MODEL_DICT[make_and_model].second }
		, color{ COLOR_DICT[color] }
		, plate{ Custom::getFreshId(ParkedCar::known_plates) }
		, time_parked{ 0.0 }
	{};

void ParkedCar::passTime(double minutes) { 
	time_parked += minutes;
};

void ParkedCar::giveTicket(ParkingTicket ticket) { 
	tickets.push_back(ticket); 
};