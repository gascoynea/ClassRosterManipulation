#include "student.h"
#include <iostream>
#include <string>
#include <array>
#include "degree.h"

using namespace std;

// Implementation of the student class
student::student() {}
student::~student() {}

student::student(string inStudentID, string inFirstName, string inLastName, string inEmailAddress, int inAge, int inDaysInCourse[], DegreeProgram inDegreeProgram)
{
    this->studentID = inStudentID;
    this->firstName = inFirstName;
    this->lastName = inLastName;
    this->emailAddress = inEmailAddress;
    this->age = inAge;
    this->daysInCourse[0] = inDaysInCourse[0];
    this->daysInCourse[1] = inDaysInCourse[1];
    this->daysInCourse[2] = inDaysInCourse[2];
    this->degreeProgram = inDegreeProgram;
}

void student::print()
{
    cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << age;
    cout << "\tdaysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\tDegree Program: ";
    if (degreeProgram == DegreeProgram::NETWORK)
        cout << "NETWORK" << endl;
    else if (degreeProgram == DegreeProgram::SECURITY)
        cout << "SECURITY" << endl;
    else if (degreeProgram == DegreeProgram::SOFTWARE)
        cout << "SOFTWARE" << endl;
}

string student::getStudentID()
{
    return studentID;
}

void student::setStudentID(string inStudentID)
{
    this->studentID = inStudentID;
}

string student::getFirstName()
{
    return firstName;
}

void student::setFirstName(string inFirstName)
{
    this->firstName = inFirstName;
}

string student::getLastName()
{
    return lastName;
}

void student::setLastName(string inLastName)
{
    this->lastName = inLastName;
}

string student::getEmailAddress()
{
    return emailAddress;
}

void student::setEmailAddress(string inEmailAddress)
{
    this->emailAddress = inEmailAddress;
}

int student::getAge()
{
    return age;
}

void student::setAge(int inAge)
{
    this->age = inAge;
}

int* student::getDaysInCourse()
{
    return daysInCourse;
}

void student::setDaysInCourse(int inDaysInCourse[])
{
    this->daysInCourse[0] = inDaysInCourse[0];
    this->daysInCourse[1] = inDaysInCourse[1];
    this->daysInCourse[2] = inDaysInCourse[2];
}

DegreeProgram student::getDegreeProgram()
{
    return degreeProgram;
}

void student::setDegreeProgram(DegreeProgram inDegreeProgram)
{
    this->degreeProgram = inDegreeProgram;
}

