#pragma once
#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course
{
public:
	Course(const string& coureName, int capacity);
	~Course();
	void addStudent(const string& name, double score);
	void dropStudent(const string& name);
	double getAverageOfScore();
	void ensureCapacity();

private:
	string courseName;
	string* students;
	double* studentscore;
	int numberOfStudents;
	int capacity;
	double AverageOfScore;
};

#endif