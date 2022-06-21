#include"Fraction.h"

int fraction::get_integer()const
{
    return integer;
}
int fraction::get_numerator()const
{
    return numerator;
}

int fraction::get_denominator()const
{
    return denominator;
}

void fraction::set_numerator(int numerator)
{
    this->numerator = numerator;
}
void fraction::set_integer(int integer)
{
    this->integer = integer;
}
void fraction::set_denominator(int denominator)
{
    if (denominator == 0)denominator = 1;
    this->denominator = denominator;
}

//Наибольший общий делитель
 //(англ.) Greatest Common Divisor
int fraction::gcd(long a, long b) {
    a = abs(a), b = abs(b);
    while (a != b) {
        if (a > b)
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
int fraction::lcm(long a, long b) {
    int max = b;
    for (int i = max; i > 0; i++)
    {
        if ((i % a == 0) && (i % b == 0))
        {
            return i;
        }
    }
}

fraction& fraction::reduce() {
    int r = gcd(numerator, denominator);
    numerator /= r;
    denominator /= r;
    cout << "Reduce" << endl;
    return *this;
}


fraction::fraction()
{
    this->integer = 0;
    this->numerator = 0;
    this->denominator = 1;
    cout << "DefaultConstructor:\t" << this << endl;
}
fraction::fraction(int integer)
{
    this->integer = integer;
    this->numerator = 0;
    this->denominator = 1;
    cout << "largConstructor:\t" << this << endl;
}
fraction::fraction(double value)
{
    integer = value;
    value -= integer;
    denominator = 1e+9;
    numerator = value * denominator;
    cout << "DoubleConstructor:\t" << this << endl;
    reduce();
}
fraction::fraction(int numerator, int denomenator)
{
    this->integer = 0;
    this->numerator = numerator;
    this->set_denominator(denomenator);
    cout << "Constructor:\t\t" << this << endl;
}

fraction::fraction(int integer, int numerator, int denominator)
{
    this->integer = integer;
    this->numerator = numerator;
    this->set_denominator(denominator);
    cout << "Constructor:\t\t" << this << endl;
}
fraction::fraction(const fraction& other)
{
    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    cout << "CopyConstructor:\t" << this << endl;

}
fraction::~fraction()
{
    cout << "Destructor: \t\t" << this << endl;
}

//              Operators:
fraction& fraction::operator=(const fraction& other)
{
    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    cout << "CopyAssigment:\t\t" << this << endl;
    return *this;
}
fraction fraction::operator*=(const fraction& other)
{
    return *this = *this * other;
}

fraction fraction::operator/=(const fraction& other)
{
    return *this = *this / other;
}

fraction fraction::operator+=(const fraction& other)
{
    return *this = *this + other;
}

fraction fraction::operator-=(const fraction& other)
{
    return *this = *this - other;
}

fraction& fraction::operator()(int integer, int numerator, int denominator)
{
    set_integer(integer);
    set_numerator(numerator);
    set_denominator(denominator);
    return *this;
}

//          increment, Decrement

fraction& fraction::operator++() //Prefix increment
{
    integer++;
    return *this;
}

fraction fraction::operator++(int) //Suffix increment
{
    fraction old = *this;
    integer++;
    return old;
}

fraction& fraction::operator--() //Prefix increment
{
    integer--;
    return *this;
}

fraction fraction::operator--(int) //Suffix increment
{
    fraction old = *this;
    integer--;
    return old;
}

//      Type-cast operators;
fraction::operator int()const
{
    return this->integer;
}

fraction::operator double()const
{
    return integer + (double)numerator / denominator;
}

//      Metods
fraction& fraction::to_improper()
{
    numerator += integer * denominator;
    integer = 0;
    return *this;
}
fraction& fraction::to_proper()
{
    integer += numerator / denominator;
    numerator %= denominator;
    return *this;
}

fraction fraction::inverted()const
{
    fraction inverted = *this;
    inverted.to_improper();
    int buffer = inverted.numerator;
    inverted.numerator = inverted.denominator;
    inverted.denominator = buffer;
    return inverted;
}

void fraction::print()const
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
fraction operator/(const fraction& left, const fraction& right)
{
    return left * right.inverted();
}
//Рабочая
fraction operator+(fraction left, fraction right) {
    /*  int n = numerator * other.denominator + other.numerator * denominator;
      int d = denominator * other.denominator;
      numerator = n / gcd(n, d);
      denominator = d / gcd(n, d);
      cout << "Operatpr+:\t\t" << this << endl;*/
    left.to_improper();
    right.to_improper();
    return fraction
    (
        left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
        left.get_denominator() * right.get_denominator()
    ).to_proper();
}
//Рабочая
fraction operator-(fraction left, fraction right) {
    left.to_improper();
    right.to_improper();
    return fraction
    (
        left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
        left.get_denominator() * right.get_denominator()
    ).to_proper();
}
bool operator==(fraction left, fraction right) {

    left.to_improper();
    right.to_improper();
    /* if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
         return true;
     else
         return false;*/
         //return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
    return
        left.to_improper().get_numerator() * right.get_denominator() ==
        right.to_improper().get_numerator() * left.get_denominator();
}

bool operator!=(const fraction& left, const fraction& right)
{
    return !(left == right);
}

bool operator>(fraction left, fraction right)
{
    return
        left.to_improper().get_numerator() * right.get_denominator() >
        right.to_improper().get_numerator() * left.get_denominator();
}
bool operator<(fraction left, fraction right)
{
    return
        left.to_improper().get_numerator() * right.get_denominator() <
        right.to_improper().get_numerator() * left.get_denominator();
}

bool operator>=(const fraction& left, const fraction& right)
{
    //return left > right || left == right;
    return !(left < right);
}

bool operator<=(const fraction& left, const fraction& right)
{
    return left < right || left == right;
}

std::ostream& operator<<(std::ostream& os, const fraction& obj)
{
    if (obj.get_integer())os << obj.get_integer();
    if (obj.get_numerator())
    {
        if (obj.get_integer())os << "(";
        os << obj.get_numerator() << "/" << obj.get_denominator();
        if (obj.get_integer())os << ")";
    }
    if (!obj.get_integer() && !obj.get_numerator())os << 0;
    return os;
}
std::istream& operator>>(std::istream& is, fraction& obj)
{
    /*int integer, numerator, denominator;
    cin >> integer >> numerator >> denominator;
    obj(integer, numerator, denominator);*/
    const int SIZE = 256;
    char sz_buffer[SIZE] = {};//sz_ - String Zero
    //is >> sz_buffer;
    is.getline(sz_buffer, SIZE);
    char* sz_numbers[3] = {};
    char sz_delimiters[] = "() /.";
    //https://cplusplus.com/reference/cstring/
    //https://cplusplus.com/reference/cstring/strtok/
    int n = 0;//Индекс элемента в массиве с подстроками (токенами) sz_numbers
    for (char* pch = strtok(sz_buffer, sz_delimiters); pch; pch = strtok(NULL, sz_delimiters))
    {
        sz_numbers[n++] = pch;
    }
    //for (int i = 0; i < n; i++)cout << sz_numbers[i] << "\t"; cout << endl;
    obj = fraction();
    switch (n)
    {
        //atoi() - ASCII-string to int (функция преобразования строки в int)
    case 1: obj.set_integer(atoi(sz_numbers[0])); break;
    case 2:
        obj.set_numerator(atoi(sz_numbers[0]));
        obj.set_denominator(atoi(sz_numbers[1]));
        break;
    case 3:obj(atoi(sz_numbers[0]), atoi(sz_numbers[1]), atoi(sz_numbers[2]));
    }
    //for (int i = 0; i < n; i++)cout << sz_numbers[i] << "\t"; cout << endl;
    return is;
}