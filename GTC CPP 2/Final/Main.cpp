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
		// Data
		double city_revenue{ 0.0 };
		double max_time{ 180.0 };
		unsigned int parking_spaces{ 1u };
		unsigned int parking_freq{ 50u };
		unsigned int passTime{ 1u };

		// Get officer name and create officer
		Custom::output("Please enter the name of the officer in the format of \"first last\"");
		PoliceOfficer officer(Custom::input<std::string>('\n'));
		
		// Get parking space amount
		Custom::output("Please enter the number of parking spaces that exist within the street [Max 1k]");
		parking_spaces = Custom::input<unsigned int>(1u, 1000u);

		// Get parking frequency
		Custom::output("Please enter the parking frequency [0-100] (not guaranteed)");
		parking_freq = Custom::input<unsigned int>(1u, 100u);

		// Setup random cars
		std::vector<std::pair<ParkingMeter, std::shared_ptr<ParkedCar>>> streetSide;
		for (int i = 0; i < parking_spaces; i++) {
			if (Custom::randNum<unsigned int>(0u, 100u) < parking_freq) {
				std::shared_ptr<ParkedCar> tempCar = std::make_shared<ParkedCar>(
					static_cast<MAKE_MODEL>(Custom::randNum<unsigned int>(0u, static_cast<unsigned int>(MAKE_MODEL::DODGE_CHARGER))),
					static_cast<COLOR>(Custom::randNum<unsigned int>(0u, static_cast<unsigned int>(COLOR::BLACK)))
				);
				streetSide.emplace_back(std::make_pair(ParkingMeter(Custom::randNum<double>(0.0, 180.0)), tempCar));
			} else {
				streetSide.emplace_back(std::make_pair(ParkingMeter(Custom::randNum<double>(0.0, 180.0)), nullptr));
			}
		}

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
