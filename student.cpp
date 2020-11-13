#include "Students.h"
#include "degree.h"
#include "Roster.h"


using namespace std;


//added not needed 10-25

// added class ch 8 section declare class getters first 5 8.14ch  deleted student class

Student::Student()

{
	this->StudentID = "";
	this->fname = "";
	this->lname = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
	this->degreeType = DegreeType::SECURITY;
}

Student::Student(string studentID, string fname, string lname, string email, int age, int days[], DegreeType degreeType)
{
	this->StudentID = studentID;
	this->fname = fname;
	this->lname = lname;
	this->email = email;
	this->age = age;


	for (int i = 0; i < daysArraySize;i++) this->days[i] = days[i];
	this->degreeType = degreeType;
}


Student::~Student() {}

string Student::getStudentID() {
	return StudentID;
}
string Student::getFname() { return fname; }
string Student::getLname() { return lname; }
string Student::getEmail() { return email; }
int Student::getAge() { return age; }
int* Student::getDays() { return days; }
DegreeType Student::getDegreeType() { return degreeType; }


void Student::setStudentID(string ID) { StudentID = ID; }
void Student::setFname(string fname) { this->fname = fname; }
void Student::setLname(string lname) {
	this->lname = lname;
}

void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDegreeType(DegreeType dt) { this->degreeType = dt; }

void Student::print()
{
	cout << left; // Left justify the text
	cout << setw(4) << getStudentID();
	cout << setw(12) << getFname();
	cout << setw(12) << getLname();
	cout << setw(25) << getEmail();
	cout << setw(4) << getDays()[0];
	cout << setw(4) << getDays()[1];
	cout << setw(4) << getDays()[2];
	cout << setw(10) << degreeTypeStrings[static_cast<int>(getDegreeType())] << '\n';
}
