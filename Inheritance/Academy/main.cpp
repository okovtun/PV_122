//Polymorphic streams DONE.
#include<iostream>
#include<fstream>
#include<string>
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

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//				Constructors:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	) :Human(last_name, first_name, age)	//Делегируем конструктор базового класса
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//				Methods:
	ostream& print(ostream& os)const
	{
		Human::print(os);
		//os << tab;
		//return os /*<< ", Специальность: "*/ << speciality << tab
		//	/*<< ", группа: "*/ << group
		//	/*<< ", успеваемость: " */ << rating;
		os.width(25);
		os << left;
		os << speciality;

		os.width(8);
		os << left;
		os << group;

		os.width(5);
		//os << right;
		os << internal;
		os << rating;
		os << "%";
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		//os << tab;
		//return os /*<< ", Специальность: "*/ << speciality << tab
		//	/*<< ", группа: "*/ << group
		//	/*<< ", успеваемость: " */ << rating;
		os.width(25);
		os << left;
		os << speciality << "|";

		os.width(8);
		os << left;
		os << group << "|";

		os.width(5);
		//os << right;
		os << internal;
		os << rating;
		os << "% |";
		return os;
	}

	istream& input(istream& is)
	{
		Human::input(is);
		is >> speciality;
		is >> group;
		is >> rating;
		return is;
	}
};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//					Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	ostream& print(ostream& os)const
	{
		Human::print(os);
		//os << tab;
		//return os /*<< "специальность: "*/ << speciality
		//	/*<< ", опыт преподавания: "*/ << experience << " лет.";
		os.width(33);
		os << speciality;
		os.width(5);
		os << right;
		os << experience << "y";
		return os;
	}
	ofstream& print(ofstream& os)const
	{
		Human::print(os);
		//os << tab;
		//return os /*<< "специальность: "*/ << speciality
		//	/*<< ", опыт преподавания: "*/ << experience << " лет.";
		os.width(33);
		os << speciality << " | ";
		os.width(5);
		os << right;
		os << experience << "y|";
		return os;
	}

};

class Graduate :public Student
{
	string subject;
public:
	const string& get_subject()const
	{
		return subject;
	}
	void set_subject(const string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& subject
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	ostream& print(ostream& os)const
	{
		Student::print(os);
		//return os /*<< "Тема диплома: "*/ << tab << subject << endl;
		return os << left << " " << subject;
	}
	ofstream& print(ofstream& os)const
	{
		Student::print(os);
		//return os /*<< "Тема диплома: "*/ << tab << subject << endl;
		os << left << " " << subject;
		return os;
	}

};

void SaveToFile(const Human* group[], const int size, const string& filename);
Human** LoadFromFile(const std::string& filename);

//#define INHERITANCE
//#define OUTPUT_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human h("Montana", "Antonio", 35);
	h.print();

	Student s("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93);
	s.print();

	Teacher t("White", "Walter", 50, "Chemistry", 25);
	t.print();

	Graduate g("Schrader", "Hank", 42,
		"Cryminalistic", "OBN", 95,
		"How to catch Heisenberg");
	g.print();
#endif // INHERITANCE

#ifdef OUTPUT_CHECK
	//Generalisation:
	const Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 5),//upcast
		new Student("Vercetti", "Tomas", 30, "Cryminal", "Vice", 100),//upcast
		new Teacher("White", "Walter", 50, "Chemistry", 25),//upcast
		new Student("Diaz", "Ricardo", 55, "Weapons distribution", "Vice", 80),
		new Graduate("Schrader", "Hank", 42,
		"Cryminalistic", "OBN", 95,	"How to catch Heisenberg"),
		new Teacher("Eistein", "Albert", 143, "Astronomy", 120)
	};

	//Specialisation - уточнение, конкретизацию
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << "\n----------------------------------------\n";
		//group[i]->print();
		cout << *group[i] << endl;
	}
	cout << "\n----------------------------------------\n";

	/*ofstream fout("group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad group.txt");*/
	string filename = "group.txt";
	SaveToFile(group, sizeof(group) / sizeof(group[0]), "group.txt");
	system((string("notepad ") + filename).c_str());
	//string("notepad ") - преобразуем стрококвую константу "notepad " в объект класса std::string
	//string("notepad ") + filename - выполняем конкатенацию двух объектов класса std::string
	//(std::string).c_str() - метод c_str() возвращает содержимое объекта std::string 
	//в виде обычной NULL Terminated line (C-string), т.е., в виде массива элементов char.

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete[] group[i];
	}
	//cout << sizeof(group)/sizeof(Human*) << endl;  
#endif // OUTPUT_CHECK

	/*Human human("last_name", "first_name", 0);
	cout << "Кто к нам пришел: ";
	cin >> human;
	cout << human << endl;*/

	/*Student stud("", "", 0, "", "", 0);
	cout << "Кто к нам пришел: ";
	cin >> stud;
	cout << stud << endl;*/

	LoadFromFile("group.txt");
}

/*
---------------------------------------------------------
					Polymorphism
(inclusion polymorphism) - это способность объектов
вести себя по разному, в зависимости от того, кем они являются.
//Generalisation
//upcast (преобразование вверх)
---------------------------------------------------------
*/

void SaveToFile(const Human* group[], const int size, const string& filename)
{
	ofstream fout(filename);
	for (int i = 0; i < size; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();

}
Human** LoadFromFile(const std::string& filename)
{
	ifstream fin(filename);
	if (fin.is_open())
	{
		//1) Вычисляем размер файла
		std::string buffer;	//В этот буфер будем читать строки из файла
		int n = 0;	//Количество строк в файле
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			cout << fin.tellg() << endl;
			n++;
		}
		//2) Выделяем память под массив группу
		Human** group = new Human*[n] {};
		//3) Возвращаем курсор в начало файла, для того чтобы заново его прочитать
		fin.clear();
		fin.seekg(ios::beg, 0);
		cout << fin.tellg() << endl;
		//4) Заново читаем файл, и загружаем его содержимое в массив олбъектов:
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer);
			cout << buffer << endl;
		}
		fin.close();
	}
	else
	{
		cerr << "Error: File not found!" << endl;
	}
	return nullptr;	//Если файл прочитать НЕ удалось, возвращаем указатель на 0
}