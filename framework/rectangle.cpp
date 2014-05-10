#include "rectangle.hpp"

Rectangle::Rectangle():
	lowerleft_{0,0},
	width_(2),
	height_(3),
	color_{0} {}

Rectangle::Rectangle(Point2d const& lowerleft, double const& width, double const& height, ColorRGB const& color):
	lowerleft_{lowerleft},
	width_(width),
	height_(height),
	color_{color} {}

Rectangle::~Rectangle(){}

void Rectangle::lowerleft(Point2d const& lowerleft){
	lowerleft_ = lowerleft;
}

Point2d Rectangle::lowerleft() const {
	return lowerleft_;
}

void Rectangle::width(double const& width){
	width_ = width;
}

double Rectangle::width() const{
	return width_;
}

void Rectangle::height(double const& height){
	height_ = height;
}

double Rectangle::height() const {
	return height_;
}

void Rectangle::color(ColorRGB const& color){
	color_=color;
}

ColorRGB Rectangle::color() const {
	return color_;
}

double Rectangle::circumference(){
	return 2*width_+2*height_;
}

bool Rectangle::is_inside(Point2d p) const{
	if (p.x()>=lowerleft_.x()&&p.x()<=lowerleft_.x()+width_&&
		p.y()>=lowerleft_.y()&&p.x()<=lowerleft_.y()+height_)
	{
		return true;
	}
	else
	{
		return false;
	}
}