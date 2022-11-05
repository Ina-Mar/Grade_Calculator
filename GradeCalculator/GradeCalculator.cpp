#include "Student.h"
#include "libraries.h"
#include "Functions.h"



int main()
{
    vector<Student> students;
    vector<vector<Student>> stude;
    students = fileInput("student1000.txt");
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    stude = sortStudentsByGrade(students);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Studentu rusiavimas i viena vektoriu uztruko: " << diff.count() << " s\n";
    

    start = std::chrono::high_resolution_clock::now();
    stude = sortStudentsByGrade2(students);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Studentu rusiavimas i du vektorius uztruko: " << diff.count() << " s\n";

    

    list<Student> st_li = fileInputList("student1000.txt");
    vector<list<Student>> studl;
    start = std::chrono::high_resolution_clock::now();
    studl = sortStudentsByGradeList(st_li);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Studentu rusiavimas i viena sarasa uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    studl = sortStudentsByGradeList2(st_li);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Studentu rusiavimas i du sarasus uztruko: " << diff.count() << " s\n";
    
    
    deque<Student> st_d;
    vector<deque<Student>> studd;
    st_d = fileInputDeque("student1000.txt");

    start = std::chrono::high_resolution_clock::now();
    studd = sortStudentsByGradeDeque(st_d);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Studentu rusiavimas i viena deque uztruko: " << diff.count() << " s\n";


    start = std::chrono::high_resolution_clock::now();
    studd = sortStudentsByGradeDeque2(st_d);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Studentu rusiavimas i du deque uztruko: " << diff.count() << " s\n";
    for (int i = 0; i < studd[1].size(); i++) {
        cout << studd[1][i] << endl;
    }

    
}



