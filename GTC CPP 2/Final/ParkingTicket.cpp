#include "ParkingTicket.hpp"
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
