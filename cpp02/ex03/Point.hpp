#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <ostream>

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &);
	~Point();
	Fixed getX() const;
	Fixed getY() const;

private:
	const Fixed x_;
	const Fixed y_;
};

std::ostream &operator<<(std::ostream &o, const Point &rhs);

#endif//POINT_HPP
