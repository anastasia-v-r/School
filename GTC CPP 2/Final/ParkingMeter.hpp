#pragma once

class ParkingMeter
{
public:
	inline ParkingMeter(double minutes) { time_remaining = minutes; };
	inline bool passTime(double time) { time_remaining -= time; return (time_remaining < 0); };
private:
	double time_remaining;
};