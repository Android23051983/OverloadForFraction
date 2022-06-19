#include"String.h"



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
	String str6 = str3;
	str6.print();

}
