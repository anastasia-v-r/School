#include "ParkingMeter.hpp"

ParkingMeter::ParkingMeter(double minutes) { 
	this->time_paid = minutes; 
};

double ParkingMeter::getTime() const { 
	return this->time_paid; 
};