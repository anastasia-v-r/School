#pragma once
#include <set>
#include <map>
#include "RandomNumber.tpp"

unsigned short getFreshId(const std::set<unsigned short>& /* Known Ids */);
unsigned short getFreshId(const std::map<unsigned short, std::string>& /* Known Ids */);