// main.cpp
// This file contains the program entry point (main())

#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"
#include<vector>
#include<sstream>

using namespace std;

// This is the program entry point
int main()
{
    // Output project info
    cout << "Scripting and programming - applications -- C867" << endl;
    cout << "JYM1 Task 1: Class Roster" << endl;
    cout << "Written in C++" << endl;
    cout << "By Adam Gascoyne #001254864" << endl;
    cout << endl;

    // Student data as listed in rubric
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Adam,Gascoyne,gascoynea@yahoo.com,25,30,29,30,SOFTWARE" };

    // Create a roster object
    roster myClass = roster();

    // Add students from studentData "table" to the roster

    // Get length of array
    int len = *(&studentData + 1) - studentData;

    // Loop over array
    for (int i = 0; i < len; i++)
    {
        // Split the current string by comma, into a vector
        vector<string> result;
        stringstream s_stream(studentData[i]);
        while (s_stream.good()) {
            string substr;
            getline(s_stream, substr, ',');
            result.push_back(substr);
        }

        string studentID = result.at(0);
        string firstName = result.at(1);
        string lastName = result.at(2);
        string emailAddress = result.at(3);
        int age = stoi(result.at(4));
        int daysInCourse1 = stoi(result.at(5));
        int daysInCourse2 = stoi(result.at(6));
        int daysInCourse3 = stoi(result.at(7));
        DegreeProgram degreeProgram = DegreeProgram::SECURITY;
        if (result.at(8) == "NETWORK")
            degreeProgram = DegreeProgram::NETWORK;
        if (result.at(8) == "SOFTWARE")
            degreeProgram = DegreeProgram::SOFTWARE;

        // Call roster.add() for this student
        myClass.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }


    cout << "Printing roster:" << endl;
    myClass.printAll();
    cout << endl;

    cout << "Checking for invalid emails:" << endl;
    myClass.printInvalidEmails();
    cout << endl;

    cout << "Printing AverageDaysInCourse:" << endl;
    for (int i = (myClass.numStudents - 1); i >= 0; i--)
    {
        myClass.printAverageDaysInCourse(myClass.classRosterArray[i].getStudentID());
        cout << endl;
    }
    cout << endl;

    cout << "Students in Degree Program SOFTWARE:" << endl;
    myClass.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;

    cout << "Removing StudentID A3: ";
    myClass.remove("A3");
    cout << endl;

    cout << "Printing roster:" << endl;
    myClass.printAll();
    cout << endl;

    cout << "Removing StudentID A3: ";
    myClass.remove("A3");
    cout << endl;

    cout << "Project complete.";
    int pause; cin >> pause;
}


