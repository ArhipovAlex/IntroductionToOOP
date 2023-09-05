#include<iostream>
using namespace std;


#define delimiter "\n-----------------------------\n"

class String
{
	int size;		//размер строки в Байтах
	char* str;	//адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const 
	{
		return str;
	}
	char* get_str()
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
	String(String&& other)
	{
		//shallow copy
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
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
		//deep copy
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
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
	}
	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
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
String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size()-1);
	for (int i = 0; i < left.get_size(); i++) 
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[left.get_size()+i-1] = right[i];
	return cat;
}

//#define CONSTRUCTOR_CHECK
#define OPERATOR_PLUS_CHECK

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
#endif //OPERATOR_PLUS_CHECK
}