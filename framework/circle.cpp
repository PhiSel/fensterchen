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
	Point2d ziel{center_.x(),center_.y()+radius_};
	double winkel = M_PI/36;
    while(winkel < 2*M_PI){
      auto start(ziel);
      ziel.rotate(center_, M_PI/36);
      win.drawLine(start.x(),start.y(),ziel.x(),ziel.y(),color_.r(),color_.g(),color_.b());
      
      winkel += M_PI/36;
    }
}

void Circle::draw(Window &win, ColorRGB clr){
	Point2d ziel{center_.x(),center_.y()+radius_};
	double winkel = M_PI/36;
    while(winkel < 2*M_PI){
      auto start(ziel);
      ziel.rotate(center_, M_PI/36);
      win.drawLine(start.x(),start.y(),ziel.x(),ziel.y(),clr.r(),clr.g(),clr.b());
      
      winkel += M_PI/36;
    }
}

bool Circle::is_inside(Point2d p) const{
	double diff_x = p.x()-center_.x();
	double diff_y = p.y()-center_.y();
	double distance = sqrt(pow(diff_x,2)+pow(diff_y,2));
	return distance < radius_;
}