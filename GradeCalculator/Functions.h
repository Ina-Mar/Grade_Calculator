#pragma once

#include "Libraries.h"
#include "Student.h"
#include "AdditionalFunctions.h"


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

//iraso surusiuotus duomenis i du failus.
void writeSortedStudents(vector<vector<Student>>, string, string);

//Rusiavimo versija vektoriui sukuriant du naujus konteinerius
vector<vector<Student>> sortStudentsByGrade2(vector<Student>);

//Duomenu isvedimo i konsole funkcija
void consoleOutput(char, vector<Student>);

//Duomenu isvedimo i failus funkcija
void fileOutput(vector<Student>, char);

//Versija inputProgram() funkcijai
void writeSortedStudents2(vector<vector<Student>>, string, string, char);