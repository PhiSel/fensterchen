#include "rectangle.hpp"
#include "fensterchen.hpp"

Rectangle::Rectangle():
	lowerleft_{0,0},
	width_(2),
	height_(3),
	color_{0} {}

Rectangle::Rectangle(Point2d const& lowerleft, double const width, double const height, ColorRGB const& color):
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

void Rectangle::width(double const width){
	width_ = width;
}

double Rectangle::width() const{
	return width_;
}

void Rectangle::height(double const height){
	height_ = height;
}

double Rectangle::height() const {
	return height_;
}

void Rectangle::color(ColorRGB const& color){
	color_ = color;
}

ColorRGB Rectangle::color() const {
	return color_;
}

double Rectangle::circumference() const{
	return 2 * width_ + 2 * height_;
}

void Rectangle::draw(Window const& win) const{
	win.drawLine(lowerleft_.x(), lowerleft_.y(), 
				 lowerleft_.x() + width_, lowerleft_.y(), color_.r_, color_.g_, color_.b_);
    win.drawLine(lowerleft_.x() + width_, lowerleft_.y(),
    		 	 lowerleft_.x() + width_, lowerleft_.y() + height_, color_.r_, color_.g_, color_.b_);
    win.drawLine(lowerleft_.x() + width_, lowerleft_.y() + height_, 
    			 lowerleft_.x(), lowerleft_.y() + height_, color_.r_, color_.g_, color_.b_);
    win.drawLine(lowerleft_.x(), lowerleft_.y() + height_, 
    			 lowerleft_.x(), lowerleft_.y(), color_.r_, color_.g_, color_.b_);
}

void Rectangle::draw(Window const& win, ColorRGB const& clr){
	win.drawLine(lowerleft_.x(), lowerleft_.y(), 
				 lowerleft_.x() + width_, lowerleft_.y(), clr.r_, clr.g_, clr.b_);
    win.drawLine(lowerleft_.x() + width_, lowerleft_.y(),
    			 lowerleft_.x() + width_, lowerleft_.y() + height_, clr.r_, clr.g_, clr.b_);
    win.drawLine(lowerleft_.x() + width_, lowerleft_.y() + height_, 
    			 lowerleft_.x(), lowerleft_.y() + height_, clr.r_, clr.g_, clr.b_);
    win.drawLine(lowerleft_.x(), lowerleft_.y() + height_, 
    			 lowerleft_.x(), lowerleft_.y(), clr.r_, clr.g_, clr.b_);
}

bool Rectangle::is_inside(Point2d const& p){
	return(p.x() >= lowerleft_.x() && p.x() <= lowerleft_.x() + width_ &&
	       p.y() >= lowerleft_.y() && p.y() <= lowerleft_.y() + height_);
}

void Rectangle::translate(double const x, double const y){
	lowerleft_.translate(x,y);
}