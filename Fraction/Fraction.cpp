#include"Fraction.h"

/////////////////////////////////////////
//ОПРЕДЕЛЕНИЕ КЛАССА - Class Definition//
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

//	Constructors:
Fraction::Fraction()//DefaultCon
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "1ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;
	numerator = decimal * denominator;
	reduce();
	cout << "doubleConstructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "2ArgConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->denominator = denominator;
	cout << "3ArgConstructor:/t" << this << endl;
}
Fraction::Fraction(const Fraction& obj)
{
	this->integer = obj.integer;
	this->numerator = obj.numerator;
	this->denominator = obj.denominator;
	cout << "CopyConstructor:/t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:/t" << this << endl;
}
// Increment/Decrement
Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction& Fraction::operator++(int)//postfix increment
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction& Fraction::operator--()
{
	integer--;
	return *this;
}
Fraction& Fraction::operator--(int)//postfix decrement
{
	Fraction old = *this;
	integer--;
	return old;
}
//Type-cast operators
Fraction::operator int()
{
	return to_proper().integer;
}
Fraction::operator double()
{
	return integer + (double)numerator / denominator;
}
//		Methods:
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction& Fraction::reduce()
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
void Fraction::print()const
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
Fraction& Fraction::operator=(const Fraction& obj)
{
	this->integer = obj.integer;
	this->numerator = obj.numerator;
	this->denominator = obj.denominator;
	cout << "CopyAssigment:/t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& obj)
{
	return *this = *this * obj;
}
Fraction& Fraction::operator/=(const Fraction& obj)
{
	return *this = *this / obj;
}
Fraction Fraction::operator+=(const Fraction& obj)
{
	return *this = *this + obj;
}
Fraction Fraction::operator-=(const Fraction& obj)
{
	return *this = *this - obj;
}

// Global Functions
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
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	int min_denom = left.get_denominator() < right.get_denominator() ? left.get_denominator() : right.get_denominator();
	int max_denom = left.get_denominator() > right.get_denominator() ? left.get_denominator() : right.get_denominator();
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
		result.set_numerator((min_denom * i) + (left.get_numerator() * (min_denom * i) / left.get_denominator()) - right.get_numerator() * ((min_denom * i) / right.get_denominator()));
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
		if (obj.get_integer())os << "(";
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
//КОНЕЦ ОПРЕДЕЛЕНИЕ КЛАССА - Class Definition End//
///////////////////////////////////////////////////