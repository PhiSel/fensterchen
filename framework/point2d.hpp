#ifndef BUW_POINT2D_HPP 
#define BUW_POINT2D_HPP

class Point2d
{
public:
	Point2d();						//Standardkonstruktor
	Point2d(double const& x, double const& y);	//Konstruktor
	~Point2d();						//Destruktor

	double x() const;		//Getter
	double y() const;		//Getter
	void translate(double const& x, double const& y);		//Setter
	void rotate(double const& r);		//Setter
	void rotate(Point2d const& Zentrum, double const& r);

private:
	double x_;
	double y_;
};



#endif