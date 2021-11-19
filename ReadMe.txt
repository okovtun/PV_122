https://github.com/okovtun/PV_122.git
https://www.youtube.com/watch?v=EDLjvLMibQI&list=PLeqyOOqxeiIO13nhWod9y7jd98OmXsgJC

TODO:
http://cplusplus.com/doc/tutorial/inheritance/
http://cplusplus.com/doc/tutorial/polymorphism/
https://drive.google.com/drive/folders/1mIhAKMp5-Jpy6s5X8u924tRCXFEdHE_z?usp=sharing

DONE:
В проекте Academy реализовать классы Teacher и Graduate(Дипломник), 
и написать проверочный код для них.

DONE:
1. В класс Matrix добавить Move методы и арифметические операторы: +, -, *;
2. Реализовать класс Binary описывающий двоичное число.
   Обеспечить арифметические и побитовые операции над двоичными числами
   Арифметические:	+, -, *, /;
   Побитовые:		~ - NOT;
					| -  OR;
					& - AND;
   А так же операции сравнения: ==, !=, >, <, >=, <=;

TOREAD:
http://cplusplus.com/doc/tutorial/classes2/

DONE:
1. В классе Fraction написать конструктор с одним параметром типа double,
   который будет преобразовывать десятичные дроби в обычные дроби:
   Fraction A = 2.75;
				(double)
   cout << A << endl;	//	2(3/4)			DONE

2. Проверочный код в проекте String должен заработать:	DONE
	https://github.com/okovtun/PV_122/blob/1d606dcef2d3442cf27017ab1028c6360a17bc65/IntroductionToOOP/String/main.cpp#L88

3. В отдельном проекте реализовать класс String, описывающий строку.
   Должна быть возможность создавать объекты следующим образом:
	String str;		//Создается пустая строка размером 80 Byte	DONE
	String str1 = "Hello";		DONE
	String str2 = "World";		DONE
	String str3 = str1 + str2;	//Конкатенация строк
	cout << str3 << endl;	//HelloWorld

DONE:
В классе Fraction реализовать:
1. Оператор перенправления в поток:				DONE
	Fraction A(2, 3);
	cout << A << endl;
2. Арифметические операции: +, -, *, /;			DONE
3. Составные присваивания:  +=, -=, *=, /=;		DONE
--------------------------------------------------------------
4. Increment/Decrement;							DONE
5. Операции сравнения: ==, !=, >, <, >=, <=;	DONE
6. Реализовать метод reduce(); который сокращает простую дробь;	DONE
	https://www.webmath.ru/poleznoe/formules_12_7.php
7. Обеспечить ввод дробей с клавиатуры:
	Fraction A;
	cin >> A;
	cout << A << endl;

DONE:
1. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
2. В отдельном проекте реализовать класс Fraction, описывающие простую дробь.
   В классе должны быть все необходимые методы. Так же должна быть возможность
   выполнять арифметические и прочие операции над дробями.


DONE:
0. ВЫУЧИТЬ ТЕОРИЮ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. В классе Point написать метод ??? distance(???), который возващает расстояние 
   ДО УКАЗАННОЙ ТОЧКИ;		DONE
2. Написать функцию ??? distance(???), которая возвращает расстояние между двумя точками.