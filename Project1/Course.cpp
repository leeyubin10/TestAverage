#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(const string& coureName, int capacity)
{
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
	studentscore = new double[capacity];
	AverageOfScore = 0;
}

Course::~Course()
{

}

void Course::addStudent(const string& name, double score)
{
	ensureCapacity();
	students[numberOfStudents] = name;
	studentscore[numberOfStudents] = score;
	numberOfStudents++;
}

void Course::dropStudent(const string& name)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		if (students[i] == name)
		{
			for (int j = i; j < numberOfStudents; j++)
			{
				students[j] = students[j + 1];
				studentscore[j] = studentscore[j + 1];
			}
			numberOfStudents--;
		}
	}
}

double Course::getAverageOfScore()
{
	double total = 0;
	for (int i = 0; i < numberOfStudents; i++)
	{
		total += studentscore[i];
	}

	AverageOfScore = total / numberOfStudents;
	return AverageOfScore;
}

void Course::ensureCapacity()
{
	if (capacity <= numberOfStudents)
	{
		double* old = studentscore;
		string* oldest = students;
		capacity = 2 * numberOfStudents;
		studentscore = new double[capacity];
		students = new string[capacity];

		for (int i = 0; i < numberOfStudents; i++)
		{
			studentscore[i] = old[i];
			students[i] = oldest[i];
		}

		delete[] old;
		delete[] oldest;
	}
}