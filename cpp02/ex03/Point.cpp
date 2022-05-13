#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}

Point::Point(const Point &other) : x_(other.x_), y_(other.y_) {}

Point &Point::operator=(const Point &)
{
	// nothing has changed
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Point &rhs)
{
	o << "(" << rhs.getX() << ", " << rhs.getY() << ")";
	return (o);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return (x_);
}

Fixed Point::getY() const
{
	return (y_);
}
