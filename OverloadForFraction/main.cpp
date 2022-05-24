/*Программа для демонстрации сложения, вычитания и умножения двух дробей*/
#include <iostream>
using namespace std;

//Дробь
struct Drob {
    int a;
    int b;
    Drob(int a, int b);
    void NOD();
    void show();
};

//Конструктор
Drob::Drob(int a, int b) {
    this->a = a;
    this->b = b;
}

//Сокращение дробей
void Drob::NOD() {
    int a_a = a;
    int b_b = b;
    int buf;
    while (b_b != 0) {
        buf = b_b;
        b_b = a_a % b_b;
        a_a = buf;
    }
    a /= a_a;
    b /= a_a;
}

//Показать дробь на экране
void Drob::show() {
    int buf = a % b;
    if (!buf) cout << a / b << endl;
    else cout << a << "/" << b << endl;

}

//Структура с двумя дробями и операциями сложения, умножения, вычитания
struct addSubMultDrob {
    struct Drob ob1; //первая дробь
    struct Drob ob2; //вторая дробь
    addSubMultDrob(int a, int b, int a1, int b1) : ob1(a, b), ob2(a1, b1) {} //конструктор копирования
    friend Drob operator+(Drob ob1, Drob ob2); //функция-друг для перегрухки операции сложения
    friend Drob operator-(Drob ob1, Drob ob2); //функция-друг для перегрухки операции вычитания
    friend Drob operator*(Drob ob1, Drob ob2); //функция-друг для перегрухки операции умножения
    void show(); //вывести результат на экран
};

//перегрузка сложения
Drob operator+(Drob ob1, Drob ob2) {
    Drob temp(0, 0);
    temp.b = ob1.b * ob2.b;
    temp.a = (temp.b / ob1.b) * ob1.a + (temp.b / ob2.b) * ob2.a;
    return temp;
}

//перегрузка вычитания
Drob operator-(Drob ob1, Drob ob2) {
    Drob temp(0, 0);
    temp.b = ob1.b * ob2.b;
    temp.a = (temp.b / ob1.b) * ob1.a - (temp.b / ob2.b) * ob2.a;
    return temp;
}

//перегрузка умножения
Drob operator*(Drob ob1, Drob ob2) {
    Drob temp(0, 0);
    temp.a = ob1.a * ob2.a;
    temp.b = ob1.b * ob2.b;
    return temp;
}

//вывести дроби, с которыми проводим действия
void addSubMultDrob::show() {
    cout << "First drob " << ob1.a << "/" << ob1.b << endl;
    cout << "Second drob " << ob2.a << "/" << ob2.b << endl;
    cout << endl;
}


void main() {
    Drob ob(0, 0);
    addSubMultDrob ob2(5, 4, 3, 4); //заводим 2 дроби 5/4 и 3/4

    ob2.show();

    cout << "After sum ";

    ob = ob2.ob1 + ob2.ob2; //сложение
    ob.NOD();
    ob.show();

    cout << "After sub ";

    ob = ob2.ob1 - ob2.ob2; //вычитание
    ob.NOD();
    ob.show();

    cout << "After mul "; //умножение

    ob = ob2.ob1 * ob2.ob2;
    ob.NOD();
    ob.show();

}