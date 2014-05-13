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
	double radius() const;					//getter		

	void color(ColorRGB const& color);	//setter
	ColorRGB color() const;				//getter	

	double circumference();	

	void draw(Window const& win) const;

	void draw(Window const& win, ColorRGB const& clr);

	bool is_inside(Point2d const& p);

private:
	Point2d center_;
	double radius_;
	ColorRGB color_;

};

#endif