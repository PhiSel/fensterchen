#include "circle.hpp"
#include "point2d.hpp"
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

void Circle::draw(Window &win){
	Point2d ziel = Point2d(center().x(),center().y()+radius());
	double winkel = M_PI/36;
    while(winkel < 2*M_PI){
      auto start(ziel);
      ziel.rotate(center(), M_PI/36);
      win.drawLine(start.x(),start.y(),ziel.x(),ziel.y(),color().r(),color().g(),color().b());
      
      winkel += M_PI/36;
    }
}

void Circle::draw(Window &win, ColorRGB clr){
	Point2d ziel = Point2d(center().x(),center().y()+radius());
	double winkel = M_PI/36;
    while(winkel < 2*M_PI){
      auto start(ziel);
      ziel.rotate(center(), M_PI/36);
      win.drawLine(start.x(),start.y(),ziel.x(),ziel.y(),clr.r(),clr.g(),clr.b());
      
      winkel += M_PI/36;
    }
}

bool Circle::is_inside(Point2d p) const{
	if (center().x()+radius_>=p.x() && center().x()-radius_<=p.x() && (center().y()+radius_>=p.y()) && (center().y()-radius_<=p.y()))
	{
		return true;
	}
	else
	{
		return false;
	}
}