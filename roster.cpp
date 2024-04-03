#include "roster.h"
#include "student.h"

using namespace std;

roster::roster()
{
	classRosterArray = new student[5];
}
roster::~roster()
{
	delete[] classRosterArray;
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	student aStudent = student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

	int counter = 0;
	for (int i = 4; i >= 0; i--)
	{
		if (classRosterArray[i].getStudentID().empty())
		{
			counter = i;
		}
	}

	classRosterArray[counter] = aStudent;
	numStudents++;
}

void roster::remove(string studentID)
{
	// Check if studentID exists before attempting to delete
	bool idExists = false;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i].getStudentID() == studentID)
		{
			idExists = true;
		}
	}
	if (!idExists)
	{
		cout << "ID not found in roster." << endl;
		return;
	}
	else
	{
		//numStudents--;
		student* backupClassRosterArray = new student[numStudents];

		const int bufferSize = 5;
		std::copy(classRosterArray, classRosterArray + bufferSize, backupClassRosterArray);
		delete[] classRosterArray;
		classRosterArray = new student[numStudents];
		int newSlot = 0;
		for (int i = 0; i < numStudents; i++)
		{
			if (backupClassRosterArray[i].getStudentID() != studentID)
			{
				classRosterArray[newSlot] = backupClassRosterArray[i];
				newSlot++;
			}

		}
		delete[] backupClassRosterArray;
		numStudents--;
		cout << "Succeeded." << endl;
	}
}

void roster::printAll()
{
	for (int i = 0; i < numStudents; i++)
	{
		classRosterArray[i].print();
	}
}

void roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i].getStudentID() == studentID)
		{
			int* days = classRosterArray[i].getDaysInCourse();
			int avg = ((days[0] + days[1] + days[2]) / 3);
			cout << "Average days in course for: " << classRosterArray[i].getStudentID() << " = " << avg;
		}
	}
}

void roster::printInvalidEmails()
{
	for (int i = 0; i < numStudents; i++)
	{
		bool badEmail = false;
		string email = classRosterArray[i].getEmailAddress();
		if (email.find(' ') < email.length())
			badEmail = true;
		if (email.find('@') >= email.length())
			badEmail = true;
		if (email.find('.') >= email.length())
			badEmail = true;

		if (badEmail)
			cout << "Invalid email for StudentID: " << classRosterArray[i].getStudentID() << " (" << classRosterArray[i].getEmailAddress() << ")" << endl;
	}
}

void roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i].getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i].print();
		}
	}
}
