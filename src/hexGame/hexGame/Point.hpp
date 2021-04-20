
#ifndef POINT_HPP
#define POINT_HPP

#include "Color.hpp"
#include <iostream>
#include <string>

class Point {
	private :
		int x;
		int y;
		Color color;
		bool isChecked;
	
	public :
		Point(int, int, Color, bool);
		Point(int, int, Color);
		Point(int, int);
		Point(const Point &);
		~Point();
		int getX() const;
		int getY() const;
		Color getColor() const;
		void setIndexes(int, int);
		void setColor(Color);
		bool isCheck();

		Point & operator=(Point const &);
};

bool operator==(Point const &, Point const &);
bool operator !=(Point const &, Point const &);


#endif