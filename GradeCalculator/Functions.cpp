# include "Functions.h";


vector<int> randomGrades(int n) {
    using rClock = high_resolution_clock;
    int random_grade;
    vector<int> grades;
    mt19937 mt(static_cast<long unsigned int>(rClock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dist(1, 10);
    for (int i = 0; i < n; i++) {
        random_grade = dist(mt);
        grades.push_back(random_grade);
    }
    return grades;
}

vector<Student> consoleInput() {
    int n_inputs;
    printf("Pasirinkite, keliu studentu pazymius norite ivesti: \n");
    scanf_s("%d", &n_inputs);
    vector<Student> students(n_inputs);
    for (int i = 0; i < n_inputs; i++) {
        printf("Iveskite studento duomenis (noredami baigti ivedima iveskite 0.)\n");
        cin >> students[i];
    }
    students = sortVector(students);
    return students;
}

vector<Student> fileInput(string f_name) {
    string line;
    string appended_line;
    vector<string> line_vector;
    

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
    vector<Student> st_vector(num_lines - 1);
    string delimiter = " 0";
    for (int i = 1; i < num_lines; i++) {
        line = line_vector[i];
        appended_line = line.append(delimiter);
        istringstream new_stream(appended_line);
        new_stream >> st_vector[static_cast<vector<Student, allocator<Student>>::size_type>(i) - 1];

    }
    st_vector = sortVector(st_vector);
    return st_vector;
}

vector<Student> sortVector(vector<Student> students) {
    sort(students.begin(), students.end());
    return students;
}

void inputProgram() {
    char input;
    char a;
    char s;
    char o;
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
    cout << "Pasirinkite, ar duomenis isvesti i konsole(C), ar i failus(F)." << endl;
    cout << "Dideles apimties duomenims rekomenduojamas isvedimas i failus" << endl;
    cin >> o;
    if (o == 'C' || o == 'c') {
        consoleOutput(a, stud);
    }
    else if (o == 'F' || o == 'f') {
        fileOutput(stud, a);
    }
    
    
}







void writeSortedStudents(vector<vector<Student>> all, string f_good, string f_bad) {
    ofstream out_f1(f_good);
    ofstream out_f2(f_bad);
    out_f1 << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis" << endl;
    out_f1 << "-------------------------------------------" << endl;
    out_f2 << setw(15) << left << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis" << endl;
    out_f2 << "-------------------------------------------" << endl;

    
    for (int j = 0; j < all[0].size(); j++) {
        out_f1 << all[0][j] << endl;
    }
    for (int y = 0; y < all[1].size(); y++) {
        out_f2 << all[1][y] << endl;
    }
    out_f1.close();
    out_f2.close();
    cout << "Pazangiu studentu duomenys irasyti i: " + f_good << endl;
    cout << "Prastu studentu duomenys irasyti i: " + f_bad << endl;
}



vector<vector<Student>> sortStudentsByGrade2(vector<Student> students) {
    // pazangiu studentu vektorius
    vector<Student> tailors;

    //prastu studentu vektorius
    vector<Student> tinkers;

    vector<vector<Student>> all_students;
    int num = count_if(students.begin(), students.end(), [](Student stu) {
        return stu.getFinal() >= 5;
    });
    tailors.resize(num);
    tinkers.resize(students.size() - num);
    partition_copy(students.begin(), students.end(), tailors.begin(), tinkers.begin(), [](Student stu) {
        return stu.getFinal() >= 5;
        }
    );
    
    all_students.push_back(tailors);
    all_students.push_back(tinkers);
    students.clear();
    return all_students;
}

void consoleOutput(char a, vector<Student> students) {
    if ((a == 'v') || (a == 'V')) {
        cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis(Vid.)" << endl;
    }
    else if ((a == 'm') || (a == 'M')) {
        cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis(Med.)" << endl;
    }



    for (int i = 0; i < students.size(); i++) {
        cout << students[i] << endl;
    }

}

void fileOutput(vector<Student> students, char a) {
    vector<vector<Student>> all_students;
    string f_good_students;
    string f_bad_students;
    char choice;
    cout << "Ar norite nurodyti isvesties failu vardus? (T/N)" << endl;
    cin >> choice;
    if (choice == 'n' || choice == 'N') {
        cout << "Bus naudojami numatytieji failai" << endl;
        f_good_students = "goodstudents.txt";
        f_bad_students = "poorstudents.txt";
    }
    else if (choice == 't' || choice == 'T') {
        string format = ".txt";
        cout << "Irasykite pavadinima failo pazangiems studentams: ";
        cin >> f_good_students;
        cout << "Irasykite pavadinima failo prastiems studentams: ";
        cin  >> f_bad_students;
        if ((f_good_students.find(format) == string::npos || f_bad_students.find(format) == string::npos)) {
            cout << "Netinkamas failu formatas" << endl;
            cout << "Bus naudojami numatytieji failai" << endl;
            f_good_students = "goodstudents.txt";
            f_bad_students = "poorstudents.txt";
        }
        all_students = sortStudentsByGrade2(students);
        writeSortedStudents2(all_students, f_good_students, f_bad_students, a);
    }


}

void writeSortedStudents2(vector<vector<Student>> all, string f_good, string f_bad, char a) {
    ofstream out_f1(f_good);
    ofstream out_f2(f_bad);
    if (a == 'v' || a == 'V') {
        out_f1 << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis(Vid.)" << endl;
        out_f1 << "-------------------------------------------" << endl;
        out_f2 << setw(15) << left << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis(Vid.)" << endl;
        out_f2 << "-------------------------------------------" << endl;

    }
    else if (a == 'M' || a == 'm') {
        out_f1 << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis(Med.)" << endl;
        out_f1 << "-------------------------------------------" << endl;
        out_f2 << setw(15) << left << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis(Med.)" << endl;
        out_f2 << "-------------------------------------------" << endl;
    }


    for (int j = 0; j < all[0].size(); j++) {
        out_f1 << all[0][j] << endl;
    }
    for (int y = 0; y < all[1].size(); y++) {
        out_f2 << all[1][y] << endl;
    }
    out_f1.close();
    out_f2.close();
    cout << "Pazangiu studentu duomenys irasyti i: " + f_good << endl;
    cout << "Prastu studentu duomenys irasyti i: " + f_bad << endl;
}
