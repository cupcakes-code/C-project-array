#pragma once

#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

class Student
{
private:
    const static int daysArraySize = 3;

    string StudentID;
    string fname;
    string  lname;
    string  email;
    int age;
    int days[daysArraySize];
    DegreeType degreeType;

public:
    Student();
    Student(string studentID, string fname, string lname, string email, int age, int days[], DegreeType degreeType);
    ~Student();

    string getStudentID();
    string getFname();
    string getLname();
    string getEmail();
    int getAge();

    int* getDays();
    DegreeType getDegreeType();

    void setStudentID(string studentID);
    void setFname(string fname);
    void setLname(string lname);
    void setEmail(string email);
    void setAge(int age);
    void setDegreeType(DegreeType dt);
    void print();
};
