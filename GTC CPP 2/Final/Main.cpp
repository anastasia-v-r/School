#include <iostream>
#include <map>
#include <vector>
#include "RandomNumber.tpp"
#include "PoliceOfficer.hpp"
#include "ParkedCar.hpp"
#include "ParkingTicket.hpp"

int main() {
	try {
		double city_revenue{ 0.0 };
		double max_time{ 180.0 };
		PoliceOfficer officer("Andrew");
		std::vector<std::pair<ParkingMeter, ParkedCar>> streetSide{
			{ParkingMeter(randNum<double>(0.0, max_time)), ParkedCar(MAKE_MODEL::TOYOTA_CAMRY, COLOR::SILVER)},
			{ParkingMeter(randNum<double>(0.0, max_time)), ParkedCar(MAKE_MODEL::TOYOTA_COROLLA, COLOR::BLUE)},
			{ParkingMeter(randNum<double>(0.0, max_time)), ParkedCar(MAKE_MODEL::HONDA_ACCORD, COLOR::YELLOW)},
			{ParkingMeter(randNum<double>(0.0, max_time)), ParkedCar(MAKE_MODEL::DODGE_CHARGER, COLOR::GREEN)},
		};
		for (auto& parking_space : streetSide) {
			parking_space.second.passTime(randNum<float>(0.0, max_time * 2.0));
			officer.examine(parking_space.second, parking_space.first);
			for (const auto& ticket : parking_space.second.getTickets()) {
				std::cout << ticket << std::endl;
			}
		}
	} catch (const std::exception& msg) {
		std::cout << "EXCEPTION EXCEPTION EXCEPTION EXCEPTION" << std::endl;
		std::cout << msg.what() << std::endl;
		std::cout << "EXCEPTION EXCEPTION EXCEPTION EXCEPTION" << std::endl;
	}
}
