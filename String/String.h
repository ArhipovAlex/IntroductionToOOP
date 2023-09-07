#pragma once
#include<iostream>

using namespace std;


#define delimiter "\n-----------------------------\n"


class String;
String operator+(const String& left, const String& right);
/////////////////////////////////////////
//���������� ������ - Class Declaration//
class String
{
	int size;		//������ ������ � ������
	char* str;	//����� ������ � ������������ ������
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//		Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//		Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& obj);
	char operator[](int i)const;
	char& operator[](int i);
	//		Methods:
	void print()const;
};
//����� ���������� ������ - Class Declaration End//
///////////////////////////////////////////////////

//-------------------------------------------------

