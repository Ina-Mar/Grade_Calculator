#pragma once
#include "Libraries.h"

//Programos versija su dinaminiu masyvu.
class StudentA
{
	string name, last_name;
	static char choose;
	int* hw;
	int exam;
	int s = 500;
	float final() const;
	
	//Metodas, kuris sutraukia masyva iki aktualaus dydzio
	void arraySize();

public:
	StudentA();
	StudentA(string, string, int*, int);
	~StudentA();
	StudentA(const StudentA& original);
	StudentA& operator=(const StudentA& original);
	friend ostream& operator<<(ostream& output, const StudentA& st);
	friend istream& operator>>(istream& input, StudentA& st);
	static void setCountingMethod(char);
};

