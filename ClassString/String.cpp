#include"String.h"
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
/*void set_str(char* str)
{
	this->str = str;
}*/

String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size]();
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}

String::String(const String& other) :String(other.str)
{
	//this->size = other.size;
	//Deep copy
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyComstructor:\t" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

void String::to_lower()const
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		//if (str[i] >= 'A' && str[i] <= 'Z')    //проверка заглавных букв
		//	str[i] = str[i] + 32;         //преобразование верхнего регистра в нижний регистр
		//if (str[i] >= 'А' && str[i] <= 'Я')    //проверка заглавных букв
		//	str[i] = str[i] + 32;
		str[i] = tolower(str[i]);
	}
}

void String::to_upper()const
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		//if (str[i] >= 'a' && str[i] <= 'z')   //проверка строчных букв
		//	str[i] = str[i] - 32;        //преобразование нижнего регистра в верхний регистр  
		//if (str[i] >= 'а' && str[i] <= 'я')   //проверка строчных букв
		//	str[i] = str[i] - 32;
		str[i] = toupper(str[i]);
	}
}

/*bool is_palindrome(const String& obj)
{
int temp;
tenp

	do
	{
		last_number = 10 * last_number + number % 10;
		number /= 10;
	} while (number != 0);

	if (temp == last_number)
	{
		return true;
	}
	else
	{
		return false;
	}
}*/



//   Operators
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	//CopyAssigment так же выполняет Deep copy
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

char String::operator[](int i)const //i -index
{
	return str[i];
}
char& String::operator[](int i) //i -index
{
	return str[i];
}

String operator+(const String& left, const String& right)
{
	//Конкатенация строк
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

std::istream& operator>>(std::istream& is, String& obj)
{
	const int SIZE = 8192;
	char sz_buffer[SIZE] = {};
	//is.getline(sz_buffer, SIZE);// Взятие всех слов
	is >> sz_buffer;//Взятие слова до пробела
	obj = sz_buffer;
	return is;
}