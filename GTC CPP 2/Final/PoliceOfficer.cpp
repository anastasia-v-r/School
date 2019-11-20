#include "PoliceOfficer.hpp"
#include "ParkingMeter.hpp"
#include <random>

unsigned short getFreshId(const std::set<unsigned short>& /* Known Ids */);

PoliceOfficer::PoliceOfficer()
	: m_name{ "Undercover" } 
	, m_id{ getFreshId(PoliceOfficer::taken_ids) } {
	PoliceOfficer::taken_ids.insert(this->m_id);
}

PoliceOfficer::PoliceOfficer(std::string name)
	: m_name{ name } 
	, m_id{ getFreshId(PoliceOfficer::taken_ids) } {
	PoliceOfficer::taken_ids.insert(this->m_id);
}

PoliceOfficer::~PoliceOfficer() {
	PoliceOfficer::taken_ids.erase(this->m_id);
}

void PoliceOfficer::examine(const ParkingMeter& meter) {

}

unsigned short int getFreshId(const std::set<unsigned short>& knownIds) {
	static std::random_device rd;
	static std::mt19937_64 mt(rd());
	static std::uniform_int_distribution<unsigned short> dist(0, std::numeric_limits<unsigned short>::max());
	unsigned short id = dist(mt);
	return (knownIds.count(id)) ? id : getFreshId(knownIds);
}


/*
The PoliceOfficer Class: This class should simulate a police officer inspecting parked cars. The class’s responsibilities are:
– To know the police officer’s name and badge number
– To examine a ParkedCar object and a ParkingMeter object, and determine whether the car’s time has expired
– To issue a parking ticket (generate a ParkingTicket object) if the car’s time has expired
Write a program that demonstrates how these classes collaborate.
*/

