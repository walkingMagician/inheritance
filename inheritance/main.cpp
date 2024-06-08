#include<iostream>
#include<string>

using namespace std;

#define DELIMITR "---------------------------------------------------------------------------------------------" << endl;

class Human
{
	std::string last_name;
	std::string first_name;
	int age;

public:
	const std::string& get_last_name() const
	{
		return last_name;
	}
	const std::string& get_first_name() const
	{
		return first_name;
	}
	int get_age() const
	{
		return age;	
	}
	
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	// constructors

	Human(const std::string& last_name, const std::string& first_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "Hconstructor:\t\t" << this << endl;
	}

	virtual ~Human()
	{
		cout << "Hdestructor:\t\t" << this << endl;
	}
	
	// methods

	virtual void print() const
	{
		cout << last_name << " " << first_name << " " << age << " years" << endl;
	}

};

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating; // успеваемость
	double attendance; // посещаемость 
public:
	const std::string& get_speciality() const
	{
		return speciality;
	}
	const std::string& get_group() const
	{
		return group;
	}
	double get_rating() const
	{
		return rating;
	}
	double get_attendence() const
	{
		return attendance;
	}

	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	// constructors

	Student
	(
		const std::string& last_name, const std::string first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "Sconstructor:\t\t" << this << endl;
	}
	~Student()
	{
		cout << "Sdestructor:\t\t" << this << endl;
	}

	// methods

	void print() const
	{
		Human::print();
		cout << speciality << "\t" << group << "\t" << rating << "\t" << attendance << endl;
	}

};

class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	int get_speciality(int experience)
	{
		this->experience = experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	// constructor

	Teacher
	(
		const std::string& last_name, const std::string first_name, int age,
		const std::string& speciality, int experience
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "Tconstructor:\t\t" << this << endl;
	}
	~Teacher()
	{
		cout << "Tdestructor:\t\t" << this << endl;
	}

	// methods

	void print() const
	{
		Human::print();
		cout << speciality << "\t" << experience << " years" << endl;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject() const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(
		const std::string& last_name, const std::string first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "Gconstructor:\t\t" << this << endl;
	}
	~Graduate()
	{
		cout << "Gdestructor:\t\t" << this << endl;
	}

	// methods

	void print() const
	{
		Student::print();
		cout << subject << endl;
	}

};

#define INHERTTANCE_CHECK

void main()
{
#ifdef INHERTTANCE_CHECK
	Human human("Payne", "Max", 30);
	human.print();
	
	Student student("Pinkman", "Jessie", 20, "Chemestry", "WW_220", 95, 97);
	student.print();

	Teacher teacher("White", "Woter", 50, "Chemestry", 25);
	teacher.print();

	Graduate graduate("Scheder", "Hank", 40, "Creminalistic", "OBN", 90, 70, "How to catch haisenberg");
	graduate.print();
#endif

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 20, "Chemestry", "WW_220", 95, 97),
		new Teacher("White", "Woter", 50, "Chemestry", 25),
		new Graduate("Scheder", "Hank", 40, "Creminalistic", "OBN", 90, 70, "How to catch haisenberg"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 98, 95),
		new Teacher("Diaz", "Ricardo", 40, "Weapons dixtribuktion", 25)
	};

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << DELIMITR;
	}
	
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		cout << DELIMITR;
		delete group[i];
	}
	
}