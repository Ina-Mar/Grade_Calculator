#pragma once
#include "Libraries.h"

//Programos versija su vektoriumi.
class Student
{
	string name, last_name;
	static char choose;
	vector<int> hw;
	int exam;
	//float final_grade;
	float final() const;
	//void setFinal() const;
public:
	Student();
	Student(string, string, vector<int>, int);
	~Student();
	Student(const Student& original);
	Student& operator=(const Student& original);
	friend ostream& operator<<(ostream& output, const Student& st);
	friend istream& operator>>(istream& input, Student& st);
	static void setCountingMethod(char);
	bool operator<(const Student& other);
	//bool operator>(const Student& other);
	float getFinal() const;

};

