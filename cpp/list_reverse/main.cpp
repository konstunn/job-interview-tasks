
#include "list.hpp"
#include <iostream>
#include <string>

int main ()
{
	std::string str;
	std::getline (std::cin, str);

	List <int> list;

	do
	{
		size_t idx;

		// throws exception 
		// in case of empty string (and thus, empty list)
		int elem = std::stoi (str, & idx);

		list.push_back (elem);
		str = str.substr (idx);
	} 
	while (str != "");

	std::cout << "list == " << list << std::endl;
	std::cout << "list == " << list.reverse() << std::endl;

	return 0; 
}
