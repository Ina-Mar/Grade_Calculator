#pragma once
#include "Libraries.h"

class Student
{
	string name, last_name;
	static char choose;
	vector<int> hw;
	int exam;
	float final() const;
public:
	Student();
	Student(string, string, vector<int>, int);
	~Student();
	Student(const Student& original);
	Student& operator=(const Student& original);
	friend ostream& operator<<(ostream& output, const Student& st);
	friend istream& operator>>(istream& input, Student& st);
	static void setCountingMethod(char);

};

