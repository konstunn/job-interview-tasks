
#include "array.hpp"
#include <iostream>
#include <string>

/* usage example
input:
1 2 3
2

output:
1
*/

int main ()
{
	std::string str;
	std::getline (std::cin, str);
		
	Array <int> array;

	do
	{
		size_t idx;
		int elem = std::stoi (str, & idx);	
		array.push_back (elem);
		str = str.substr (idx);
	} 
	while (str != "");

	if (! array.isSorted()) 
	{
		std::cout << -1 << std::endl;
		return -1;
	}
		
	int key;
	std::cin >> key; 

	int index = array.binary_search (key);
	std::cout << index << std::endl;

	return 0; 
}
