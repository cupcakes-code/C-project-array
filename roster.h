
#pragma once

#include "degree.h"
#include "Students.h"
#include <string>

using namespace std;

// change 2
class Roster
{
private:
	int lastIndex = -1;
	const static int arraySize = 5;
	int numberOfElements = 0; // Number of students in the array
public:
	Student* classRosterArray[arraySize];

public:
	void add(string studentID,
		string fname,
		string lname,
		string email,
		int age,
		double days1,
		double days2,
		double days3,
		DegreeType dt);
	void printAll();
	void printByDegreeProgram(DegreeType dt);
	void printAverageDaysInCourse(string studentID);
	void remove(string studentID);
	void printInvalidEmails();
	~Roster();

};

