#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "prime.h"

int main()
{
	std::ofstream primeList;
	bool prime;
	std::string path;

	primeList.open("allprimes.dat");

	primeList << "List of Primes between 1 - 100\n";
	std::cout << "List of Primes between 1 - 100\n";
	primeList << "---------------------------------\n";
	std::cout << "---------------------------------\n";


	for (int count = 1; count < 100; ++count)
	{
		prime = isPrime(count);
		if (prime == true)
		{
			primeList << "Prime : " << count << " \n";
			std::cout << "Prime : " << count << " \n";
		}
	}

	path = std::filesystem::current_path().string();
	std::cout << "Your primes file is located at the following location.\n" << path << "\n";

	primeList.close();

	std::cin.ignore(2);

}



/*Program 1:

A prime number is a number that is only evenly divisible by itself and 1.
For example, the number 5 is prime because it can only be evenly divided by 1 and 5.
The number 6, however, is not prime because it can be divided evenly by 1, 2, 3, and 6.

Write a function name isPrime , which takes an integer as an argument and returns true
if the argument is a prime number, or false otherwise. Use the isPrime function in a program
that stores a list of all the prime numbers from 1 through 100 in a file named allprimes.dat.

TIP: Recall that the % operator divides one number by another, and returns the remainder
of the division. In an expression such as num1 % num2 , the % operator will return 0 if
num1 is evenly divisible by num2 .*/