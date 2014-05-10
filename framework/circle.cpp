#include "circle.hpp"
#include <cmath>

Circle::Circle():
	center_{0,0},
	radius_(1.0),
	color_{0} {} 


Circle::Circle(Point2d const& center, double radius, ColorRGB const& color):
	center_(center),
	radius_(radius),
	color_(color) {}

Circle::~Circle(){}


void Circle::center(Point2d const& center){
	center_ = center;
}

Point2d Circle::center() const {
	return center_;
}

void Circle::radius(double radius){
	if (radius<0) {radius=(-1)*radius;}
	radius_ = radius;
}

double Circle::radius(){
	if (radius_<0) {radius_=(-1)*radius_;}
	return radius_;
}

void Circle::color(ColorRGB const& color){
	color_=color;
}

ColorRGB Circle::color() const {
	return color_;
}

double Circle::circumference(){
	double u = 2 * M_PI * radius_;
	return u;
}

bool Circle::is_inside(Point2d p) const{
	if (sqrt(pow(p.x(),2)+pow(p.y(),2))<=radius_)
	{
		return true;
	}
	else
	{
		return false;
	}
}