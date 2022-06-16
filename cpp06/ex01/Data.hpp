#ifndef DATA_HPP
#define DATA_HPP

#include <ostream>
#include <stdint.h> // uintptr_t, and it's an optional type in C99
#include <string>

class Data
{
public:
	Data();
	Data(const Data &other);
	Data &operator=(const Data &rhs);
	~Data();

	const std::string &getData() const;
	int getI() const;

private:
	std::string data_;
	int i_;
};

std::ostream &operator<<(std::ostream &o, const Data &d);

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif // !DATA_HPP
