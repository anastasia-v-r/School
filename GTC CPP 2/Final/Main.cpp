#include <iostream>
#include <map>
#include <vector>
#include "Funcs.hpp"
#include "RandomNumber.tpp"
#include "Input.tpp"
#include "PoliceOfficer.hpp"
#include "ParkedCar.hpp"
#include "ParkingTicket.hpp"

int main() {
	try {
		double city_revenue{ 0.0 };
		double max_time{ 180.0 };
		unsigned int parking_space{ 1u };
		 


		PoliceOfficer officer("Andrew");
		std::vector<std::pair<ParkingMeter, std::shared_ptr<ParkedCar>>> streetSide;
		streetSide.emplace_back(std::make_pair(ParkingMeter(Custom::randNum<double>(0.0, max_time)), std::make_shared<ParkedCar>(MAKE_MODEL::TOYOTA_CAMRY, COLOR::SILVER)));
		streetSide.emplace_back(std::make_pair(ParkingMeter(Custom::randNum<double>(0.0, max_time)), nullptr));
		streetSide.emplace_back(std::make_pair(ParkingMeter(Custom::randNum<double>(0.0, max_time)), std::make_shared<ParkedCar>(MAKE_MODEL::HONDA_ACCORD, COLOR::YELLOW)));
		streetSide.emplace_back(std::make_pair(ParkingMeter(Custom::randNum<double>(0.0, max_time)), std::make_shared<ParkedCar>(MAKE_MODEL::DODGE_CHARGER, COLOR::GREEN)));
		for (auto& parking_space : streetSide) {
			if (parking_space.second != nullptr) {
				parking_space.second->passTime(Custom::randNum<float>(0.0, max_time * 2.0));
				officer.examine(*parking_space.second, parking_space.first);
				for (const auto& ticket : parking_space.second->getTickets()) {
					std::cout << ticket << std::endl;
				}
			}
		}
	} catch (const std::exception& msg) {
		std::cout << "EXCEPTION EXCEPTION EXCEPTION EXCEPTION" << std::endl;
		std::cout << msg.what() << std::endl;
		std::cout << "EXCEPTION EXCEPTION EXCEPTION EXCEPTION" << std::endl;
	}
}
