#include"Point.h"

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS-CHECK
//#define COPY_ASSIGMENT_1
#define COPY_ASSIGMENT_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	Point A;//Объявление переменной 'А' типа 'Point'
//Объявление объекта 'А' cnhernehs Point
	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A; //Создаём указатель на 'Point'
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	Point A, B;
	A.setPoint(2, 3);
	B.setPoint(7, 8);

	A.print();
	B.print();
	cout << "Расстояние между двумя точками: " << distance(A, B) << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
#endif // DISTANCE

#ifdef CONSTRUCTORS-CHECK
	Point A;
	A.print();

	Point B = 5;//Single-Argument constructor (Конструктор с одним параметром)
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTORS-CHECK
#ifdef COPY_ASSIGMENT_1
	Point A(2, 3);
	Point B = A;
	Point C;
	C = B;
#endif // COPY_ASSIGMENT_1

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << "\n------------------------\n" << endl;
	A = B = C = Point(2, 3);
	cout << "\n------------------------\n" << endl;
}