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
    
    ifstream open_f(f_name);
    
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
        new_stream >> st_vector[static_cast<std::vector<Student, std::allocator<Student>>::size_type>(i) - 1];

    }
    st_vector = sortVector(st_vector);
    //sort(st_vector.begin(), st_vector.end());
    return st_vector;
}

vector<Student> sortVector(vector<Student> students) {
    sort(students.begin(), students.end());
    return students;
}