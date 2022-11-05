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

//Funkcija ivesciai is failo, list versija.
list<Student> fileInputList(string);

//Atlieka surusiavima pagal nustatyta faktoriu, list versija.
list<Student> sortList(list<Student>);


//surusiuoja studentus i dvi kategorijas, list versija.
vector<list<Student>> sortStudentsByGradeList(list<Student>);
 
//iraso surusiuotus duomenis i du failus, list versija.
void writeSortedStudentsList(vector<list<Student>>, string, string);

//Funkcija ivesciai is failo, deque versija.
deque<Student> fileInputDeque(string);

//Atlieka surusiavima pagal nustatyta faktoriu, deque versija.
deque<Student> sortDeque(deque<Student>);


//surusiuoja studentus i dvi kategorijas, deque versija.
vector<deque<Student>> sortStudentsByGradeDeque(deque<Student>);

//iraso surusiuotus duomenis i du failus, deque versija.
void writeSortedStudentsDeque(vector<deque<Student>>, string, string);

//Testavimo funkcija skirtingiems konteineriams.
void testProgramContainers(int, string);

//Rusiavimo versija vektoriui sukuriant du naujus konteinerius
vector<vector<Student>> sortStudentsByGrade2(vector<Student>);


//Rusiavimo versija sarasui sukuriant du naujus konteinerius
vector<list<Student>> sortStudentsByGradeList2(list<Student>);

//Rusiavimo versija deque sukuriant du naujus konteinerius
vector<deque<Student>> sortStudentsByGradeDeque2(deque<Student>);