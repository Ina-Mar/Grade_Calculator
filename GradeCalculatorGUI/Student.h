#pragma once
#include "Libraries.h"


class Student
{
	wstring name, last_name;
	static char choose;
	vector<int> hw;
	int exam;

public:
	Student() {}
	Student(wstring name, wstring last_name, vector<int> hw, int exam) {
		this->name = name;
		this->last_name = last_name;
		this->hw = hw;
		this->exam = exam;
	}
	~Student() {}

	Student(const Student& original) {
		name = original.name;
		last_name = original.last_name;
		hw = original.hw;
		exam = original.exam;
	}
	Student& operator=(const Student& original) {
		if (this != &original) {
			name = original.name;
			last_name = original.last_name;
			hw = original.hw;
			exam = original.exam;
		}
		return *this;
	}

	float final() const {

		float fin, sum;
		int num_of_grades;
		fin = 0;
		num_of_grades = hw.size();
		if ((choose == 'V') || (choose == 'v')) {
			sum = 0;
			for (int i = 0; i < num_of_grades; i++) {
				sum += hw[i];
			}
			fin = ((sum * 1.0) / num_of_grades) * 0.4 + exam * 0.6;
		}
		else if ((choose == 'M') || (choose == 'm')) {
			vector<int>hw2 = hw;
			sort(hw2.begin(), hw2.end());
			if (num_of_grades % 2 != 0) {
				sum = hw2[hw.size() / 2];
			}
			else {
				sum = (hw2[hw.size() / 2] + hw2[hw.size() / 2 + 1]) / (2 * 1.0);
			}
			fin = sum * 0.4 + exam * 0.6;
		}

		return fin;
	}
	friend wostream& operator<<(wostream& output, const Student& st) {
		output << setw(15) << left << st.last_name << setw(15) << left << st.name << setw(15) << left << fixed
			<< setprecision(2) << st.getFinal();
		return output;
	}
	friend wistream& operator>>(wistream& input, Student& st) {
		int grade;
		int last_num;
		input >> st.name >> st.last_name;

		while (input >> grade && grade != 0) {
			while (grade < 0 || grade > 10) {
				input.clear();
				input.ignore(numeric_limits<streamsize>::max(), ' ');
				break;
			}
			st.hw.push_back(grade);


		}

		last_num = st.hw.size() - 1;
		st.exam = st.hw[last_num];
		st.hw.pop_back();
		return input;
	}
	static void setCountingMethod(char a) {
		choose = a;
	}
	bool operator<(const Student& other) {
		return last_name < other.last_name;
	}
	float getFinal() const {
		float fin = final();
		return fin;
	}
	


};