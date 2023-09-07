#include"String.h"

//#define CONSTRUCTOR_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK
	String str(5);
	str.print();

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = str1; //Copy Constructor
	cout << str2 << endl;

	String str3;
	str3 = str2; //copy assigment
	cout << str3 << endl;
#endif //CONSTRUCTOR_CHEK
#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter<<endl;
	//String str3 = str1+str2;
	String str3;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;
	str1 += str2;
	cout << str1 << endl;
#endif //OPERATOR_PLUS_CHECK

	String str1;	//Default constructor
	str1.print();

	String str2(5);	//Single-Arg constructor
	str2.print();

	String str3 = "Hello"; //Single-Argument Char constructor
	str3.print();

	String str4();	//«десь не создаетс€ никакой объект,
					//объ€вл€етс€ функци€ str4, котора€ ничего не принимает 
					//и возвращает объект класса String
	//str4.print();
	String str5{}; //явно вызываетс€ конструктор по умолчанию
	str5.print();

	String str6("World");
	str6.print();

	String str7{ "Compile" };
	str7.print();

	String str8 = str3;//Copy constructor
	str8.print();

	String str9;
	str9 = str6;
	str9.print();
}