#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

#define tab "\t"

class Human
{
protected:
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//					Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//				Methods:
	virtual ostream& print(ostream& os)const
	{
		//return os << last_name << " " << first_name << " " << age;
		os.width(10);	//Задает ширину поля, в которое будет выводиться следующее значение
		os << std::left;
		os << last_name;
		os.width(10);
		os << std::left;
		os << first_name;
		os.width(5);
		os << age;
		return os;
	}
	virtual ofstream& print(ofstream& os)const
	{
		os.width(15);
		os << left;
		os << typeid(*this).name() << " | ";
		//return os << last_name << " " << first_name << " " << age;
		os.width(10);	//Задает ширину поля, в которое будет выводиться следующее значение
		os << std::left;
		os << last_name << "|";
		os.width(10);
		os << std::left;
		os << first_name << "|";
		os.width(5);
		os << age << "|";
		return os;
	}

	virtual istream& input(istream& is)
	{
		return is >> last_name >> first_name >> age;
	}
};
ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);
}
ofstream& operator<<(ofstream& os, const Human& obj)
{
	return obj.print(os);
}

istream& operator>>(istream& is, Human& obj)
{
	return obj.input(is);
}

class Employee :public Human
{
	std::string position;	//Занимаемая должность
public:
	const std::string& get_position()const
	{
		return position;
	}
	void set_position(const std::string& position)
	{
		this->position = position;
	}
	Employee
	(
		const string& last_name, const string& first_name, unsigned int age,
		const std::string& position
	) :Human(last_name, first_name, age)
	{
		this->position = position;
		cout << "EConstructor:\t" << this << endl;
	}
	~Employee()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	virtual double count_salary()const = 0;
};
class ResidentEmployee :public Employee
{
	double salary;
public:
	ResidentEmployee
	(
		const string& last_name, const string& first_name, unsigned int age,
		const std::string& position,
		double salary
	) :Employee(last_name, first_name, age, position)
	{
		this->salary = salary;
		cout << "RConstructor:\t" << this << endl;
	}
	~ResidentEmployee()
	{
		cout << "RDestructor:\t" << this << endl;
	}
	double count_salary()const
	{
		return salary;
	}
};
class HourEmployee :public Employee
{
	double rate;	//ставка за час
	int complete_hours;	//количество отработанных часов
public:
	HourEmployee
	(
		const string& last_name, const string& first_name, unsigned int age,
		const std::string& position,
		double rate,
		int complete_hours
	) :Employee(last_name, first_name, age, position), rate(rate), complete_hours(complete_hours)
	{
		cout << "HEConstructor:\t" << this << endl;
	}
	~HourEmployee()
	{
		cout << "HEDestructor:\t" << this << endl;
	}
	double count_salary()const
	{
		return rate * complete_hours;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Employee* department[] =
	{
		new HourEmployee("Pinkman", "Jessie", 22, "Helper", 1000, 20),//upcast
		new HourEmployee("Vercetti", "Tomas", 30, "Killer",  5000, 10),//upcast
		new ResidentEmployee("White", "Walter", 50, "Chemist", 150000),//upcast
		new ResidentEmployee("Diaz", "Ricardo", 55, "Director", 825000),
		new ResidentEmployee("Schrader", "Hank", 42,"Detective", 10000),
		new HourEmployee("Eistein", "Albert", 143, "Researcher", 3000, 15)
	};
	double total_money = 0;
	for (int i = 0; i < sizeof(department) / sizeof(department[0]); i++)
	{
		cout << *department[i] << " salary: " << department[i]->count_salary() << endl;
		total_money += department[i]->count_salary();
	}
	cout << "Total money: " << setprecision(15) << total_money << "USD" << endl;
	for (int i = 0; i < sizeof(department) / sizeof(department[0]); i++)
	{
		delete department[i];
	}
}