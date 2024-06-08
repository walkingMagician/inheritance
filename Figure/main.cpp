#include<iostream>
#include<math.h>

const double PI = 3.1415;

class Figure
{
	double length_AR; // длина стороны или (радиус)
public:	
	virtual double set_length_AR() { return length_AR; } const
	virtual void get_length_AR(double length_AR) { this->length_AR = length_AR; }

	// constructor
	Figure(double length_AR)
	{
		get_length_AR(length_AR);
		std::cout << "F-constructor:\t\t" << this << std::endl;
	}
	virtual ~Figure() // destructor
	{
		std::cout << "F-destructor:\t\t" << this << std::endl;
	}

	// methods
	virtual double sqare() = 0; // чисто виртуальная функция 
	virtual double perimeter() = 0;
	virtual void print()
	{
		std::cout << "sqare: " << sqare(); std::cout << "\tperimeter: " << perimeter(); std::cout << std::endl;
	}
};

class Square : public Figure
{
	double width; // ширина

public:
	//get/set
	double set_width() { return width; } const
	void get_width(double width) { this->width = width; }
	
	//constructor
	Square(double length_AR, double width = 0) :Figure(length_AR)
	{
		get_width(width);
		std::cout << "S-constructor\t\t" << this << std::endl;
	}
	~Square() // destructor
	{
		std::cout << "S-destructor\t\t" << this << std::endl;
	}

	// methods

	double sqare() // переопределение чисто виртуальной функции 
	{
		return set_length_AR() * set_width();
	}
	double perimeter()
	{
		return (set_length_AR() + set_width()) * 2;
	}

	void print()
	{
		std::cout << "length: " << set_length_AR() << "\twidth: " << set_width() << std::endl;
		Figure::print(); 

		for (int i = 0; i < set_length_AR(); i++)
		{
			for (int j = 0; j < set_width(); j++)
			{
				std::cout << "# ";
			}
			std::cout << std::endl;
		}
	}
};

class Triangle : public Figure
{
	double length_B, length_C; // length_R - длина стороны A, len_B - длина стороны B, len_C - длина стороны C
public:
	// set/get
	double set_length_B() { return length_B; } const
	double set_length_C() { return length_C; } const
	void get_length_B(double length_B) { this->length_B = length_B; }
	void get_length_C(double length_C) { this->length_C = length_C; }

	// constructor
	Triangle(double length_R, double length_B, int length_C) :Figure(length_R)
	{
		get_length_B(length_B);
		get_length_C(length_C);
		std::cout << "T-constructor:\t\t" << this << std::endl;
	}
	~Triangle() //destructor
	{
		std::cout << "T-destructor:\t\t" << this << std::endl;
	}

	// methods 
	double sqare()
	{
		double p = perimeter() / 2;
		return sqrt(p*(p - set_length_B()) * (p - set_length_C()) * (p - set_length_AR()));
	}
	double perimeter()
	{
		return set_length_AR() + set_length_B() + set_length_C();
	}

	void print()
	{
		std::cout << "storona A: " << set_length_AR() << "\tstorona B: " << set_length_B() << "\tstorona C: " << set_length_C() << std::endl;
		Figure::print();

		std::cout << "demo drawing: ";
		for (int i = 0; i <= set_length_AR(); ++i)
		{
			for (int j = set_length_B(); j > i; --j) std::cout << "  ";
			for (int j = 1; j < 2 * i; ++j) std::cout << "# ";
			std::cout << std::endl;
		}
		
	}
};

class Circle :public Figure
{
	
public:

	// constructor
	Circle(double length_AR) :Figure(length_AR)
	{
		std::cout << "C-constructor:\t\t" << this << std::endl;
	}
	~Circle()
	{
		std::cout << "C-destructor:\t\t" << this << std::endl;
	}

	// methods

	double sqare()
	{
		return PI * pow(set_length_AR(), 2);
	}

	double perimeter()
	{
		return 2 * PI * set_length_AR();
	}

	void print()
	{
		std::cout << "radius: " << set_length_AR() << std::endl;
		Figure::print();
	}

};


int main()
{
	Square S(5, 5);
	S.print();

	Triangle T(5, 6, 7);
	T.print();
	
	Circle C(8);
	C.print();

}


/*for (int i = 1; i <= set_length_AR(); ++i)
		{
			for (int j = set_length_B(); j > i; --j)
				std::cout << "  ";
			for (int j = 1; j < 2 * set_length_C(); ++j)
				std::cout << "# ";
			std::cout << std::endl;
		}*/