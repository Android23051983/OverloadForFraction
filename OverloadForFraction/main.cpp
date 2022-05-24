/*��������� ��� ������������ ��������, ��������� � ��������� ���� ������*/
#include <iostream>
using namespace std;

//�����
struct Drob {
    int a;
    int b;
    Drob(int a, int b);
    void NOD();
    void show();
};

//�����������
Drob::Drob(int a, int b) {
    this->a = a;
    this->b = b;
}

//���������� ������
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

//�������� ����� �� ������
void Drob::show() {
    int buf = a % b;
    if (!buf) cout << a / b << endl;
    else cout << a << "/" << b << endl;

}

//��������� � ����� ������� � ���������� ��������, ���������, ���������
struct addSubMultDrob {
    struct Drob ob1; //������ �����
    struct Drob ob2; //������ �����
    addSubMultDrob(int a, int b, int a1, int b1) : ob1(a, b), ob2(a1, b1) {} //����������� �����������
    friend Drob operator+(Drob ob1, Drob ob2); //�������-���� ��� ���������� �������� ��������
    friend Drob operator-(Drob ob1, Drob ob2); //�������-���� ��� ���������� �������� ���������
    friend Drob operator*(Drob ob1, Drob ob2); //�������-���� ��� ���������� �������� ���������
    void show(); //������� ��������� �� �����
};

//���������� ��������
Drob operator+(Drob ob1, Drob ob2) {
    Drob temp(0, 0);
    temp.b = ob1.b * ob2.b;
    temp.a = (temp.b / ob1.b) * ob1.a + (temp.b / ob2.b) * ob2.a;
    return temp;
}

//���������� ���������
Drob operator-(Drob ob1, Drob ob2) {
    Drob temp(0, 0);
    temp.b = ob1.b * ob2.b;
    temp.a = (temp.b / ob1.b) * ob1.a - (temp.b / ob2.b) * ob2.a;
    return temp;
}

//���������� ���������
Drob operator*(Drob ob1, Drob ob2) {
    Drob temp(0, 0);
    temp.a = ob1.a * ob2.a;
    temp.b = ob1.b * ob2.b;
    return temp;
}

//������� �����, � �������� �������� ��������
void addSubMultDrob::show() {
    cout << "First drob " << ob1.a << "/" << ob1.b << endl;
    cout << "Second drob " << ob2.a << "/" << ob2.b << endl;
    cout << endl;
}


void main() {
    Drob ob(0, 0);
    addSubMultDrob ob2(5, 4, 3, 4); //������� 2 ����� 5/4 � 3/4

    ob2.show();

    cout << "After sum ";

    ob = ob2.ob1 + ob2.ob2; //��������
    ob.NOD();
    ob.show();

    cout << "After sub ";

    ob = ob2.ob1 - ob2.ob2; //���������
    ob.NOD();
    ob.show();

    cout << "After mul "; //���������

    ob = ob2.ob1 * ob2.ob2;
    ob.NOD();
    ob.show();

}