#include "PoliceOfficer.hpp"
#include "ParkedCar.hpp"
#include "ParkingMeter.hpp"
#include "RandomNumber.tpp"
#include "Funcs.hpp"
#include <iostream>

std::map<unsigned short, std::string> PoliceOfficer::taken_ids;

PoliceOfficer::PoliceOfficer(std::string name)
	: m_name{ name } 
	, m_id{ Custom::getFreshId(PoliceOfficer::taken_ids) } {
	for (const auto& letter : this->m_name) {
		if (!std::isalpha(letter) && !std::isspace(letter)) {
			throw std::invalid_argument("Police officer names should not contain non letters/spaces!");
		}
	}
	Custom::output("assigning #" + std::to_string(this->m_id) + " to officer " + this->m_name);
	PoliceOfficer::taken_ids.insert({ this->m_id, this->m_name });
}

PoliceOfficer::~PoliceOfficer() {
	PoliceOfficer::taken_ids.erase(this->m_id);
}

double PoliceOfficer::examine(ParkedCar& car, const ParkingMeter& meter) {
	if (car.getTime() > meter.getTime()) {
		car.giveTicket(ParkingTicket(car, *this, meter));
		return car.getTickets().back().getFine();
	}
}
