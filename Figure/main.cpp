#include<iostream>


class Figure
{
	int length, width; // длина, ширина
	
public:
	//get/set
	virtual int set_length() { return length; } const
	virtual int set_width() { return width; } const

	virtual void get_length(int length) { this->length = length; }
	virtual void get_width(int width) { this->width = width; }

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

class Square : public Figure
{
	int square, perimeter;

public:
	// get/set
	int set_square() { return square; }
	int set_perimeter() { return perimeter; }

	void get_square(int square) { this->square = square; }
	void get_perimeter(int perimeter) { this->perimeter = perimeter; }

	//constructor
	Square(int length, int width) :Figure(length, width)
	{
		get_square(length * width);
		get_perimeter((width + length) * 2);
		std::cout << "Sconstructor\t\t" << this << std::endl;
	}

	~Square() // destructor
	{
		std::cout << "Sdestructor\t\t" << this << std::endl;
	}

	// methods

	void print()
	{
		Figure::print();
		std::cout << "square: " << set_square() << "\t" << "perimeter: " << set_perimeter() << std::endl;
	}
};

class Rectangle : public Figure
{
	int square, perimeter;

public:
	// get/set
	int set_square() { return square; }
	int set_perimeter() { return perimeter; }

	void get_square(int square) { this->square = square; }
	void get_perimeter(int perimeter) { this->perimeter = perimeter; }

	//constructor
	Rectangle(int length, int width) :Figure(length, width)
	{
		get_square(length * width);
		get_perimeter((width + length) * 2);
		std::cout << "Rconstructor\t\t" << this << std::endl;
	}

	~Rectangle() // destructor
	{
		std::cout << "Rdestructor\t\t" << this << std::endl;
	}

	// methods

	void print()
	{
		Figure::print();
		std::cout << "square: " << set_square() << "\t" << "perimeter: " << set_perimeter() << std::endl;
	}
};

int main()
{
	Figure A(5,5);
	A.print();

	Square S(4, 4);
	S.print();

	Rectangle R(4, 8);
	R.print();

}