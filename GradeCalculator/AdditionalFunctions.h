#pragma once

#include "Libraries.h"
#include "Student.h"
#include "Functions.h"

//Sukuria norimo dydzio dokumenta su atsitiktinai generuotu studentu sarasu.
void randomFileOutput(int, int, string);

//surusiuoja studentus i dvi kategorijas.
vector<vector<Student>> sortStudentsByGrade(vector<Student>);
 
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
void testProgramContainers(string);

//Rusiavimo versija sarasui sukuriant du naujus konteinerius
vector<list<Student>> sortStudentsByGradeList2(list<Student>);

//Rusiavimo versija deque sukuriant du naujus konteinerius
vector<deque<Student>> sortStudentsByGradeDeque2(deque<Student>);

//Konteineriu rusiavimas pagal dvi strategijas
void testSorting(string);

//Leidzia pasirinkti norimus atlikti testus
void testing();

//finalGrade() funkcijos palyginimo operatorius
bool compareFinal(Student st1, Student st2);