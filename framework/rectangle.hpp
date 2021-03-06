#ifndef BUW_RECTANGLE_HPP
#define BUW_RECTANGLE_HPP 
#include "point2d.hpp"
#include "colorrgb.hpp"
#include "fensterchen.hpp"

class Rectangle
{
public:
	Rectangle();
	Rectangle(Point2d const& lowerleft, double const width, double const height, ColorRGB const& color);
	~Rectangle();

	void lowerleft(Point2d const& lowerleft);
	Point2d lowerleft() const;

	void width(double const width);
	double width() const;

	void height(double const height);
	double height() const;

	void color(ColorRGB const& color);
	ColorRGB color() const;

	double circumference() const;

	void draw(Window const& win) const;

	void draw(Window const& win, ColorRGB const& clr);

	bool is_inside(Point2d const& p);

	void translate(double const x, double const y);

private:
	Point2d lowerleft_;
	double width_;
	double height_;
	ColorRGB color_;
};

#endif