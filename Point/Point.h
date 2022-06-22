#pragma once
#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const;//Некогда ничего не принимает!!!
	double get_y()const;
	void set_x(double x);
	void set_y(double y);


	double distance(Point other);

	void setPoint(double pt_x, double pt_y);

	void print()const;
	// Constructors:

	/*Point()
	{
		x = y = double();
		cout << "DefaultConstructor: \t" << this << endl;
	}*/



	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();
	// Operators

	Point& operator=(const Point& other);

};