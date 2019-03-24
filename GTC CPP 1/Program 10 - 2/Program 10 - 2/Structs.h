#pragma once
#include <string>
// Usings
using str_t = std::string;
// Structs
struct speaker
{
	str_t name;
	str_t phone;
	str_t topic;
	float fee;
};
// Var Structs
speaker defSpkr = {
		"A name",
		"555-555-5555",
		"A topic",
		0
};