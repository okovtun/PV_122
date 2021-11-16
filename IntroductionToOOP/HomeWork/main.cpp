#include<iostream>
#include<string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	string str1 = "Hello";
	string str2 = "World";
	cout << str1 + str2 << endl;
	str1.append(str2);
	cout << str1 << endl;
	cout << (str1 == str1) << endl;
}