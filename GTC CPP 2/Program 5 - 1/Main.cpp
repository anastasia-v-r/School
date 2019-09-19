#include "Month.hpp"
#include <iostream>

int main() {
	Month m_month;
	Month temp;
	std::cout << "Default Init\n" << m_month;
	m_month = Month("mArCh");
	std::cout << "String Init\n" << m_month;
	m_month = Month(7);
	std::cout << "Int Init\n" << m_month;
	temp = m_month++;
	std::cout << "Postfix ++\n" << temp << m_month;
	std::cout << "Prefix ++\n" << ++m_month;
	temp = m_month--;
	std::cout << "Postfix --\n" << temp << m_month;
	std::cout << "Prefix --\n" << --m_month;
	std::cin >> m_month;
	std::cout << "String >> Init\n" << m_month;
	std::cin >> m_month;
	std::cout << "Int >> Init\n" << m_month;
	system("pause");
	return 0;
}