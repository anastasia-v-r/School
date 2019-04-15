#pragma once
#include <fstream>
#include <string>
#include "Player.h"

void pullAcc(std::ifstream&, std::vector<Player>&);
void makeAcc(std::string, std::vector<Player>&);
void updateAcc(std::string, std::vector<Player>);
