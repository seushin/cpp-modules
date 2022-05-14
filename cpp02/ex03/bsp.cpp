#include "bsp.hpp"
#include "Fixed.hpp"

static bool isNeg(const Fixed &a)
{
	return (a < Fixed(0));
}

/*
 * ref: https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
 * `p = p0 + (p1 - p0) * s + (p2 - p0) * t`
 * if Point p is inside the triangle, then true that 0 <= s <= 1 && 0 <= t <= 1 && s + t <= 1
 * s, t and 1 - s - t are called the barycentric coordinates of the point p.
 *
 * s = 1/(2*Area)*(p0y*p2x - p0x*p2y + (p2y - p0y)*px + (p0x - p2x)*py);
 * t = 1/(2*Area)*(p0x*p1y - p0y*p1x + (p0y - p1y)*px + (p1x - p0x)*py);
 * Area = 0.5 *(-p1y*p2x + p0y*(-p1x + p2x) + p0x*(p1y - p2y) + p1x*p2y);
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area, s, t;
	Fixed px = point.getX(), py = point.getY(),
		  p0x = a.getX(), p0y = a.getY(),
		  p1x = b.getX(), p1y = b.getY(),
		  p2x = c.getX(), p2y = c.getY();

	area = Fixed(0.5f) *
		   ((Fixed(-1) * p1y * p2x) + p0y * (Fixed(-1) * p1x + p2x) + p0x * (p1y - p2y) + p1x * p2y);
	s = Fixed(1) / (Fixed(2) * area) * (p0y * p2x - p0x * p2y + (p2y - p0y) * px + (p0x - p2x) * py);
	t = Fixed(1) / (Fixed(2) * area) * (p0x * p1y - p0y * p1x + (p0y - p1y) * px + (p1x - p0x) * py);

	if (isNeg(s) || isNeg(t) || isNeg(Fixed(1) - s - t))
		return (false);
	return (true);
}
