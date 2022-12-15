#pragma once

#include "Libraries.h"
#include "Student.h"


//Funkcija ivesciai is failo, list versija.
list<Student> fileInputList(string);

//Atlieka surusiavima pagal nustatyta faktoriu, list versija.
list<Student> sortList(list<Student>);


//surusiuoja studentus i dvi kategorijas, list versija.
vector<list<Student>> sortStudentsByGradeList(list<Student>);

//finalGrade() funkcijos palyginimo operatorius
bool compareFinal(Student st1, Student st2);


list<Student> fileInputList(string f_name) {
    wstring line;
    wstring appended_line;
    vector<wstring> line_vector;
    //stringstream f_buffer;


    try {
        std::wifstream open_f(f_name);
        open_f.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
        if (open_f.fail()) {
            throw exception("Dokumentas nerastas");
        }


        while (open_f) {
            if (!open_f.eof()) {
                getline(open_f, line);
                if (!(line.empty())) {
                    line_vector.push_back(line);
                }

            }
            else break;
        }
        open_f.close();
    }
    catch (exception& e) {
        cout << e.what() << endl;
        exit(0);

    }

    int num_lines = line_vector.size();
    list<Student> st_list(num_lines - 1);
    string delimiter = " 0";
    wstring wDelimiter = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(delimiter);
    list<Student>::iterator iter;
    iter = st_list.begin();
    for (int i = 1; i < num_lines; i++) {
        line = line_vector[i];
        appended_line = line.append(wDelimiter);
        std::wistringstream new_stream(appended_line);
        new_stream >> *iter;
        iter++;
    }

    return st_list;
}

bool compareFinal(Student st1, Student st2) {
    return st1.getFinal() < st2.getFinal();
}


list<Student> sortList(list<Student> students) {
    students.sort(compareFinal);
    return students;
}

vector<list<Student>> sortStudentsByGradeList(list<Student> students) {
    students = sortList(students);
    list<Student> tinkers;
    vector<list<Student>> all_students;
    list<Student>::iterator iter;
    iter = students.begin();
    for (int i = 0; i < students.size(); i++) {
        if (iter->getFinal() < 5) {
            tinkers.push_back(*iter);
            iter++;
            students.pop_front();

        }
        else break;
    }

    //students saugo gerus studentus, o tinkers blogus.
    all_students.push_back(students);
    all_students.push_back(tinkers);
    return all_students;
}


char Student::choose = 'V';



