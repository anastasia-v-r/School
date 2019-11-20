#pragma once
#include <string>

class ParkedCar
{
public:
	// Constructors
	ParkedCar() = delete;
	inline ParkedCar(std::string make, std::string model, std::string color, std::string plate)
		: make{make}
		, model{model}
		, color{color}
		, plate{plate}
	{};
	// Processors
	inline void passTime(double minutes) { time_parked += minutes; };
	// Getters
	inline std::string getMake() const { return this->make; };
	inline std::string getModel() const { return this->model; };
	inline std::string getColor() const { return this->color; };
	inline std::string getPlate() const { return this->plate;} ;
private:
	std::string make;
	std::string model;
	std::string color;
	std::string plate;
	double time_parked;
};
