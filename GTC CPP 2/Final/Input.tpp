#pragma once
#include <string>
#include <type_traits>

namespace Custom {
	// Arithmetic Types
	template < typename T,
		std::enable_if_t<
		!std::is_same_v<T, char> && std::is_arithmetic_v<T>
	> * = nullptr>
		void input(T&) {

	}

	// Char Types
	template < typename T,
		std::enable_if_t<
		std::is_same_v<T, char>
	> * = nullptr>
		void input(T&) {

	}

	// Strings
	template < typename T,
		std::enable_if_t<
		std::is_convertible_v<T, std::string>
	> * = nullptr>
		void input(T&) {

	}
}