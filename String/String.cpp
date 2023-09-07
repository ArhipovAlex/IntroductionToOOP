#include"String.h"

/////////////////////////////////////////
//ÎÏÐÅÄÅËÅÍÈÅ ÊËÀÑÑÀ - Class Definition//
//:: - Scope operator - îïåðàòîð ðàçðåøåíèÿ âèäèìîñòè
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//		Constructors:
//Êëþ÷åâîå ñëîâî explicit ìîæíî îïèñàòü òîëüêî âíóòðè êëàññà
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstruct:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str)+1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Single-Argument Char constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//deep copy
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i=0; i<size; i++)this->str[i] = other.str[i];
	cout << "CopyConstruct:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//shallow copy
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}
//		Operators
String& String::operator=(const String& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
}
String& String::operator+=(const String& obj)
{
	return *this = *this + obj;
}
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
//		Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
//Global-function
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[left.get_size() + i - 1] = right[i];
	return cat;
}
//ÊÎÍÅÖ ÎÏÐÅÄÅËÅÍÈÅ ÊËÀÑÑÀ - Class Definition End//
///////////////////////////////////////////////////
