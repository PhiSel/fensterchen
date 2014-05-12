#ifndef BUW_CIRCLE_HPP 
#define BUW_CIRCLE_HPP
#include "point2d.hpp"
#include "colorrgb.hpp"
#include "fensterchen.hpp"
class Circle
{
public:
	Circle();
	Circle(Point2d const& center, double radius, ColorRGB const& color);
	~Circle();

	void center(Point2d const& center); //setter
	Point2d center() const;				//getter		

	void radius(double r);				//setter
	double radius();					//getter		

	void color(ColorRGB const& color);	//setter
	ColorRGB color() const;				//getter	

	double circumference();	

	void draw(Window &win);

	void draw(Window &win, ColorRGB clr);

	bool is_inside(Point2d p) const;

private:
	Point2d center_;
	double radius_;
	ColorRGB color_;

};

#endif