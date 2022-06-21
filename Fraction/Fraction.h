#pragma once
#include <iostream>
#include <cstring>
using namespace std;

using std::string;
using std::cin;
using std::cout;
using std::endl;

class fraction;
fraction operator*(fraction left, fraction right);
fraction operator/(const fraction& left, const fraction& right);
fraction operator+(fraction left, fraction right);
fraction operator-(fraction left, fraction right);
std::ostream& operator<<(std::ostream& os, const fraction& obj);
std::istream& operator>>(std::istream& is, fraction& obj);

//Дробь
class fraction {
    int integer;
    int numerator;
    int denominator;

public:
    int get_integer()const;
    int get_numerator()const;
    int get_denominator()const;

    void set_numerator(int numerator);
    void set_integer(int integer);
    void set_denominator(int denominator);

    //Наибольший общий делитель
   //(англ.) Greatest Common Divisor
    int gcd(long a, long b);

    //Наименьшее общее кратное
  // (англ.) least common multiple
    int lcm(long a, long b);

    fraction& reduce();
    fraction();
    fraction(int integer);
    fraction(double value);
    fraction(int numerator, int denomenator);
    fraction(int integer, int numerator, int denominator);
    fraction(const fraction& other);
    ~fraction();

    //              Operators:
    fraction& operator=(const fraction& other);
    fraction operator*=(const fraction& other);
    fraction operator/=(const fraction& other);
    fraction operator+=(const fraction& other);
    fraction operator-=(const fraction& other);
    fraction& operator()(int integer, int numerator, int denominator);

    //          increment, Decrement

    fraction& operator++(); //Prefix increment
    fraction operator++(int); //Suffix increment
    fraction& operator--(); //Prefix increment-
    fraction operator--(int); //Suffix increment

    //      Type-cast operators;
    explicit operator int()const;
    explicit operator double()const;

    //      Metods
    fraction& to_improper();
    fraction& to_proper();
    fraction inverted()const;

    void print()const;
};