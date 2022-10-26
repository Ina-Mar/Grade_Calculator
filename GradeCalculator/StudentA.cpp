#include "StudentA.h"

char StudentA::choose = 'V';
StudentA::StudentA() {
	name = "";
	last_name = "";
	hw = new int[s];
	for (int i = 0; i < s; i++) {
		hw[i] = 0;
	}
	exam = 0;

}
StudentA::StudentA(string name, string last_name, int* hw, int exam) {
	this->name = name;
	this->last_name = last_name;
	this->hw = new int[1000];
	this->exam = exam;
}
StudentA::~StudentA() {
	delete[] hw;
}
StudentA::StudentA(const StudentA& original) {

	s = original.s;
	hw = new int[s];
	for (int i = 0; i < s; i++) {
		hw[i] = original.hw[i];
	}
	name = original.name;
	last_name = original.last_name;
	exam = original.exam;
}
StudentA& StudentA::operator=(const StudentA& original) {
	if (this != &original) {
		name = original.name;
		last_name = original.last_name;
		delete[] hw;
		s = original.s;
		hw = new int[s];
		for (int i = 0; i < s; i++) {
			hw[i] = original.hw[i];
		}
		exam = original.exam;
	}
	return *this;
}
void StudentA::arraySize() {
	int full = 0;
	for (int i = 0; i < s; i++) {
		if (hw[i] != 0) {
			full += 1;
		}
	}
	int* hw2 = new int[full];
	for (int j = 0; j < full; j++) {
		hw2[j] = hw[j];
	}

	delete[] hw;
	hw = hw2;
	s = full;
	//printf("%d", s);
}

float StudentA::final() const {

	float fin, sum;
	fin = 0;

	if ((choose == 'V') || (choose == 'v')) {
		sum = 0;
		for (int i = 0; i < s; i++) {
			sum += hw[i];
		}
		fin = ((sum * 1.0) / s) * 0.4 + exam * 0.6;
	}
	else if ((choose == 'M') || (choose == 'm')) {
		int medium_ind;
		sort(hw, hw + s);
		if (s % 2 != 0) {
			medium_ind = ((s + 1) / 2) - 1;
			sum = (float)hw[medium_ind];
		}
		else {
			medium_ind = (s / 2) - 1;
			sum = (float)((hw[medium_ind] + hw[medium_ind + 1]) / (2 * 1.0));
		}
		fin = sum * 0.4 + exam * 0.6;
	}

	return fin;
}
void StudentA::setCountingMethod(char a) {
	choose = a;

}
ostream& operator<<(ostream& output, const  StudentA& st) {
	output << setw(15) << left << st.name << setw(15) << left << st.last_name << setw(15) << left << fixed
		<< setprecision(2) << st.final();
	return output;


}
istream& operator>>(istream& input, StudentA& st) {
	int grade, iter;
	int term = -1;
	iter = 0;
	printf("Iveskite studento varda ir pavarde\n");
	input >> st.name >> st.last_name;
	printf("iveskite studento pazymius. Baikite ivedima ivesdami -1\n");

	while ((input >> grade) && grade != term) {
		st.hw[iter] = grade;
		iter++;


	}
	st.arraySize();
	printf("Ivekite egzamino rezultata\n");
	input >> st.exam;
	return input;
}
