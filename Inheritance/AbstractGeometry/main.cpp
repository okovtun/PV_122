//AbstractGeometry
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<thread>
using std::cin;
using std::cout;
using std::endl;

namespace Geometry
{
	enum Color
	{
		console_gray = 0x88,	//0x88 - шестнадцатеричный код цвета
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_white = 0xFF,
		console_default = 0x07,

		red = 0x000000FF,
		green = 0x0000FF00,
		dark_green = 0x0000AA00,
		blue = 0x00FF0000,
		yellow = 0x0E00FFFF,
		white = 0x00FFFFFF
		//
	};
	//enum - перечисление. ѕеречисление - это набор именованных констант типа int.

	const char* console_color[] =
	{
		"08",
		"19",
		"2A",
		"4C",
		"7F"
	};

	class Shape
	{
	protected:
		Color color;
		unsigned int width;	//Ўирина линии
		//Ќачальные координаты дл€ рисовани€ фигуры
		unsigned int start_x;
		unsigned int start_y;
	public:
		unsigned int get_width()const
		{
			return width;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		void set_width(unsigned int width)
		{
			if (width > 20)width = 20;
			this->width = width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 1000)start_x = 1000;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y > 700)start_y = 700;
			this->start_y = start_y;
		}

		Shape(Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :color(color)
		{
			set_width(width);
			set_start_x(start_x);
			set_start_y(start_y);
			cout << "ShConstructor:\t" << this << endl;
		}
		virtual ~Shape()
		{
			cout << "ShDestructor:\t" << this << endl;
		}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		void start_draw()const
		{
			while (true)
			{
				draw();
			}
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		Square(double side, Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
		{
			set_side(side);
		}
		~Square()
		{

		}

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
			//std::string command = std::string("color ") + console_color[color];
			//cout << command << endl;
			//system(command.c_str());
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			//SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|BACKGROUND_RED);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
	};

	class Rectangle :public Shape
	{
		double side1;
		double side2;
	public:
		double get_side1()const
		{
			return side1;
		}
		double get_side2()const
		{
			return side2;
		}
		void set_side1(double side1)
		{
			if (side1 <= 0)side1 = 1;
			this->side1 = side1;
		}
		void set_side2(double side2)
		{
			if (side2 <= 0)side2 = 2;
			this->side2 = side2;
		}
		Rectangle(double side1, double side2, Color color, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100) :Shape(color, width, start_x, start_y)
		{
			set_side1(side1);
			set_side2(side2);
		}
		~Rectangle()
		{

		}
		double get_area()const
		{
			return side1 * side2;
		}
		double get_perimeter()const
		{
			return (side1 + side2) * 2;
		}
		void draw()const
		{
			//1) ѕолучаем окно консоли:
			//HWND hwnd = GetConsoleWindow();
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			//2) —оздаем контекст устройства полученного окна:
			HDC hdc = GetDC(hwnd);
			//3) —оздаем карандаш:
			HPEN hPen = CreatePen(PS_SOLID, 5, color);//PS_SOLID - сплошна€ лини€, 5 - толщина линии 5 пикселов
			//4) ѕрежде чем рисорвать , нужно выбрать чем и на чем рисовать:
			SelectObject(hdc, hPen);

			//5) „тобы фигура была закрашена определенным цветом, нужно создать и применить кисть
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hBrush);

			::Rectangle(hdc, start_x, start_y, start_x + side2, start_y + side1);

			DeleteObject(hBrush);
			//?) ”дал€ем карандаш:
			DeleteObject(hPen);
			//?) ¬се контексты устройств нужно удал€ть, чтобы освободить занимаемые ими ресурсы:
			ReleaseDC(hwnd, hdc);
		}
	};

	class Triangle :public Shape
	{
		//Ётот класс €вл€етс€ абстрактным, поскольку треуголники бывают:
		//равносторонний, равнобедренный, пр€моугольный, тупоугольный.
	public:
		Triangle(Color color, unsigned int width, unsigned int start_x, unsigned int start_y)
			:Shape(color, width, start_x, start_y)
		{

		}
		~Triangle()
		{

		}
		virtual double get_height()const = 0;
		//Ќќ, мы значем что у каждого треугольника есть высота,
		//и как ее вычислить зависит от конкретного типа треугольника
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		double get_area()const
		{
			//https://www.webmath.ru/poleznoe/formules_14_4.php
			return side * side*sqrt(3) / 4;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//int arr[] = { 3,5,8,13,21 };
			const POINT points[] =
			{
				{start_x, start_y + this->get_height()},
				{start_x + side, start_y + this->get_height()},
				{start_x + side / 2, start_y}
			};
			Polygon(hdc, points, sizeof(points) / sizeof(POINT));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		EquilateralTriangle
		(
			double side,
			Color color = Color::white, unsigned int width = 5, unsigned int start_x = 100, unsigned int start_y = 100
		) :Triangle(color, width, start_x, start_y)
		{
			set_side(side);
		}
		~EquilateralTriangle()
		{

		}
	};
}

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer = { 80,50 };
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN, &buffer);
	//system("pause");
	setlocale(LC_ALL, "");
	//Shape shape;
	/*Geometry::Square square(5, Geometry::Color::console_red);
	cout << "ѕлощадь квадрата: " << square.get_area() << endl;
	cout << "ѕериметр квадрата: " << square.get_perimeter() << endl;
	square.draw();*/
	char key = 0;

	Geometry::Rectangle rect1(100, 200, Geometry::Color::yellow, 5, 200, 100);
	cout << rect1.get_area() << endl;
	cout << rect1.get_perimeter() << endl;

	/*while (key != ' ')
	{
		rect1.draw();
		if (_kbhit())key = _getch();
	}*/

	std::thread rect1_thread(&Geometry::Rectangle::start_draw, rect1);


	cout << "\n------------------------------------\n";
	Geometry::EquilateralTriangle et(300, Geometry::Color::green, 5, 200, 200);
	cout << et.get_height() << endl;
	cout << et.get_area() << endl;
	cout << et.get_perimeter() << endl;
	//system("pause");
	key = 0;
	//while (key != ' ')
	//{
	//	et.draw();
	//	if (_kbhit())key = _getch();
	//	//cin.get();
	//}
	std::thread et_thread(&Geometry::EquilateralTriangle::start_draw, et);
	//Sleep(10000);
	//cin.get();
	cin.get();
	et_thread.join();
	rect1_thread.join();
}