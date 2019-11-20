#include "PoliceOfficer.hpp"
#include "ParkedCar.hpp"
#include "ParkingMeter.hpp"
#include "RandomNumber.tpp"
#include <iostream>

std::set<unsigned short> PoliceOfficer::taken_ids;

unsigned short getFreshId(const std::set<unsigned short>& /* Known Ids */);

PoliceOfficer::PoliceOfficer(std::string name)
	: m_name{ name } 
	, m_id{ getFreshId(PoliceOfficer::taken_ids) } {
	std::cout << "assigning #" << this->m_id << " to " << m_name << std::endl;
	PoliceOfficer::taken_ids.emplace(this->m_id);
}

PoliceOfficer::~PoliceOfficer() {
	PoliceOfficer::taken_ids.erase(this->m_id);
}

void PoliceOfficer::examine(ParkedCar& car, const ParkingMeter& meter) {
	if (car.getTime() > meter.getTime()) {
		car.giveTicket(ParkingTicket(car, *this, meter));
	}
}

unsigned short getFreshId(const std::set<unsigned short>& knownIds) {
	auto id = randNum<unsigned short>();
	return (knownIds.count(id)) ? getFreshId(knownIds) : id;
}
