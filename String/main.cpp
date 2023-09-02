#include<iostream>
using namespace std;

class String
{
	int size;		//размер строки в Байтах
	char* str;	//адрес строки в динамической памяти
public:
	const char* get_str()const 
	{
		return str;
	}
	//		Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstruct:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str)+1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Construct:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i=0; i<size; i++)this->str[i] = other.str[i];
		cout << "CopyConstruct:\t" << this << endl;
	}
	//		Operators
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	//		Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
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
}