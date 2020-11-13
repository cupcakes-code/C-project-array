
#include "degree.h"
#include "Roster.h"
#include "Students.h"


void Roster::add(string studentID,
	string fname,
	string lname,
	string email,
	int age,
	double days1,
	double days2,
	double days3,
	DegreeType dt)
{
	int parr[3] = { days1,days2,days3 };

	classRosterArray[numberOfElements++] = new Student(studentID, lname, fname, email, age, parr, dt);
	//classRosterArray.push_back(new Student(studentID, lname, fname, email, age, parr, dt) );
}

void Roster::printAll()
{
	for (int i = 0; i < numberOfElements; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numberOfElements; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << static_cast<double>(classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3.0;
		}
	}
}

void Roster::remove(string studentID) {
	bool success = false;

	for (int i = 0; i < numberOfElements; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			//delete memory holding the class object
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			//shuffle the elements back so that the empty
			//array slots are at the end of the array
			numberOfElements--;
			while (i < numberOfElements) {
				classRosterArray[i] = classRosterArray[i + 1];
				i++;
			}
			classRosterArray[numberOfElements] = nullptr;
			success = true;
			break;
		}
	}

	if (success)
	{
		cout << studentID << " removed from repository." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << "not found." << std::endl << std::endl;
}

void Roster::printInvalidEmails()
{
	string email;
	int pos = 0;
	//A valid email should include an at sign('@') and period('.') and should not include a space(' ').
	cout << "The Invalid Emails Are: " << endl;
	for (int i = 0; i < numberOfElements; i++) {
		email = classRosterArray[i]->getEmail();
		if (email.find('@') == -1 || email.find('.') == -1 || email.find(' ') != -1)
		{
			cout << "  " << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeType dt)
{
	cout << "Students Working Toward " << degreeTypeStrings[static_cast<int>(dt)] << " degree:\n";
	for (int i = 0; i < numberOfElements; i++)
	{
		if (classRosterArray[i]->getDegreeType() == dt) {
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {

	cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl;

	for (int i = 0; i < numberOfElements; i++) {
		cout << "Destroying student #" << i + 1 << std::endl;
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
}






