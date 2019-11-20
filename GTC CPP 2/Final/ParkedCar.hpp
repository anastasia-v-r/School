#pragma once
#include <string>
#include <vector>
#include <set>
#include <map>
#include "ParkingTicket.hpp"

class ParkingTicket;

enum class MAKE_MODEL {
	TOYOTA_CAMRY,
	TOYOTA_COROLLA,
	HONDA_CIVIC,
	HONDA_ACCORD,
	DODGE_RAM,
	DODGE_CHARGER
};

enum class COLOR {
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	INDIGO,
	VIOLET,
	WHITE,
	SILVER,
	BLACK
};

class ParkedCar
{
public:
	// Constructors
	ParkedCar() = default;
	ParkedCar(MAKE_MODEL /* make and model */, COLOR /*color*/);
	// Processors
	void passTime(double /*minutes*/);
	void giveTicket(ParkingTicket /*ticket*/);
	// Getters
	inline std::string getMake() const { return this->make; };
	inline std::string getModel() const { return this->model; };
	inline std::string getColor() const { return this->color; };
	inline unsigned short getPlate() const { return this->plate;};
	inline double getTime() const { return this->time_parked; };
private:
	std::string make;
	std::string model;
	std::string color;
	unsigned short plate;
	double time_parked;
	std::vector<ParkingTicket> tickets;
	
	static std::set<unsigned short> known_plates;

	std::map<MAKE_MODEL, std::pair<std::string, std::string>> MAKE_MODEL_DICT = {
	{MAKE_MODEL::TOYOTA_CAMRY	, { "Toyota", "Camry" } },
	{MAKE_MODEL::TOYOTA_COROLLA	, { "Toyota", "Corolla" } },
	{MAKE_MODEL::HONDA_CIVIC	, { "Honda", "Civic" } },
	{MAKE_MODEL::HONDA_ACCORD	, { "Honda", "Accord" } },
	{MAKE_MODEL::DODGE_RAM		, { "Dodge", "Ram" } },
	{MAKE_MODEL::DODGE_CHARGER	, { "Dodge", "Charger" } }
	};

	std::map<COLOR, std::string> COLOR_DICT = {
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
};
