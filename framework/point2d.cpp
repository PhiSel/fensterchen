#include "point2d.hpp"
#include <cmath>

Point2d::Point2d(): 		//Standardkonstruktor
	x_(0),
	y_(0) {}

Point2d::Point2d(double const x, double const y):
	x_(x),
	y_(y) {}

Point2d::~Point2d(){}

double Point2d::x() const{
	return x_;
}

double Point2d::y() const{
	return y_;
}

void Point2d::translate(double const x, double const y){
	x_ += x;
	y_ += y;
}

void Point2d::rotate(double const r){ //Rotation im Ursprung
	double x = x_;
	double y = y_;
	x_ = x * cos(-r) - y * sin(-r);	//Berechnung durch die Drehmatrix
	y_ = x * sin(-r) + y * cos(-r);	
}

void Point2d::rotate(Point2d const& Zentrum, double const r){ //Rotation um ein beliebiges Zentrum
	double x = x_;
	double y = y_;
	x_ = Zentrum.x() + (x-Zentrum.x()) * cos(-r) - (y-Zentrum.y()) * sin(-r);
	y_ = Zentrum.y() + (x-Zentrum.x()) * sin(-r) + (y-Zentrum.y()) * cos(-r);
}
