#pragma once
#include <set>
#include <map>
#include <string>
#include "RandomNumber.tpp"


namespace Custom {
	unsigned short getFreshId(const std::set<unsigned short>& /* Known Ids */);
	unsigned short getFreshId(const std::map<unsigned short, std::string>& /* Known Ids */);
	
	std::string output(std::string /* message */);

}
