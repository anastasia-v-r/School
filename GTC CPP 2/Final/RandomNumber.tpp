#pragma once
#include <random>

template <class T>
T randInt() {
	static std::random_device rd;
	static std::mt19937_64 mt(rd());
	static std::uniform_int_distribution<T> dist(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
	return dist(mt);
}

template <class T>
T randReal() {
	static std::random_device rd;
	static std::mt19937_64 mt(rd());
	static std::uniform_real_distribution<T> dist(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
	return dist(mt);
}