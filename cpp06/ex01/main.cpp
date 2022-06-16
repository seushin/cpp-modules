#include "Data.hpp"
#include <iostream>

int main()
{
	Data d;
	Data *dptr;
	uintptr_t tmp;

	tmp = serialize(&d);
	dptr = deserialize(tmp);

	std::cout << "original data: " << d << std::endl;
	std::cout << "deserialized data: " << *dptr << std::endl;

	std::cout << "data pointer: " << &d << std::endl;
	std::cout << "deserialized pointer: " << dptr << std::endl;

	return (0);
}
