#pragma once
#include <iostream>
#include <ctype.h>
#include<Windows.h>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);
std::istream& operator>>(std::istream& is, String& obj);
std::ostream& operator<<(std::ostream& os, const String& obj);
class String
{
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	/*void set_str(char* str)
	{
		this->str = str;
	}*/

	// Constructors:

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	void print()const;


	void to_lower()const;


	void to_upper()const;


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
	String& operator=(const String& other);
	String& operator+=(const String& other);
	char operator[](int i)const; //i -index
	char& operator[](int i); //i -index

};