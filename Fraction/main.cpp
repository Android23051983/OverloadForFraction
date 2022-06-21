#include"Fraction.h"

  

//#define CONSTRUCTORS_CHECK
//#define COMPARISON_OPERATOR
//#define CONVERTION_FROM_CLASS_TO_OTHER
#define COVERSIONS_HOME_WORK

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
       /* fraction A(2, 3, 4);
        cout << A<<endl;
        A.print();*/
        /*A.to_imnroper();
        A.print();
        A.to_proper();
        A.print();*/
       /* fraction B(3, 4, 5);
        B.print();*/

      /*  fraction C = A * B;
        C.print();

        (A - B).print();*/
       

      /*  for (double i = .75; i < 10; i++)
        {
            cout << i << "\t";
        }
        cout << endl;
        for (fraction i(1, 2); i.get_integer() >= 1;i++)
        {
            i.print();
        }*/
        /*cout << (A == B) << endl;*/
#ifdef COMPARISON_OPERATOR
        cout << "(operator ==) " << (A == B) << endl;
        cout << "(operator >) " << (A > B) << endl;
        cout << "(operator <) " << (A < B) << endl;

#endif // COMPARISON_OPERATOR
#ifdef CONVERTION_FROM_CLASS_TO_OTHER

        fraction A(2, 3, 4);
        cout << A << endl;
        int a = A;
        cout << a << endl;

        double b = A;
        cout << b << endl;
#endif // CONVERTION_FROM_CLASS_TO_OTHER

#ifdef COVERSIONS_HOME_WORK
        fraction A = 2.75;
        cout << A << endl;
#endif // COVERSIONS_HOME_WORK

  /*      fraction A;
        cout << "¬ведите простую дробь:"; 
        cin >> A;

        cout << A << endl;*/

        /*

        --------------------------------------------------
        5
        1/20
        2(2/3)
        2 3/4
        --------------------------------------------------

        */

 }

    




