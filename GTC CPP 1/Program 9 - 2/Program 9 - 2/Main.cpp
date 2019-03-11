#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	using std::cout;
	std::string posString;
	std::fstream inputFile("inputdata.dat", std::ios::in);
	std::fstream outputFile("outputdata.dat", std::ios::out | std::ios::app);
	unsigned int row, colom;
	char holder;

	if (inputFile)
	{
		cout << "File opened succesfully\n";
		while (inputFile >> row >> colom && (row && colom) != 0)
		{
			cout << "Rows : [" << row << "]\n";
			cout << "Rows : [" << colom << "]\n";

			if (row > 0 && colom < 101)
			{
				std::vector<std::vector<char>> inputField(row,
					std::vector<char>(colom));
				for (int countOut = 0; countOut < row; countOut++)
				{
					for (int countIn = 0; countIn < colom; countIn++)
					{
						inputFile >> holder;
						inputField[countOut][countIn] = holder;
						cout << inputField[countOut][countIn];
					}
					cout << std::endl;
				}
			}
			else
			{
				if (row < 0)
				{
					cout << "Too few rows. Must be more than 1.\n";
				}
				else
				{
					cout << "Too many columns. Must be less than 101.\n";
				}
			}
		}
	}
	else
	{
		cout << "Error opening file!\n";
	}

	std::cin.ignore();
	
}

//STEPS!!!!!!!!


//Pull in data
//SEARCH : use N poisiton such as n[n][n] and check [n-1][n-1] (↑←), [n-1][n] (↑) so on and so forth.
//Generate output
//Output
/*Program 2:

Have you ever played Minesweeper ? This cute little game comes with a certain operating 
system whose name we can’t remember.The goal of the game is to find where all the mines 
are located within a M × N field.

The game shows a number in a square which tells you how many mines there are adjacent to
that square.Each square has at most eight adjacent squares.The 4 × 4 field on the left
contains two mines, each represented by a “*” character.If we represent the same field 
by the hint numbers described above, we end up with the field on the right :

*...	*100
....	2210
.*..  	1*10
.... 	1110


Input(inputdata.dat file)

The input will consist of an arbitrary number of fields.The first line of each field
contains two integers n and m(0 < n, m ≤ 100) which stand for the number of lines and 
columns of the field, respectively.Each of the next n lines contains exactly m characters, 
representing the field.

	Safe squares are denoted by “.” and mine squares by “*, ” both without the quotes. The 
	first field line where n = m = 0 represents the end of input and should not be processed.

	Output(outputdata.dat file)

	For each field, print the message Field #x: on a line alone, where x stands for the 
	number of the field starting from 1. The next n lines should contain the field with
	the “.” characters replaced by the number of mines adjacent to that square.There must
	be an empty line between field outputs.

	Sample Input Data

	4 4 
	*...
	....
	.*..
	....

	3 5 
	**...
	.....
	.*...
	0 0   

	Sample Output

	Field #1:
	*100
	2210
	1*10
	1110

	Field #2:
	**100
	33200
	1*100
*/