#pragma once

#include "Libraries.h"
#include "Student.h"

//Sukuria vektorių iš atsitiktinai sugeneruotų sveikųjų skaičių.
vector<int> randomGrades(int n);

//Funkcija ivesciai is konsoles.
vector<Student> consoleInput();

//Funkcija ivesciai is failo.
vector<Student> fileInput(string);

//Atlieka surusiavima pagal nustatyta faktoriu.
vector<Student> sortVector(vector<Student>);

//Ivesties is failo arba dokumento funkcija.
void inputProgram();


//Sukuria norimo dydzio dokumenta su atsitiktinai generuotu studentu sarasu.
void randomFileOutput(int, int, string);

//surusiuoja studentus i dvi kategorijas.
vector<vector<Student>> sortStudentsByGrade(vector<Student>);

//iraso surusiuotus duomenis i du failus.
void writeSortedStudents(vector<vector<Student>>, string, string);

//Testavimo programa skirtingo dydzio failams.
void testProgram(int);

