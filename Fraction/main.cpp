#include<iostream>
using namespace std;

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
	Fraction(int integer)
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

	//		Methods:
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}

	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
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
	Fraction operator*=(Fraction obj)
	{
		this->to_improper();
		obj.to_improper();
		this->numerator*= obj.get_numerator();
		this->denominator*= obj.get_denominator();
		return *this;
	}
	Fraction operator/=(Fraction obj)
	{
		this->to_improper();
		obj.to_improper();
		this->numerator*= obj.get_denominator();
		this->denominator*= obj.get_numerator();
		return *this;
	}
	Fraction operator+=(const Fraction& obj)
	{
		this->integer+= obj.get_integer();
		int min_denom = this->denominator < obj.get_denominator() ? this->denominator : obj.get_denominator();
		int max_denom = this->denominator > obj.get_denominator() ? this->denominator : obj.get_denominator();
		int i = 0;
		do
			++i;
		while (min_denom * i % max_denom != 0);
		this->numerator= this->numerator * ((min_denom * i) / this->denominator) + obj.get_numerator() * ((min_denom * i) / obj.get_denominator());
		this->denominator=min_denom * i;
		return *this;
	}
	Fraction operator-=(const Fraction& obj)
	{
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
		this->denominator=min_denom * i;
		return *this;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result;
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


//#define CONSTRUCTORS_CHEK

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
#endif

	Fraction A(7, 5, 12);
	A.print();
	Fraction B(3, 2, 3);
	B.print();
	Fraction C = A * B;
	C.print();
	C = A + B;
	C.print();
	C = A - B;
	C.print();
	A -= B;
	A.print();

}