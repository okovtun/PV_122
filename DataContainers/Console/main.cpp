#include<iostream>
#include<Windows.h>
using namespace std;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer = { 160, 48 };
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &buffer);

	COORD pos = { 8, 5 };
	SetConsoleCursorPosition(hConsole, pos);
	cout << "Hello" << endl;
	CONSOLE_SCREEN_BUFFER_INFO csbi = {};
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	cout << "Cursor:\n";
	cout << csbi.dwCursorPosition.X << tab;
	cout << csbi.dwCursorPosition.Y << endl;
	cout << "Window size:\n";
	cout << csbi.dwSize.X << tab;
	cout << csbi.dwSize.Y << tab;
	cout << "Max Window size:\n";
	cout << csbi.dwMaximumWindowSize.X << tab;
	cout << csbi.dwMaximumWindowSize.Y << tab;

}