#include "point2d.hpp"
#include <cmath>

Point2d::Point2d(): 		//Standardkonstruktor
	x_(0),
	y_(0) {}

Point2d::Point2d(double const& x, double const& y):
	x_(x),
	y_(y) {}

Point2d::~Point2d(){}

double Point2d::x() const{
	return x_;
}

double Point2d::y() const{
	return y_;
}

void Point2d::translate(double const& x, double const& y){
	x_ += x;
	y_ += y;
}

void Point2d::rotate(double const& r){
	double x = x_;
	double y = y_;
	x_=x*cos(-r)-y*sin(-r);	//Berechnung durch die Drehmatrix
	y_=x*sin(-r)+y*cos(-r);	
}


