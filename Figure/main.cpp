#include<iostream>
#include<math.h>


class Figure
{
	int length, width; // длина, ширина (высота)
	//int square, perimeter; // площадь, периметр

public:
	//get/set
	virtual int set_length() { return length; } const
	virtual int set_width() { return width; } const

	virtual void get_length(int length) { this->length = length; }
	virtual void get_width(int width) { this->width = width; }

	/*virtual int set_square() { return square; } const
	virtual int set_perimeter() { return perimeter; } const

	virtual void get_square(int square) { this->square = square; } 
	virtual void get_perimeter(int perimeter) { this->perimeter = perimeter; }*/

	// constructor;
	Figure(int length, int width) 
	{
		get_length(length);
		get_width(width);
		std::cout << "Fconstructor:\t\t" << this << std::endl;
	}

	virtual ~Figure() // destructor
	{
		std::cout << "Fdestructor\t\t" << this << std::endl;
	}

	//methods
	virtual void print()
	{
		std::cout << "length: " << set_length() << "\t" << "width: " << set_width() << std::endl;
		SQARE();
	}	

	virtual void SQARE() {};
	virtual void PERIMETER() {};

};

class Square : public Figure
{
public:
	
	//constructor
	Square(int length, int width) :Figure(length, width)
	{
		/*get_square(length * width);
		get_perimeter((width + length) * 2);*/
		SQARE();
		PERIMETER();
		std::cout << "Sconstructor\t\t" << this << std::endl;
	}

	~Square() // destructor
	{
		std::cout << "Sdestructor\t\t" << this << std::endl;
	}

	// methods

	void SQARE()
	{
		set_length() * set_width();
	}

	void PERIMETER()
	{
		(set_length() + set_width()) * 2;
	}



	void print()
	{
		Figure::print();
		for (int i = 0; i < set_length(); i++)
		{
			for (int j = 0; j < set_width(); j++)
			{
				std::cout << "# ";
			}
			std::cout << std::endl;
		}
	}
};

//class Triangle :public Figure
//{
//	int lengthRebro;
//public:
//	// set/get
//
//	int set_lengthRebro() { return lengthRebro; }
//	void get_lengthRebro(int lengthRebro) { this->lengthRebro = lengthRebro; }
//
//	// constructors
//
//	Triangle(int length, int width) :Figure(length, width)
//	{
//		get_length(length);
//		get_width(width);
//
//	}
//
//	// methods
//
//	
//};

int main()
{
	Figure A(5,5);
	A.print();

	Square S(4, 4);
	S.print();


}