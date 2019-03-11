#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using std::cout;
using std::fstream;
using Vec2dChar = std::vector<std::vector<char>>;

bool processInput(fstream& inputFile, Vec2dChar& inputField, bool& success)
{
	unsigned int row, colom;
	char holder;

	while (inputFile >> row >> colom)
	{
		if (row == 0 && colom == 0)
		{
			success = true;
			cout << "\nEnd of Processing";
			return true;
			break;
		}

		if (row > 0 && colom < 101)
		{
			success = true;
			inputField.clear();
			inputField.resize(row, std::vector<char>(colom));
			for (int countOut = 0; countOut < row; countOut++)
			{
				for (int countIn = 0; countIn < colom; countIn++)
				{
					inputFile >> holder;
					inputField[countOut][countIn] = holder;
					//cout << inputField[countOut][countIn];
				}
				//cout << std::endl;
			}
			//cout << "\n";
			return false;
			break;
		}
		else
		{
			success = false;
			if (row < 0 && colom > 100)
			{
				cout << "Too few rows. Must be more than 1.\n";
				cout << "Too many columns. Must be less than 101.\n";

			}
			else if (row < 0)
			{
				cout << "Too few rows. Must be more than 1.\n";
			}
			else
			{
				cout << "Too many columns. Must be less than 101.\n";
			}
			return false;
			break;
		}
	}
}

char bombDetect(Vec2dChar inputField, Vec2dChar& outputField, int row, int colom)
{
	int bombs = 0;
	for (int countOut = row - 1; countOut <= row + 1; ++countOut)
	{
		for (int countIn = colom - 1; countIn <= colom + 1; ++countIn)
		{
			if ((countOut >= 0 && countIn >= 0) && (countOut < inputField.size()) && (countIn < inputField[countOut].size()))
			{
				if (inputField[countOut][countIn] == '*')
				{
					++bombs;
				}
			}
		}
	}
	return bombs;
}

void processOutput(fstream& outputFile, Vec2dChar& inputField, Vec2dChar& outputField)
{
	outputField.clear();
	outputField.resize(inputField.size(), std::vector<char>(inputField[0].size()));

	for (int countOut = 0; countOut < inputField.size(); countOut++)
	{
		for (int countIn = 0; countIn < inputField[countOut].size(); countIn++)
		{

			if (inputField[countOut][countIn] == '*')
			{
				outputField[countOut][countIn] = inputField[countOut][countIn];
			}
			else
			{
				outputField[countOut][countIn] = bombDetect(inputField, outputField, countOut, countIn) + 48;
			}
			std::cout << outputField[countOut][countIn];
		}
		cout << "\n";
	}
	cout << "\n";
}



//SEARCH : use N poisiton such as n[n][n] and check [n-1][n-1] (↑←), [n-1][n] (↑) so on and so forth.