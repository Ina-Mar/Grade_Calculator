# include "Functions.h";


vector<int> randomGrades(int n) {
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