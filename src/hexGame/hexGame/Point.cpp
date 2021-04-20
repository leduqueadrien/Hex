
#include "Point.hpp"
#include "Color.hpp"

Point::Point(int _x, int _y, Color _color, bool _isChecked) : x(_x), y(_y), color(_color), isChecked(_isChecked) {}

Point::Point(int _x, int _y, Color _color) : Point(_x, _y, _color, false) {}

Point::Point(int _x, int _y) : Point(_x, _y, Color::Undefined, false) {}

Point::Point(Point const & p ) : Point(p.x, p.y, p.color, p.isChecked) {}

Point::~Point() {}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

Color Point::getColor() const {
	return color;
}

void Point::setIndexes(int newx, int newy) {
	x = newx;
	y = newy;
}

void Point::setColor(Color newColor) {
	color = newColor;
}

bool Point::isCheck() {
	return isChecked;
}


Point & Point::operator=(Point const & p) {
	if (this != &p) {
		x = p.x;
		y = p.y;
		color = p.color;
		isChecked = p.isChecked;
	}
	return *this;
}




bool operator==(Point const & p1, Point const & p2) {
	return P1.getX() == p2.getY();
}

bool operator !=(Point const & p1, Point const & p2) {
	return P1.getX() != p2.getY();
}
