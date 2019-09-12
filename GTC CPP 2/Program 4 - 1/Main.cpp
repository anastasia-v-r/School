#include <iostream>
#include <iomanip>
#include <vector>
#include "Name.hpp"
#include "Patient.hpp"
#include "Procedure.hpp"

int main() {
	Patient vPatient(Name{ "Jimmy", "Fairwright", "Don" }, "2852 Crabapple Lane", "Dacula", "Georgia", 30019, 4045558282, Name{ "Donna", "Fairwright", "Baxton" }, 4046668787);
	std::vector<Procedure> Procedures { 
		{"Physical Exam", "Sep 11, 2019", "Dr. Irvine", 250.00 }, 
		{"X-Ray", "Sep 11, 2019", "Dr. Jamison", 500.00}, 
		{"Blood Test", "Sep 11, 2019", "Dr. Smith", 200.00} 
	};
	std::cout << "--------------------------------------------------------------\n";
	std::cout << "| Patient Name : " << vPatient.getFullName().firstName << " " << vPatient.getFullName().middleName << " " << vPatient.getFullName().lastName << "                        |\n";
	std::cout << "| Patient Address : " << vPatient.getStreet() << " " << vPatient.getCity() << ", " << vPatient.getState() << " " << vPatient.getZip() << "|\n";
	std::cout << "| Patient Phone Number : " << std::fixed << std::setprecision(0) << vPatient.getPhone() << "                          |\n";
	std::cout << "| Emergency Contact Name : " << vPatient.getContactName().firstName << " " << vPatient.getContactName().middleName << " " << vPatient.getContactName().lastName << "           |\n";
	std::cout << "| Emergency Contact Phone Number : " << std::fixed << std::setprecision(0) << vPatient.getContactNumber() << "                |\n";
	std::cout << "+------------------------------------------------------------+\n";
	for (int i = 0; i < 3; i++) {
		std::cout << "|"  << "Procedure " << (i + 1) << "                                                 |\n";
		std::cout << "|" << std::setw(20) <<"Procedure Name : " << std::setw(20) << Procedures[i].getProcedureName() << "                    |\n";
		std::cout << "|" << std::setw(20) <<"Date : " << std::setw(20) << Procedures[i].getDate() << "                    |\n";
		std::cout << "|" << std::setw(20) <<"Practitioner : " << std::setw(20) << Procedures[i].getPractitionerName() << "                    |\n";
		std::cout << "|" << std::setw(20) <<"Charge : " << std::setw(20) << Procedures[i].getCost() << "                    |\n";
		if (i < 2)
			std::cout << "+------------------------------------------------------------+\n";
		else
			std::cout << "--------------------------------------------------------------\n";
	}
	std::cin.ignore(1);
}