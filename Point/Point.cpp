#include"Point.h"

double Point::get_x()const//Некогда ничего не принимает!!!
{
	return x;
}
double Point::get_y()const
{
	return y;
}
void Point::set_x(double x)
{
	this->x = x;
}
void Point::set_y(double y)
{
	this->y = y;
}


double Point::distance(Point other)
{
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);

	return distance;
}

void Point::setPoint(double pt_x, double pt_y)
{
	x = pt_x;
	y = pt_y;

}

void Point::print()const
{
	cout << "X = " << x << "\t" << "Y = " << y << endl;
}
// Constructors:

/*Point()
{
	x = y = double();
	cout << "DefaultConstructor: \t" << this << endl;
}*/



Point::Point(double x , double y )
{
	this->x = x;
	this->y = y;

}
Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyConstruction:\t" << this << endl;
}
Point::~Point()
{
	cout << "Destructor: \t\t" << this << endl;

}
// Operators

Point& Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssigment:\t\t" << this << endl;
	return *this;
}


double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}