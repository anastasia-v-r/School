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
	inline const std::vector<ParkingTicket>& getTickets() const { return tickets; };
private:
	std::string make;
	std::string model;
	std::string color;
	unsigned short plate;
	double time_parked;
	std::vector<ParkingTicket> tickets;
	
	static std::set<unsigned short> known_plates;

	static std::map<MAKE_MODEL, std::pair<std::string, std::string>> MAKE_MODEL_DICT;
	static std::map<COLOR, std::string> COLOR_DICT;
};
