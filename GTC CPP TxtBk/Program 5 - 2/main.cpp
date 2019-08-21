#include <iostream>
#include <iomanip>

int main()
{
	int count = 0;
	char ascii = 0;

	for (count = 0; count <= 127; count++)
	{
		ascii = count;
		int mod = count % 16;

		std::cout << ascii;
		std::cout << "(" << mod << ")";
			if ((count % 16) == 0)
			{
				std::cout << "\n";
			}
	}
	std::cin.ignore(2);
}