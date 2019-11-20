#pragma once

class ParkingMeter
{
public:
	ParkingMeter() = default;
	ParkingMeter(double /*minutes*/);
	double getTime() const;
private:
	double time_paid;
};