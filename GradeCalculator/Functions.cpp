# include "Functions.h";


vector<int> randomGrades(int n) {
    //Sios komandos neleidzia naudoti be std, net ir apibrezus "libraries.h"
    using rClock = std::chrono::high_resolution_clock;
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
    stringstream f_buffer;
    

    try {
        ifstream open_f(f_name);
        if (open_f.fail()) {
            throw exception("Dokumentas nerastas");
        }
        f_buffer << open_f.rdbuf();
        open_f.close();
        while (f_buffer) {
            if (!f_buffer.eof()) {
                getline(f_buffer, line);
                if (!(line == "")) {
                    line_vector.push_back(line);
                }

            }
            else break;
        }
        //open_f.close();
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
        new_stream >> st_vector[static_cast<std::vector<Student, std::allocator<Student>>::size_type>(i) - 1];

    }
    //st_vector = sortVector(st_vector);
    //sort(st_vector.begin(), st_vector.end());
    return st_vector;
}

vector<Student> sortVector(vector<Student> students) {
    sort(students.begin(), students.end());
    return students;
}

void inputProgram() {
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





void randomFileOutput(int num_entries, int num_grades, string file_name) {
    
    string name;
    ofstream out_f(file_name);
    out_f << "Pavarde" << setw(25) << "Vardas";
    for (int i = 1; i <= num_grades; i++) {
        out_f << right << setw(12) << "ND"+to_string(i);


    }
    vector<int> r_grades;
    out_f << setw(12) << "Egz." << "\n";
    for (int j = 1; j <= num_entries; j++) {
        name = "Vardas" + to_string(j);
        r_grades = randomGrades(num_grades + 1);
        out_f <<"Pavarde" + to_string(j) << setw(31-name.length())<< right << name;
        for (int y = 0; y < r_grades.size(); y++) {
            out_f <<setw(12) << r_grades[y];
        }
        out_f << "\n";
        r_grades.clear();
    }
    out_f.close();
}

vector<vector<Student>> sortStudentsByGrade(vector<Student> students) {
    students = sortVector(students);
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

void writeSortedStudents(vector<vector<Student>> all, string f_good, string f_bad) {
    ofstream out_f1(f_good);
    ofstream out_f2(f_bad);

    out_f1 << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas" << setw(15) << left << "Galutinis" << endl;
    out_f1 << "-------------------------------------------"<<endl;
    out_f2 << setw(15) << left << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis" << endl;
    out_f2 << "-------------------------------------------"<<endl;

    for (int j = 0; j < all[0].size(); j++) {
        out_f1 << all[0][j] << endl;
    }
    for (int y = 0; y < all[1].size(); y++) {
        out_f2 << all[1][y] << endl;
    }
    out_f1.close();
    out_f2.close();
}

void testProgram(int num_lines) {
    string f_name = "student" + to_string(num_lines) + ".txt";
    string f_good_students = "ups" + to_string(num_lines) + ".txt";
    string f_bad_students = "downs" + to_string(num_lines) + ".txt";
    cout << "Failas su " + to_string(num_lines) + " eiluciu" << endl;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    randomFileOutput(num_lines, 15, f_name);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo generavimas uztruko: " << diff.count() << " s\n";


    start = std::chrono::high_resolution_clock::now();
    vector <Student> student_v;
    student_v = fileInput(f_name);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; 
    std::cout << "Duomenu nuskaitymas is failo uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    vector<vector<Student>> studs;
    studs = sortStudentsByGrade(student_v);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; 
    std::cout << "Studentu rusiavimas uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();

    writeSortedStudents(studs, f_good_students, f_bad_students);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Irasymas i failus uztruko: " << diff.count() << " s\n";


}