#include <iostream>
#include <iomanip>
#include "Course.h"
using namespace std;

int main()
{
	Course course1("C++ Programming", 10);
	course1.addStudent("A",90);
	course1.addStudent("B",100);
	course1.addStudent("C",95);
	course1.addStudent("D",60);
	course1.addStudent("E",70);
	course1.addStudent("F",50);
	course1.addStudent("G",20);
	course1.addStudent("H",100);
	course1.addStudent("I",98);
	course1.addStudent("J",100);

	cout << "2학년 1반 시험 성적 평균: " << fixed << setprecision(1) << course1.getAverageOfScore() << endl;
}