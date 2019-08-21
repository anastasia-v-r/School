#pragma once
#include <iostream>

bool isPrime(int num)
{
	bool prime = true;

	for (int count = 2; count < num; ++count)
	{
		//std::cout << "mod : " << (num % count) << "\n";
		//std::cout << count;
		if ((num % count) == 0)
		{
			prime = false;
			break;
		}
		else
		{
			prime = true;
		}
	}

	return prime;

}
