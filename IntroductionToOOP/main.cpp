#include<iostream>
#include<math.h>
using namespace std;
using std::endl;
using std::cout;
using std::cin;
//описание структуры
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//Constructors:
	/*Point()
	{
		x = y = double();
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = double();
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	Point(const Point& other)//deep-copy
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Deep-copy:\t"<<this<<endl;
	}
	//Assigment operator:
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	Point operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	// Increment/Decrement
	Point operator++() //Prefix increment
	{
		x++;
		y++;
		return *this;
	}

	Point operator++(int) //postfix increment
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	Point operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}

	//Metods:
	void print()const
	{
		cout << "X = " << this->x << "\t" << "Y = " << this->y << endl;
	}

	double distance()const //distance one Point
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}
};

double distance(const Point& firstP, const Point& secondP) //distance two Points
{
	return sqrt(pow((firstP.get_x() - secondP.get_x()), 2) + pow(firstP.get_y() - secondP.get_y(), 2));
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator==(const Point& left, const Point& right)
{
	return (left.get_x()== right.get_x() && left.get_y() == right.get_y());
}

std::ostream& operator<<(std::ostream& os, const Point obj)
{
	os << "X= " << obj.get_x() << "\tY= " << obj.get_y();
	return os;
}

//#define STRUCT_POINT;
//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a;	 //создание переменной 'a' типа 'int'
	Point A; //создание объекта 'A' структуры 'Point'
			 //создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif //STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	Point A; //default constructor
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B = 5;//single argument parameter
	B.print();
	Point C(2,3);
	C.print();
	Point D = C;//deep-copy
	D.print();
	Point E;
	E = D;
	E.print();
#endif //CONSTRUCTORS_CHECK
#ifdef ASSIGMENT_CHECK
	Point A, B, C;
	A = B = C = Point(4, 4);
#endif //ASSIGMENT_CHECK


	Point A(2, 3);
	A.print();
	cout << A.distance() << endl;//use distance one Point

	Point B(7, 8);
	B.print();
	cout << "Расстояние между точками А и В: "<<distance(A, B) << endl;//use distance two Points
	Point C = A + B;
	C.print();

	A += B;
	A.print();

	B=A++;
	A.print();
	B.print();

	cout << (A == B) << endl;
	cout << A << endl;

	/*A.set_x(33);
	A.set_y(44);*/
	A(33, 44);
	A.print();
}

