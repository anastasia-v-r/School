#include "ParkingTicket.hpp"
#include <iostream>
#include <iomanip>
#include "ParkedCar.hpp"
#include "PoliceOfficer.hpp"
#include "ParkingMeter.hpp"

ParkingTicket::ParkingTicket(const ParkedCar& car, const PoliceOfficer& officer, const ParkingMeter& meter)
	: make{ car.getMake() }
	, model{ car.getModel() }
	, color{ car.getColor() }
	, plate{ car.getPlate() }
	, issuing_officer{ officer.getName() }
	, officer_badge{ officer.getBadge() } {
	double overtime = meter.getTime() - car.getTime();
	if (overtime > 0.0) {
		overtime -= 60.0;
		fine = 25.0;
		while (overtime > 0.0) {
			overtime -= 60.0;
			fine += 10.0;
		}
	} else {
		fine = 0.0;
	}
};

std::ostream& operator<<(std::ostream& strm, const ParkingTicket& obj) {
	strm << "=====================" << std::endl;
	strm << "=  PARKING  TICKET  =" << std::endl;
	strm << "= MAKE : " << std::setw(10) << obj.make << "=" << std::endl;
	strm << "= MODEL : " << std::setw(9) << obj.model << "=" << std::endl;
	strm << "= PLATE : " << std::setw(9) << obj.plate << "=" << std::endl;
	strm << "= COLOR : " << std::setw(9) << obj.color << "=" << std::endl;
	strm << "= OFFICER : " << std::setw(7) << obj.issuing_officer << "=" << std::endl;
	strm << "= OFFICER ID : " << std::setw(3) << obj.officer_badge << "=" << std::endl;
	strm << "=     FINE : $" << std::setw(5) << std::fixed << std::setprecision(2) << obj.fine << "=" << std::endl;
	strm << "=====================" << std::endl;
	return strm;
}

double ParkingTicket::getFine() const { 
	return this->fine; 
};

std::string ParkingTicket::getMake() const { 
	return this->make; 
};

std::string ParkingTicket::getModel() const { 
	return this->model;
};

std::string ParkingTicket::getColor() const { 
	return this->color; 
};

unsigned short ParkingTicket::getPlate() const {
	return this->plate; 
};

std::string ParkingTicket::getName() const { 
	return this->issuing_officer; 
};

unsigned short ParkingTicket::getBadge() const { 
	return this->officer_badge; 
};