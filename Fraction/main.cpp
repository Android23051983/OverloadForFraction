#include <iostream>
#include<cmath>
using namespace std;

using std::string;
using std::cin;
using std::cout;
using std::endl;

class fraction;
fraction operator*(fraction left, fraction right);

//ִנמבü
class fraction {
    int integer;
    int numerator;
    int denominator;

public:
    int get_integer()
    {
        return integer;
    }
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
    void set_integer(int integer)
    {
        this->integer = integer;
    }
    void set_denominator(int denominator)
    {
        if (denominator == 0)denominator = 1;
        this->denominator = denominator;
    }


    fraction()
    {
        this->integer = 0;
        this->numerator = 0;
        this->denominator = 1;
        cout << "DefaultConstructor:\t" << this << endl;
    }
    fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;
        cout << "largConstructor:\t" << this << endl;
    }
    fraction(int numerator, int denomenator)
    {
        this->integer = 0;
        this->numerator = numerator;
        this->denominator = denomenator;
        cout << "Constructor:\t\t" << this << endl;
    }

    fraction(int integer, int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        this->set_denominator(denominator);
    }
    fraction(const fraction& other)
    {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        cout << "CopyConstructor:\t" << this << endl;

    } 
    ~fraction()
    {
        cout << "Destructor: \t\t" << this << endl;
    }


    fraction& operator=(const fraction& other)
    {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        cout << "CopyAssigment:\t\t" << this << endl;
        return *this;
    }
    fraction operator*=(const fraction& other)
    {
        return *this = *this * other;
    }

    //increment, Decrement

    fraction& operator++() //Prefix increment
    {
        integer++;
        return *this;
    }

    fraction operator++(int) //Suffix increment
    {
        fraction old = *this;
        integer++;
        return old;
    }

    // Metods
    fraction& to_improper() 
    {
        numerator += integer * denominator;
        integer = 0;
        return *this;
    }
    fraction& to_proper()
    {
        integer += numerator / denominator;
        numerator %= denominator;
        return *this;
    }

    fraction inverted()const
    {
        fraction inverted = *this;
        inverted.to_improper();
        int buffer = inverted.numerator;
        inverted.numerator = inverted.denominator;
        inverted.denominator = buffer;
        return inverted;
    }

    void print()const
    {
        if (integer)cout << integer;
        if (numerator)
        {
            if (integer)cout << "(";
            cout << numerator << "/" << denominator;
            if (integer)cout << ")";
        }
        if (!integer && !numerator)cout << 0;
        cout << endl;
    }
};
fraction operator*(fraction left, fraction right)
{
    left.to_improper();
    right.to_improper();
    return fraction
        (
    left.get_numerator() * right.get_numerator(),
    left.get_denominator() * right.get_denominator()
    ).to_proper();
}
fraction operator/(const fraction & left, const fraction& right)
{
    return left * right.inverted();
}


//#define CONSTRUCTORS_CHECK
    void main()
    {
        setlocale(LC_ALL, "RUSSIAN");
#ifdef CONSTRUCTORS_CHECK
        fraction A;
        A.print();

        fraction B = 5;
        B.print();

        fraction C(1, 2);
        C.print();

        fraction D(2, 3, 4);
        D.print();

        fraction E = D;
        E.print();

        fraction F;
        F = E;
        E.print();
#endif // CONSTRUCTORS_CHECK
        fraction A(2, 3, 4);
        A.print();
        /*A.to_imnroper();
        A.print();
        A.to_proper();
        A.print();*/
        fraction B(3, 4, 5);
        B.print();

        fraction C = A * B;
        C.print();

        (A / B).print();

        A *= B;
        A.print();

        for (double i = .75; i < 10; i++)
        {
            cout << i << "\t";
        }
        cout << endl;
        for (fraction i(1, 2); i.get_integer() < 10; i++)
        {
            i.print();
        }
    }
    




