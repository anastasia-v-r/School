#include <iostream>
#include <vector>
#include "PersonData.hpp"
#include "CustomerData.hpp"

int main() {
	std::vector<CustomerData> customers;
	std::string LastName;
	std::string FirstName;
	std::string	Address;
	std::string	City;
	std::string	State;
	std::string	Zip;
	std::string	Phone;
	bool mail;
	int custAmount = 0;
	std::cout << "How many customers would you like to process : " << std::flush;
	std::cin >> custAmount;
	for (int i = 0; i < custAmount; i++) {
		std::cout << "Please enter your last name : " << std::flush;
		std::cin >> LastName;
		std::cout << "Please enter your first name : " << std::flush;
		std::cin >> FirstName;
		std::cout << "Please enter your address (555 Sesame Street) : " << std::flush;
		std::cin.ignore(1);
		std::getline(std::cin, Address);
		std::cout << "Please enter your city (Los Angelos) : " << std::flush;
		std::getline(std::cin, City);
		std::cout << "Please enter your state (NY)  : " << std::flush;
		std::cin >> State;
		std::cout << "Please enter your zip code (30043) : " << std::flush;
		std::cin >> Zip;
		std::cout << "Please enter your phone number (2415558946) : " << std::flush;
		std::cin >> Phone;
		std::cout << "Would you like to be on our mailing list (y/n) : " << std::flush;
		char mailC;
		std::cin >> mailC;
		mailC = std::tolower(mailC);
		mail = (mailC == 'y') ? true : false;
		customers.emplace_back(CustomerData(LastName, FirstName, Address, City, State, Zip, Phone, (i + 1), mail));
	}
	bool progress;
	char progC;
	std::cout << "Would you like to access any of the customers information :" << std::flush;
	std::cin >> progC;
	progC = std::tolower(progC);
	progress = (progC == 'y') ? true : false;
	std::cout.flush();
	int custchoice;
	while (progress) {
		std::cout << "Which customer would you like to access :" << std::flush;
		std::cin >> custchoice;
		custchoice--;
		std::cout.flush();
		std::cout << "What would you like to access (lastname/firstname/address/city/state/zip/phone/mail):" << std::flush;
		std::string option;
		std::cin >> option;
		for (auto& chara : option) {
			chara = std::tolower(chara);
		}
		std::cout.flush();
		std::cout << "And are we accessing or modifying (get/set):" << std::flush;
		std::string access;
		std::cin >> access;
		for (auto& chara : access) {
			chara = std::tolower(chara);
		}
		std::cout.flush();
		std::string sinput;
		bool binput;
		if (access == "set") {
			std::cout << "What value would you like to enter :";
			if (option == "mail") {
				std::cin.ignore();
				std::getline(std::cin, sinput);
				binput = (sinput == "true") ? true : false;
				std::cout << std::endl;
			} else {
				std::cin.ignore();
				std::getline(std::cin, sinput);
				std::cout << std::endl;
			}
		}
		std::cout.flush();
		if (option == "firstname") {
			if (access == "get") {
				std::cout << customers[custchoice].getFirstName();
			} else {
				customers[custchoice].setFirstName(sinput);
			}
		} else if (option == "lastname") {
			if (access == "get") {
				std::cout << customers[custchoice].getLastName();
			}
			else {
				customers[custchoice].setLastName(sinput);
			}
		} else if (option == "address") {
			if (access == "get") {
				std::cout << customers[custchoice].getAddress();
			}
			else {
				customers[custchoice].setAddress(sinput);
			}
		} else if (option == "city") {
			if (access == "get") {
				std::cout << customers[custchoice].getCity();
			}
			else {
				customers[custchoice].setCity(sinput);
			}
		} else if (option == "state") {
			if (access == "get") {
				std::cout << customers[custchoice].getState();
			}
			else {
				customers[custchoice].setState(sinput);
			}
		} else if (option == "zip") {
			if (access == "get") {
				std::cout << customers[custchoice].getZip();
			}
			else {
				customers[custchoice].setZip(sinput);
			}
		} else if (option == "phone") {
			if (access == "get") {
				std::cout << customers[custchoice].getPhone();
			}
			else {
				customers[custchoice].setPhone(sinput);
			}
		} else if (option == "mail") {
			if (access == "get") {
				std::cout << (customers[custchoice].getMailingList() ? "true" : "false");
			}
			else {
				customers[custchoice].setMailingList(binput);
			}
		}
		std::cout << std::endl;
		std::cout << "Go again :" << std::flush;
		std::cin >> progC;
		progC = std::tolower(progC);
		progress = (progC == 'y') ? true : false;
	}
	std::cout << std::endl;
	for (auto& customer : customers) {
		std::cout << "Customer [" << customer.getCustomerNumber() << "] " << customer.getLastName() << ", " << customer.getFirstName() << "\n";
		std::cout << "Address : " << customer.getAddress() << " " << customer.getCity() << ", " << customer.getState() << " " << customer.getZip() << "\n";
		std::cout << "Phone : " << customer.getPhone() << "\n";
		std::cout << "Mailing Status : " << (customer.getMailingList() ? "Active" : "Inactive") << "\n\n";
	}
	std::cout << "End of program" << std::endl;
	std::cin.ignore(10);
}