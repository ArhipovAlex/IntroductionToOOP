#include"Fraction.h"

#define CONSTRUCTORS_CHEK
//#define ARIFMETICAL_OPERATORS_CHEK
//#define INCREMENT_CHEK
//#define TYPE_CONVERSIONS_BASIC
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define CONVERSIONS_HOME_WORK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHEK
	Fraction A; //Default Constructor
	A.print();

	Fraction B = 5; //Single-Argument Constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif //CONSTRUCTORS_CHEK
#ifdef ARIFMETICAL_OPERATORS_CHEK
	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();
	Fraction C = A + B;
	C.print();
	A += B;
	A.print();
	A -= B;
	A.print();
#endif //ARIFMETICAL_OPERATORS_CHEK
#ifdef INCREMENT_CHEK
	for (Fraction i(1, 4); i.get_integer() < 10; ++i)//лучше использовать префикс инкремент при работе с объектами
	{
		i.print();
	}
#endif //INCREMENT_CHEK

	//cout << (Fraction(1, 2) > Fraction(5, 10)) << endl;
	/*
	Fraction A;
	cout << "Введите дробь:\t"; cin >> A;
	cout << A << endl;
	*/
#ifdef TYPE_CONVERSIONS_BASIC

#endif //TYPE_CONVERSIONS_BASIC
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5; // Conversion INT to Fraction from 1ArgConstructor
	cout << A << endl;

	Fraction B;
	B = Fraction(8);
	cout << B << endl;
#endif //CONVERSIONS_FROM_OTHER_TO_CLASS
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	Fraction A(52, 10);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;

	Fraction B(2, 3, 4);
	cout << B << endl;
	double b = (double)B;
	cout << b << endl;
#endif//CONVERSIONS_FROM_CLASS_TO_OTHER
#ifdef CONVERSIONS_HOME_WORK
	Fraction A = 2.75;
	cout << A << endl;
#endif
}