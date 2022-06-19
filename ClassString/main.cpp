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
class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	/*void set_str(char* str)
	{
		this->str = str;
	}*/

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size]();
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}

	String(const String& other)
	{
		this->size = other.size;
		//Deep copy
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyComstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}

	void to_lower()const
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

	void to_upper()const
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
	String& operator=(const String& other)
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

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char operator[](int i)const //i -index
	{
		return str[i];
	}
	char& operator[](int i) //i -index
	{
		return str[i];
	}
};

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

//#define CONSTRACTORS_CHECK
//#define STRING_CONCATENATION
//#define KEYBOARD_INPUT_CHECK
void main()
{
#ifdef CONSTRACTORS_CHECK
	String str1;
	str1.print();

	String str2(44);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();
	cout << str3 << endl;

	String str4 = str3; //Copy constructor
	cout << str4 << endl;

	String str5;
	str5 = str4;
	cout << str5 << endl;

#endif // CONSTRACTORS_CHECK
#ifdef STRING_CONCATENATION
	String str1 = "Hello";
	String str2 = "World";
	//String str3 = str1 + str2;
	//cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;
#endif // STRING_CONCATENATION
#ifdef KEYBOARD_INPUT_CHECK
	//system("chcp 1251");
//system("cls");
	setlocale(LC_ALL, "");
	String str;
	cout << str << endl;
	cout << "Введите строку заглавными символами: "; cin >> str;
	str.print();
	str.to_lower();
	str.print();
	cout << "Введите строку прописными символами: "; cin >> str;
	str.to_upper();
	str.print();
#endif // KEYBOARD_INPUT_CHECK
	String str1; //Default constrictor
	str1.print();
	String str2(22);
	str2.print();
	String str3 = "Hello";
	str3.print();
	String str4();
	String str5{};
	str5.print();

}
