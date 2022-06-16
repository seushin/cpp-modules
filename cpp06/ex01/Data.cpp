#include "Data.hpp"

Data::Data() : data_("data"), i_(42) {}

Data::Data(const Data &other) : data_(other.data_), i_(other.i_) {}

Data &Data::operator=(const Data &rhs)
{
	data_ = rhs.data_;
	i_ = rhs.i_;
	return (*this);
}

Data::~Data() {}

const std::string &Data::getData() const
{
	return (data_);
}

int Data::getI() const
{
	return (i_);
}

std::ostream &operator<<(std::ostream &o, const Data &d)
{
	o << "data is [" << d.getData() << ", " << d.getI() << "]";
	return (o);
}

uintptr_t serialize(Data *ptr)
{
	uintptr_t res;

	res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}

Data *deserialize(uintptr_t raw)
{
	Data *res;

	res = reinterpret_cast<Data *>(raw);
	return (res);
}
