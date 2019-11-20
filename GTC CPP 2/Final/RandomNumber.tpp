#pragma once
#include <cmath>
#include <random>
#include <type_traits>
#include <exception>

/// sdsd
template <class T>
constexpr T randNum() {

	static_assert(std::is_arithmetic_v<T>, "[RandNum] This template only accepts arithmetic types (INT / REAL)"); // Make sure the type is Int/Real
	
	using dist_t = typename 
	std::conditional<
		std::is_integral_v<T>, 
			std::uniform_int_distribution<T>, // If integral, let it keep its type
			std::uniform_int_distribution<std::int64_t>
	>::type; // If floating, set to int_64
	
	using range_t = typename
	std::conditional<
		std::is_integral_v<T>,
			std::pair<T, T>,
			std::pair<std::int64_t, std::int64_t>
	>::type;

	static std::random_device rd; // Get a perfectly random seed for each type's engine
	static std::mt19937_64 mt(rd()); // Create a randomly seeded engine for each type

	range_t range; // Set the ceiling
	if constexpr(std::is_integral_v<T>) {
		range.second = std::numeric_limits<T>::max() - 1;
	} else {
		range.second = std::numeric_limits<std::int64_t>::max() - 1;
	}
	if constexpr (std::is_signed_v<T>) {
		range.first = -range.second;
	} else {
		range.first = 0;
	} 

	dist_t dist(range.first, range.second); // Mark the range for integrals

	if constexpr(std::is_integral_v<T>) { // Check if the type is of an integral
		return dist(mt);
	} else {
		dist_t precision_dist = (std::is_same_v<T, float>) ? dist_t(-9999999, 9999999) : dist_t(-999999999999999, 999999999999999); // Create a range based on the number of decimal places floats vs doubles have
		return ((T)dist(mt) + (T)((T)precision_dist(mt) / ((std::is_same_v<T, float>) ? 10000000.0f : 1000000000000000.0))); // use int distribution to create the significant and floating sections
	}
}

template <class T>
constexpr T randNum(const T user_min, const T user_max) {

	static_assert(std::is_arithmetic_v<T>, "[RandNum] This template only accepts arithmetic types (INT / REAL)"); // Make sure the type is Int/Real
	if (user_min > user_max) // Make sure the min is lower
		throw std::invalid_argument("[RandNum] Minimum is larger than maximum"); 
	else if (user_min == user_max) // Make sure the min is lower
		throw std::invalid_argument("[RandNum] Minimum is the same value as maximum");
	else if (user_min < static_cast<T>(std::numeric_limits<std::int64_t>::min())) // Make sure min and max aren't too big (memory wise)
		throw std::invalid_argument("[RandNum] Min is too small (x < int64_t::min)");
	else if (user_max > static_cast<T>(std::numeric_limits<std::int64_t>::max()))
		throw std::invalid_argument("[RandNum] Max is too big (x > int65_t::min)");

	using dist_t = typename
	std::conditional<
		std::is_integral_v<T>,
			std::uniform_int_distribution<T>, // If integral, let it keep its type
			std::uniform_real_distribution<T>
	>::type; // If floating, set to int_64

	static std::random_device rd; // Get a perfectly random seed for each type's engine
	static std::mt19937_64 mt(rd()); // Create a randomly seeded engine for each type

	
	dist_t dist(user_min, user_max); // Mark the range for integrals

	return dist(mt);
}


