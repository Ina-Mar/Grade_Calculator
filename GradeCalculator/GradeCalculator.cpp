#include "Student.h"
#include "libraries.h"
#include "StudentA.h"
#include "Functions.h"



int main()
{
    char input;
    char a;
    vector<Student> stud;
    cout << "Pasirinkite duomenu ivedima is konsoles(C) arba is failo(F)" << endl;
    cin >> input;
    cout << "Pasirinkite pazymio skaiciavima pagal vidurki(V) arba pagal mediana(M)" << endl;
    cin >> a;
    if ((a == 'V' || a == 'v' || a == 'M' || a == 'm')) {
        Student::setCountingMethod(a);
    }
    else {
        cout << "Neteisingai nurodytas skaiciavimo metodas." << endl;
        cout << "Skaiciuojama bus pagal vidurki." << endl;
        a = 'v';
    }
    if (input == 'C' || input == 'c') {
        stud = consoleInput();
    }
    else if (input == 'F' || input == 'f') {
        string f_name;
        cout << "Iveskite failo varda: " << endl;;
        cin >> f_name;
        stud = fileInput(f_name);
        
    }
    else {
        cout << "Neteisingai nurodytas ivesties metodas." << endl;

    }

    if ((a == 'v') || (a == 'V')) {
        cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis(Vid.)" << endl;
    }
    else if ((a == 'm') || (a == 'M')) {
        cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis(Med.)" << endl;
    }
   

    
    for (int i = 0; i < stud.size(); i++) {
        cout << stud[i] << endl;
    }

    
}



