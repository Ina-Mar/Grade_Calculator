
#include "AdditionalFunctions.h"

void randomFileOutput(int num_entries, int num_grades, string file_name) {

    string name;
    ofstream out_f(file_name);
    out_f << "Vardas" << setw(23) << "Pavarde";
    for (int i = 1; i <= num_grades; i++) {
        out_f << right << setw(12) << "ND" + to_string(i);


    }
    out_f << setw(12) << "Egz." << "\n";
    vector<int> r_grades;
    for (int j = 1; j <= num_entries; j++) {
        name = "Pavarde" + to_string(j);
        r_grades = randomGrades(num_grades + 1);
        out_f << "Vardas" + to_string(j) << setw(31 - name.length()) << right << name;
        for (int y = 0; y < r_grades.size(); y++) {
            out_f << setw(12) << r_grades[y];
        }
        out_f << "\n";
        r_grades.clear();
    }
    out_f.close();
}

vector<vector<Student>> sortStudentsByGrade(vector<Student> students) {
    sort(students.begin(), students.end(), compareFinal);
    vector<Student> tinkers;
    vector<vector<Student>> all_students;
    for (int i = students.size() - 1; i >= 0; i--) {
        if (students[i].getFinal() >= 5) {
            tinkers.push_back(students[i]);
            students.pop_back();
        }
    }
    all_students.push_back(tinkers);
    all_students.push_back(students);
    return all_students;


}

void testProgram(int num_lines) {
    string f_name = "student" + to_string(num_lines) + ".txt";
    string f_good_students = "fine" + to_string(num_lines) + ".txt";
    string f_bad_students = "poor" + to_string(num_lines) + ".txt";
    cout << "Failas su " + to_string(num_lines) + " eiluciu" << endl;
    auto start = high_resolution_clock::now(); auto st = start;
    randomFileOutput(num_lines, 15, f_name);
    cout << "Sukurtas failas " + f_name << endl;
    auto end = std::chrono::high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "Failo generavimas uztruko: " << diff.count() << " s\n";


    start = high_resolution_clock::now();
    vector <Student> student_v;
    student_v = fileInput(f_name);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Duomenu nuskaitymas is failo uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    vector<vector<Student>> studs;
    studs = sortStudentsByGrade(student_v);
    student_v.clear();
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();

    writeSortedStudents(studs, f_good_students, f_bad_students);
    cout << "Sukurti failai " + f_good_students + ", " + f_bad_students << endl;
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Irasymas i failus uztruko: " << diff.count() << " s\n";


}

list<Student> fileInputList(string f_name) {
    string line;
    string appended_line;
    vector<string> line_vector;
    stringstream f_buffer;


    try {
        ifstream open_f(f_name);
        if (open_f.fail()) {
            throw exception("Dokumentas nerastas");
        }


        while (open_f) {
            if (!open_f.eof()) {
                getline(open_f, line);
                if (!(line == "")) {
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
    list<Student>::iterator iter;
    iter = st_list.begin();
    for (int i = 1; i < num_lines; i++) {
        line = line_vector[i];
        appended_line = line.append(delimiter);
        istringstream new_stream(appended_line);
        new_stream >> *iter;
        iter++;
    }

    return st_list;
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

void writeSortedStudentsList(vector<list<Student>> all, string f_good, string f_bad) {
    ofstream out_f1(f_good);
    ofstream out_f2(f_bad);

    out_f1 << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis" << endl;
    out_f1 << "-------------------------------------------" << endl;
    out_f2 << setw(15) << left << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis" << endl;
    out_f2 << "-------------------------------------------" << endl;

    for (auto const& i : all[0]) {
        out_f1 << i << endl;
    }
    for (auto const& y : all[1]) {
        out_f2 << y << endl;
    }
    out_f1.close();
    out_f2.close();
}

deque<Student> fileInputDeque(string f_name) {
    string line;
    string appended_line;
    vector<string> line_vector;
    stringstream f_buffer;


    try {
        ifstream open_f(f_name);
        if (open_f.fail()) {
            throw exception("Dokumentas nerastas");
        }


        while (open_f) {
            if (!open_f.eof()) {
                getline(open_f, line);
                if (!(line == "")) {
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
    deque<Student> st_deque(num_lines - 1);
    string delimiter = " 0";
    for (int i = 1; i < num_lines; i++) {
        line = line_vector[i];
        appended_line = line.append(delimiter);
        istringstream new_stream(appended_line);
        new_stream >> st_deque[static_cast<deque<Student, allocator<Student>>::size_type>(i) - 1];

    }
    return st_deque;
}


deque<Student> sortDeque(deque<Student> students) {
    sort(students.begin(), students.end(), compareFinal);
    return students;
}

vector<deque<Student>> sortStudentsByGradeDeque(deque<Student> students) {
    students = sortDeque(students);
    deque<Student> tinkers;
    vector<deque<Student>> all_students;
    for (int i = students.size() - 1; i >= 0; i--) {
        if (students[i].getFinal() >= 5) {
            tinkers.push_back(students[i]);
            students.pop_back();
        }
    }
    all_students.push_back(tinkers);
    all_students.push_back(students);
    return all_students;


}
void writeSortedStudentsDeque(vector<deque<Student>> all, string f_good, string f_bad) {
    ofstream out_f1(f_good);
    ofstream out_f2(f_bad);

    out_f1 << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis" << endl;
    out_f1 << "-------------------------------------------" << endl;
    out_f2 << setw(15) << left << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis" << endl;
    out_f2 << "-------------------------------------------" << endl;

    for (Student st : all[0]) {
        out_f1 << st << endl;
    }
    for (Student st2 : all[1]) {
        out_f2 << st2 << endl;
    }
    out_f1.close();
    out_f2.close();
    all.clear();
}
void testProgramContainers(string file_name) {
    cout << "Nuskaitomas failas "+file_name << endl;
    auto start = high_resolution_clock::now(); auto st = start;
    vector<Student> student_v;
    student_v = fileInput(file_name);
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "Failo nuskaitymas i vektoriu uztruko: " << diff.count() << " s\n";


    start = high_resolution_clock::now();
    list <Student> student_l;
    student_l = fileInputList(file_name);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Failo nuskaitymas i sarasa uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    deque <Student> student_d;
    student_d = fileInputDeque(file_name);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Failo nuskaitymas i deque uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    vector<vector<Student>> studs;
    studs = sortStudentsByGrade(student_v);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i vektorius uztruko: " << diff.count() << " s\n";


    start = high_resolution_clock::now();
    vector<list<Student>> studs_l;
    studs_l = sortStudentsByGradeList(student_l);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i sarasus uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    vector<deque<Student>> studs_d;
    studs_d = sortStudentsByGradeDeque(student_d);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i deque uztruko: " << diff.count() << " s\n";


}

vector<list<Student>> sortStudentsByGradeList2(list<Student> students) {
    //pazangiu studentu sarasas
    list<Student> tailors;
    //prastu studentu sarasas
    list<Student> tinkers;
    vector<list<Student>> all_students;
    list<Student>::iterator iter;
    for (iter = students.begin(); iter != students.end(); ++iter) {
        if (iter->getFinal() < 5) {
            tinkers.push_back(*iter);

        }
        else {
            tailors.push_back(*iter);
        }
    }

    all_students.push_back(tailors);
    all_students.push_back(tinkers);
    students.clear();
    return all_students;
}

vector<deque<Student>> sortStudentsByGradeDeque2(deque<Student> students) {
    //pazangiu studentu deque
    deque<Student> tailors;
    //prastu studentu deque
    deque<Student> tinkers;
    vector<deque<Student>> all_students;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getFinal() >= 5) {
            tailors.push_back(students[i]);
        }
        else {
            tinkers.push_back(students[i]);
        }
    }
    all_students.push_back(tailors);
    all_students.push_back(tinkers);
    students.clear();
    return all_students;
}

void testSorting(string f_name) {
    vector<Student> students;
    students = fileInput(f_name);
    vector<vector<Student>> stude;
    auto start = high_resolution_clock::now(); auto st = start;
    stude = sortStudentsByGrade(students);
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "Studentu rusiavimas i viena vektoriu uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    stude = sortStudentsByGrade2(students);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i du vektorius uztruko: " << diff.count() << " s\n";



    list<Student> st_li = fileInputList(f_name);
    vector<list<Student>> studl;
    start = high_resolution_clock::now();
    studl = sortStudentsByGradeList(st_li);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i viena sarasa uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    studl = sortStudentsByGradeList2(st_li);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i du sarasus uztruko: " << diff.count() << " s\n";


    deque<Student> st_d;
    vector<deque<Student>> studd;
    st_d = fileInputDeque(f_name);

    start = high_resolution_clock::now();
    studd = sortStudentsByGradeDeque(st_d);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i viena deque uztruko: " << diff.count() << " s\n";


    start = high_resolution_clock::now();
    studd = sortStudentsByGradeDeque2(st_d);
    end = high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i du deque uztruko: " << diff.count() << " s\n";


}

void testing() {
    char choice;
    string f_name;
    cout << "Pasirinkite failu kurima ir rusiavima i naujus failus(P), rusiavima naudojant skirtingus konteinerius(C) arba skirtingas rusiavimo strategijas(S)" << endl;
    cin >> choice;
    if (choice == 'P' || choice == 'p') {
        int num_lines;
        cout << "Parasykite norima failo eiluciu kieki: ";
        cin >> num_lines;
        testProgram(num_lines);
    }
    else if (choice == 'C' || choice == 'c') {
        cout << "Pateikite failo varda: ";
        cin >> f_name;
        testProgramContainers(f_name);

    }
    else if (choice == 'S' || choice == 's') {
        cout << "Pateikite failo varda: ";
        cin >> f_name;
        testSorting(f_name);
    }
    else {
        cout << "Netinkama ivestis" << endl;
    }
}

bool compareFinal(Student st1, Student st2) {
    return st1.getFinal() < st2.getFinal();
}