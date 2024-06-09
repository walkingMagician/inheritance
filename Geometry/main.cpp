#define _USE_MATH_DEFINES
#include<windows.h>
#include<iostream>


using namespace std;

namespace Geometry
{
	enum Color
	{
		RED = 0x000000FF,
		GREEN = 0x0000FF00,
		BLUE = 0x00FF0000,
		YELLOW = 0x0000FFFF,
		WHITE = 0x00FFFFFF,
		GREY = 0x00AAAAAA,


		CONSOLE_RED = 0xCC,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_BLUE = 0x99,
		CONSOLE_DEFAULT = 0x07
	};

#define SHAPE_TAKE_PARAMETERS unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x, start_y, line_width, color

	class Shape
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;

		Color color;
	public:
		static const int MAX_START_X = 400;
		static const int MAX_START_Y = 400;
		static const int MIN_START_X = 100;
		static const int MIN_START_Y = 100;

		static const int MIN_LINE_WIDTH = 3;
		static const int MAX_LINE_WIDTH = 6;

		Shape(SHAPE_TAKE_PARAMETERS) : color(color) 
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		virtual double get_area() const = 0;
		virtual double get_perimeter() const = 0;
		virtual void draw()const = 0;

		unsigned int get_start_x() const
		{
			return start_x;
		}
		unsigned int get_start_y() const
		{
			return start_y;
		}
		unsigned int get_line_width() const
		{
			return line_width;
		}
		Color get_color() const
		{
			return color;
		}

		void set_start_x(unsigned int start_x) 
		{
			if (start_x < MIN_START_X)start_x = MIN_START_X;
			if (start_x > MAX_START_X)start_x = MAX_START_X;
			this->start_x = start_x;
			//this->start_x = start_x < MAX_START_X ? start_x : MAX_START_X;
		}
		void set_start_y(unsigned int start_y) 
		{
			if (start_y < MIN_START_Y)start_y = MIN_START_Y;
			if (start_y > MAX_START_Y)start_y = MAX_START_Y;
			this->start_y = start_y;
			//this->start_y = start_y;
			//this->start_y = start_y < MAX_START_Y ? start_y : MAX_START_Y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
			if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
			this->line_width = line_width;
		}
		void set_color(Color color)
		{
			this->color = color;
		}
		virtual void info() const
		{
			cout << "area: " << get_area() << endl;
			cout << "perimeter: " << get_perimeter() << endl;
			draw();
		}
	};

	class Rectangle :public Shape
	{
		double width;
		double heigth;
	public:
		Rectangle(double width, double heigth, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_heigth(heigth);
		}
		~Rectangle() {}

		double get_area() const override
		{
			return width * heigth;
		}

		double get_perimeter() const override
		{
			return 2 * (width + heigth);
		}

		double get_width() const
		{
			return width;
		}
		double get_heigth() const
		{
			return heigth;
		}
		void set_width(double width)
		{
			this->width = width;
		}
		void set_heigth(double heigth)
		{
			this->heigth = heigth;
		}

		void draw() const override
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < heigth; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "# ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);*/

			HWND hwnd = GetConsoleWindow();
			HDC  hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color - 1000);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + heigth);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info() const override
		{
			cout << typeid(*this).name() << endl;
			cout << "width: " << get_width() << endl;
			cout << "heigth: " << get_heigth() << endl;
			Shape::info();
		}
	};

	class Sqare :public Rectangle
	{
	public:
		Sqare(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side ,SHAPE_GIVE_PARAMETERS) {}
		~Sqare() {}

		void info() const override
		{
			cout << typeid(*this).name() << endl;
			cout << "side: " << get_width() << endl;
			Rectangle::info();
		}

		class Circle :public Shape
		{
			Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {}
			~Circle() {}

			double get_area() const override
			{
				//return M_PI * radius * radius;
			}

		};

	};
}

void main()
{
	Geometry::Rectangle rectangle(120, 80, 1000, 1000, 5, Geometry::Color::YELLOW);
	/*cout << "width: " << rectangle.get_width() << endl;
	cout << "heigth: " << rectangle.get_heigth() << endl;
	cout << "area: " << rectangle.get_area() << endl;
	cout << "perimeter: " << rectangle.get_perimeter() << endl;
	rectangle.draw();*/

	rectangle.info();

	Geometry::Sqare sqare(100, 80, 1000, 8, Geometry::Color::BLUE);
	sqare.info();

	cin.get();
}