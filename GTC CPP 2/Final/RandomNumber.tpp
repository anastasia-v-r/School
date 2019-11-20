#pragma once
#include <cmath>
#include <random>
#include <type_traits>

/// sdsd
template <class T>
constexpr T randNum() {

	static_assert(std::is_arithmetic_v<T>, "RandNum : This template only accepts arithmetic types (INT / REAL)"); // Make sure the type is Int/Real
	
	using dist_t = typename 
	std::conditional<
		std::is_integral_v<T>, 
			std::uniform_int_distribution<T>, // If integral, let it keep its type
			std::uniform_int_distribution<std::int64_t>>::type; // If floating, set to int_64
	using range_t = typename
	std::conditional<
		std::is_integral_v<T>,
			T,
			std::int64_t>::type;

	static std::random_device rd; // Get a perfectly random seed for each type's engine
	static std::mt19937_64 mt(rd()); // Create a randomly seeded engine for each type

	range_t max; // Set the ceiling
	if constexpr(std::is_integral_v<T>) {
		max = std::numeric_limits<T>::max() - 1;
	} else {
		max = std::numeric_limits<std::int64_t>::max() - 1;
	}

	range_t min; // Set the floor
	if constexpr (std::is_signed_v<T>) {
		min = -max;
	} else {
		min = 0;
	} 

	dist_t dist(min, max); // Mark the range for integrals

	if constexpr(std::is_integral_v<T>) { // Check if the type is of an integral
		return dist(mt);
	} else {
		dist_t precision_dist = (std::is_same_v<T, float>) ? dist_t(0, 9999999) : dist_t(0, 999999999999999); // Create a range based on the number of decimal places floats vs doubles have
		return ((T)dist(mt) + (T)((T)precision_dist(mt) / ((std::is_same_v<T, float>) ? 10000000.0f : 1000000000000000.0))); // use int distribution to create the significant and floating sections
	}
}

