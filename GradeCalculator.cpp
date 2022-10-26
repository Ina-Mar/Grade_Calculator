#include "Student.h"
#include "libraries.h"
#include "StudentA.h"
#include "Functions.h"



int main()
{
    vector<int> tryit;
    vector<int> tryit2;
    int n = 10;
    tryit = randomGrades(10);
    tryit2 = randomGrades(10);

    for (int i = 0; i < tryit.size(); i++) {
        cout << tryit[i] << endl;
        cout << tryit2[i] << endl;
    }

    /*char a;
    printf("Pasirinkite pazymio skaiciavima pagal vidurki(V) arba pagal mediana(M)\n");
    scanf_s("%c", &a, 1);
    //StudentA::setCountingMethod(a);
    Student::setCountingMethod(a);

    //StudentA st1;
    //tudentA st2;
    Student st3;

    cin >> st3;
    //cin >> st2;
    if ((a == 'v') || (a == 'V')) {
        cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis(Vid.)" << endl;
    }
    else if ((a == 'm') || (a == 'M')) {
        cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis(Med.)" << endl;
    }


    cout << "-------------------------------------------------" << endl;
    cout << st3 << endl;
    //cout << st1 << endl;
    */
}



