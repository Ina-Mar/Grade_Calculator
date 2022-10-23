#include "Student.h"

char Student::choose = 'V';
Student::Student() {
	name = "";
	last_name = "";
	exam = 0;

}
Student::Student(string name, string last_name, vector<int> hw, int exam) {
	this->name = name;
	this->last_name = last_name;
	this->hw = hw;
	this->exam = exam;
}
Student::~Student() {

}
Student::Student(const Student& original) {
	name = original.name;
	last_name = original.last_name;
	hw = original.hw;
	exam = original.exam;
}
Student& Student::operator=(const Student& original) {
	if (this != &original) {
		name = original.name;
		last_name = original.last_name;
		hw = original.hw;
		exam = original.exam;
	}
	return *this;
}

float Student::final() const {

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
void Student::setCountingMethod(char a) {
	choose = a;

}
ostream& operator<<(ostream& output, const  Student& st) {
	output << setw(15) << left << st.name << setw(15) << left << st.last_name << setw(15) << left << fixed
		<< setprecision(2) << st.final();
	return output;


}
istream& operator>>(istream& input, Student& st) {
	int grade;
	int term = -1;
	printf("Iveskite studento varda ir pavarde\n");
	input >> st.name >> st.last_name;
	printf("iveskite studento pazymius. Baikite ivedima ivesdami -1\n");

	while ((input >> grade) && grade != term) {
		st.hw.push_back(grade);
	}
	printf("Iveskite egzamino rezultata\n");
	input >> st.exam;
	//last_num = st.hw.size() - 1;
	//st.exam = st.hw[last_num];
	//st.hw.pop_back();
	return input;
}