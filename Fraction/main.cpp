#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer=integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator=numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//	Constructors:
	Fraction()//DefaultCon
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator,int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "2ArgConstructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "3ArgConstructor:/t" << this << endl;
	}
	Fraction(const Fraction& obj)
	{
		this->integer = obj.integer;
		this->numerator = obj.numerator;
		this->denominator = obj.denominator;
		cout << "CopyConstructor:/t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:/t" << this << endl;
	}
	// Increment/Decrement
	Fraction& operator++()
	{
		integer++;
		return *this;
	}

	Fraction& operator++(int)//postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	Fraction& operator--()
	{
		integer--;
		return *this;
	}

	Fraction& operator--(int)//postfix decrement
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	//Type-cast operators
	explicit operator int()
	{
		return to_proper().integer;
	}
	explicit operator double()
	{
		return integer + (double)numerator / denominator;
	}
	//		Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		if (numerator == 0)return *this;
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	//		Operators:
	Fraction& operator=(const Fraction& obj)
	{
		this->integer = obj.integer;
		this->numerator = obj.numerator;
		this->denominator = obj.denominator;
		cout << "CopyAssigment:/t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& obj)
	{
		return *this = *this*obj;
	}
	Fraction& operator/=(const Fraction& obj)
	{
		return *this = *this / obj;
	}
	Fraction operator+=(const Fraction& obj)
	{
		/*
		this->integer+= obj.get_integer();
		int min_denom = this->denominator < obj.get_denominator() ? this->denominator : obj.get_denominator();
		int max_denom = this->denominator > obj.get_denominator() ? this->denominator : obj.get_denominator();
		int i = 0;
		do
			++i;
		while (min_denom * i % max_denom != 0);
		this->numerator= this->numerator * ((min_denom * i) / this->denominator) + obj.get_numerator() * ((min_denom * i) / obj.get_denominator());
		this->denominator=min_denom * i;*/

		return *this=*this+obj;
	}
	Fraction operator-=(const Fraction& obj)
	{/*
		Fraction result;
		this->integer-= obj.get_integer();
		int min_denom = this->denominator < obj.get_denominator() ? this->denominator : obj.get_denominator();
		int max_denom = this->denominator > obj.get_denominator() ? this->denominator : obj.get_denominator();
		int i = 0;
		do
			++i;
		while (min_denom * i % max_denom != 0);
		if (this->numerator < obj.get_numerator())
		{
			this->numerator= this->numerator * ((min_denom * i) / this->denominator) - obj.get_numerator() * ((min_denom * i) / obj.get_denominator());
		}
		else
		{
			this->integer--;
			this->numerator=(min_denom * i) + (this->numerator * (min_denom * i) / this->denominator) - obj.get_numerator() * ((min_denom * i) / obj.get_denominator());
		}
		this->denominator=min_denom * i;*/

		return *this=*this-obj;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	return result;*/
	/*
	Fraction result(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
	result.to_proper();
	*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(), 
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
	//Явно вызывается конструктор и создается временный безымянный объект
	//Этот объект сразу же возвращается на место вызова функции
	//Временные безымянные существуют в пределах одного выражения.
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left*right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	int min_denom=left.get_denominator() < right.get_denominator() ? left.get_denominator() : right.get_denominator();
	int max_denom=left.get_denominator() > right.get_denominator() ? left.get_denominator() : right.get_denominator();
	int i = 0;
	do
		++i;
	while (min_denom * i % max_denom != 0);
	result.set_numerator(left.get_numerator() * ((min_denom * i) / left.get_denominator()) + right.get_numerator() * ((min_denom * i) / right.get_denominator()));
	result.set_denominator(min_denom * i);
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	Fraction result;
	result.set_integer(left.get_integer() - right.get_integer());
	int min_denom = left.get_denominator() < right.get_denominator() ? left.get_denominator() : right.get_denominator();
	int max_denom = left.get_denominator() > right.get_denominator() ? left.get_denominator() : right.get_denominator();
	int i = 0;
	do
		++i;
	while (min_denom * i % max_denom != 0);
	if (left.get_numerator() < right.get_numerator())
	{
		result.set_numerator(left.get_numerator() * ((min_denom * i) / left.get_denominator()) - right.get_numerator() * ((min_denom * i) / right.get_denominator()));
	}
	else
	{
		result.set_integer(result.get_integer() - 1);
		result.set_numerator((min_denom * i)+(left.get_numerator() * (min_denom * i) / left.get_denominator()) - right.get_numerator() * ((min_denom * i) / right.get_denominator()));
	}
	result.set_denominator(min_denom * i);
	return result;
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator());
}
bool operator!=(const Fraction left, Fraction right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator());
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator());
}
bool operator>=(const Fraction left, Fraction right)
{
	return !(left < right);
}
bool operator<=(const Fraction left, Fraction right)
{
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os<< "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	/*
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	if (is) 
	{
		obj.set_integer(integer);
		obj.set_numerator(numerator);
		obj.set_denominator(denominator);
	}*/
	/*
	-------------
	5
	1/2
	5(1/2)
	-------------
	*/
	const int SIZE = 256;
	char sz_buffer[SIZE]{};
	is >> sz_buffer;
	int number[3] = {};
	char delimiters[] = "()/";
	int n = 0;
	for (char* pch = strtok(sz_buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = std::atoi(pch);//atoi - ASCII-string to integer - преобразует строку в число
	}
	switch (n)
	{
	case 1: obj = Fraction(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]); break;
	case 3: obj = Fraction(number[0], number[1], number[2]); break;
	}
	return is;
}

//#define CONSTRUCTORS_CHEK
//#define ARIFMETICAL_OPERATORS_CHEK
//#define INCREMENT_CHEK
// 
//#define TYPE_CONVERSIONS_BASIC
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
#define CONVERSIONS_HOME_WORK

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

#endif
}