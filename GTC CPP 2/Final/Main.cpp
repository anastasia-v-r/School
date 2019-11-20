#include <iostream>
#include <map>
#include "RandomNumber.tpp"
#include "PoliceOfficer.hpp"
#include "ParkedCar.hpp"
#include "ParkingTicket.hpp"

int main() {
	try {
		std::map<ParkingMeter, ParkedCar> streetSide;
		double city_revenue{ 0.0 };
		PoliceOfficer officer("Andrew Barnes");
		ParkedCar myCar("Toyota", "Camry", "Silver");
		ParkingMeter meter(120.0);
	} catch (const std::exception& msg) {
		std::cout << msg.what() << std::endl;
	}
}
