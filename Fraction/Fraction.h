#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
/////////////////////////////////////////
//ÎÁÚßÂËÅÍÈÅ ÊËÀÑÑÀ - Class Declaration//
class Fraction
{
	int integer;		//Öåëàÿ ÷àñòü
	int numerator;		//×èñëèòåëü
	int denominator;	//Çíàìåíàòåëü
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//	Constructors:
	Fraction();//DefaultCon
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& obj);
	~Fraction();
	// Increment/Decrement
	Fraction& operator++();
	Fraction& operator++(int);//postfix increment
	Fraction& operator--();
	Fraction& operator--(int);//postfix decrement
	//Type-cast operators
	explicit operator int();
	explicit operator double();
	//		Methods:
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduce();
	void print()const;
	//		Operators:
	Fraction& operator=(const Fraction& obj);
	Fraction& operator*=(const Fraction& obj);
	Fraction& operator/=(const Fraction& obj);
	Fraction operator+=(const Fraction& obj);
	Fraction operator-=(const Fraction& obj);
};
//ÊÎÍÅÖ ÎÁÚßÂËÅÍÈß ÊËÀÑÑÀ - Class Declaration End//
///////////////////////////////////////////////////

//-------------------------------------------------