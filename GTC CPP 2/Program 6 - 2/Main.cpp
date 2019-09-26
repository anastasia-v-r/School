#include "PreferredCustomer.hpp"
#include <iostream>

int main() {
	PreferredCustomer Jane;
	std::cout << "Jane has purchased $" << Jane.getPurchasesAmount() << " in goods.\n";
	std::cout << "Please enter their purchases, enter 0 to stop adding purchases" << std::endl;
	int purchase = 1;
	while (purchase > 0) {
		std::cout << "Purchase amount : ";
		std::cout.flush();
		std::cin >> purchase;
		Jane.setPurchasesAmount(Jane.getPurchasesAmount() + purchase);
	}
	if (Jane.getPurchasesAmount() < 500) {
		Jane.setDiscountLevel(.00);
	} else if (Jane.getPurchasesAmount() >= 500 && Jane.getPurchasesAmount() < 1000) {
		Jane.setDiscountLevel(.05);
	} else if (Jane.getPurchasesAmount() >= 1000 && Jane.getPurchasesAmount() < 1500) {
		Jane.setDiscountLevel(.06);
	} else if (Jane.getPurchasesAmount() > 0 && Jane.getPurchasesAmount() < 2000) {
		Jane.setDiscountLevel(.07);
	} else {
		Jane.setDiscountLevel(.10);
	}
	std::cout << "Customer " << Jane.getLastName() << ", " << Jane.getFirstName() << "\n";
	std::cout << "Address : " << Jane.getAddress() << " " << Jane.getCity() << ", " << Jane.getState() << " " << Jane.getZip() << "\n";
	std::cout << "Phone : " << Jane.getPhone() << "\n";
	std::cout << "Mailing Status : " << (Jane.getMailingList() ? "Active" : "Inactive") << "\n";
	std::cout << "Purchase Amount total : $" << Jane.getPurchasesAmount() << "\n";
	std::cout << "Discount Percentage : %" << Jane.getDiscountLevel() << "\n";
	std::cout.flush();
	std::cin.ignore(1);
}
