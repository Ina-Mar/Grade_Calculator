#pragma once

#include "Libraries.h"
#include "Student.h"

//Sukuria vektorių iš atsitiktinai sugeneruotų sveikųjų skaičių.
vector<int> randomGrades(int n);

//Funkcija ivesciai is konsoles.
vector<Student> consoleInput();

//Funkcija ivesciai is failo.
vector<Student> fileInput(string);

//Atlieka surusiavima pagal studentu pavardes.
vector<Student> sortVector(vector<Student>);

