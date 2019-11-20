#include <iostream>
#include "RandomNumber.tpp"
#include "PoliceOfficer.hpp"
#include "ParkedCar.hpp"
#include "ParkingTicket.hpp"

int main() {
	PoliceOfficer officer("Andrew Barnes");
	ParkedCar myCar("Toyota", "Camry", "Silver", "CET8888");
	ParkingMeter meter(120.0);
	try {
		
	} catch (const std::exception& msg) {
		std::cout << msg.what() << std::endl;
	}
}

/*
Due Date: November 20.
Chapter 14: Programming Challenge no 14: Parking Ticket Simulator.
Prepare a presentation for your project.
Your program is going to be "Attacked" It must resist it.
Requirements: "All previous requirements"

Generalizations.
Take a look to a parking ticket and be creative.
More is comming.

Parking Ticket Simulator
For this assignment, you will design a set of classes that work together to simulate a police officer issuing a parking ticket. 
The classes you should design are:

The ParkedCar Class: This class should simulate a parked car. The class�s responsibilities are:
� To know the car�s make, model, color, license number, and the number of minutes that the car has been parked
The ParkingMeter Class: This class should simulate a parking meter. The class�s only responsibility is:
� To know the number of minutes of parking time that has been purchased

The ParkingTicket Class: This class should simulate a parking ticket. The class�s responsibilities are:
� To report the make, model, color, and license number of the illegally parked car
� To report the amount of the fine, which is $25 for the first hour or part of an hour that the car is illegally parked, plus $10
for every additional hour or part of an hour that the car is illegally parked
� To report the name and badge number of the police officer issuing the ticket

The PoliceOfficer Class: This class should simulate a police officer inspecting parked cars. The class�s responsibilities are:
� To know the police officer�s name and badge number
� To examine a ParkedCar object and a ParkingMeter object, and determine whether the car�s time has expired
� To issue a parking ticket (generate a ParkingTicket object) if the car�s time has expired
Write a program that demonstrates how these classes collaborate.
*/