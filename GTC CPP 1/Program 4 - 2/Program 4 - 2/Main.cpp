#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main()
{
	using std::cout, std::cin, std::string;

	int sales[5];
	string results[5];
	string path;

	std::ifstream salFile;
	std::ofstream resFile;

	
	path = std::filesystem::current_path().string();
	//cout << path; // For debugging file errors.

	cout << path << "\n";
	salFile.open("sales.txt");
	for (int count = 0; count < 5; ++count)
	{	
		salFile >> sales[count];
		int temp = sales[count];
		sales[count] = temp /= 100;
		int maxCount = sales[count];
		for (int nesCount = 1; nesCount <= maxCount; ++nesCount)
		{
			results[count] = results[count] + "*";
		}
		//cout << sales[count] << "---" << count << "\n" << results[count] << "\n"; //For Debugging
	}
	salFile.close();

	resFile.open("results.txt");
	resFile << "[Sales Bar Chart]\n" << "(Each * = $100)\n";
	cout << "[Sales Bar Chart]\n" << "(Each * = $100)\n"; //For Debugging
	for (int count = 0; count < 5; ++count)
	{
		
		resFile << "Store " << count + 1 << " : " << results[count] << "\n";
		cout << "Store " << count + 1 << " : " << results[count] << "\n"; //For Debugging
	}
	
	resFile.close();

	std::cin.ignore(2);
}






//Write a program that reads a data file named sales.dat.The program should then display a bar
//graph comparing each store’s sales and also output the sales bar graph to a file names results.dat.Create
//each bar in the bar graph by displaying a row of asterisks.Each asterisk should represent $100 of sales.
//
//
//Here is an example of the program’s input file sales.dat:
//
//1000
//1200
//1800
//800
//1900
//
//Here is an example of the program’s output on the screen and in the file results.dat:
//
//SALES BAR CHART
//(Each * = $100)
//Store 1 : **********
//Store 2 : ************
//Store 3 : ******************
//Store 4 : ********
//Store 5 : *******************