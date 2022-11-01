#include "Student.h"
#include "libraries.h"
#include "StudentA.h"
#include "Functions.h"



int main()
{
    char choice;
    cout << "Pasirinkite failu kurimo ir irasymo testavima(T) arba konteineriu testavima(K)"<<endl;
    cin >> choice;
    if (choice == 'T' || choice == 't') {
        testProgram(1000);
        testProgram(10000);
        testProgram(100000);
        //testProgram(1000000);
        //testProgram(10000000);
    }
   
    else if (choice == 'K' || choice == 'k') {
        testProgramContainers(1000, "student1000.txt");
        testProgramContainers(10000, "student10000.txt");
        testProgramContainers(100000, "student100000.txt");
        //testProgramContainers(1000000, "student1000000.txt");
        //testProgramContainers(10000000, "student10000000.txt");
    }
    
}



