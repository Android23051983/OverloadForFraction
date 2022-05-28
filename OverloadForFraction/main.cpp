/*Программа для демонстрации сложения, вычитания и умножения двух дробей*/
#include <iostream>
#include<cmath>
using namespace std;

using std::string;
using std::cin;
using std::cout;
using std::endl;

//Дробь
class fraction {
   int numerator;
   int denominator;

public:
    int get_numerator()const
    {
        return numerator;
    }

    int get_denominator()const
    {
        return denominator;
    }

    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }
    void set_denominator(int denominator)
    {
        this->denominator = denominator;
    }

    //Наибольший общий делитель
    //(англ.) Greatest Common Divisor
    int gcd(long a, long b) {
        a = abs(a), b = abs(b);
        while (a != b) {
            if (a>b)
            {
            long temp = a;
            a = b;
            b = temp;
            }
            b = b - a;
        }
        return a;
    }


    //Наименьшее общее кратное
    // (англ.) least common multiple
    int lcm(long a, long b) {
        int max = b;
        for (int i = max; i > 0; i++)
        {
            if ((i % a == 0) && (i % b == 0))
            {
            return i;
            }
        }
    }

    fraction& reduce() {
        int r = gcd(numerator, denominator);
        numerator /= r;
        denominator /= r;
        cout << "Reduce" << endl;
        return *this;
    }

    fraction(long numerator = 1, long denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    ~fraction()
    {
        cout << "Distructor: \t\t" << this << endl;
    }

    //Рабочая 
    fraction& operator*(const fraction& f) {
        numerator *= f.numerator;
        denominator *= f.denominator;
        cout << "Operator*:\t" << this << endl;
        return *this;
    }

    //Рабочая
    fraction& operator/(const fraction& f) {
        numerator *= f.denominator;
        denominator *= f.numerator;
        cout << "Operator\\:\t" << this << endl;
        return *this;
    }

    //Рабочая
    fraction& operator-(const fraction& f) {
        int n = numerator * f.denominator - f.numerator * denominator;
        int d = denominator * f.denominator;
        numerator = n / gcd(n, d);
        denominator = d / gcd(n, d);
        cout << "Operator-:\t" << this << endl;
        return *this;
    }

    //Рабочая
    fraction& operator+(const fraction& f) {
        long n = numerator * f.denominator + f.numerator * denominator;
        long d = denominator * f.denominator;
        numerator = n / gcd(n, d);
        denominator = d / gcd(n, d);
        cout << "Operatpr+:\t\t" << this << endl;
        return *this;
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }
    
};




void main() 
{
    setlocale(LC_ALL, "RUSSIAN");
    fraction C;
    C.print();
    cout << "------------------------------------------------------\n";
    fraction A(2, 10);
    A.print();
    cout << "------------------------------------------------------\n";
    fraction B(5, 7);
    B.print();
    cout << "------------------------------------------------------\n";
    C = A.operator-(B);
    C.reduce();
    C.print();
}