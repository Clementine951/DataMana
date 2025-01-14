#include "main.hpp"

int main(void) {
    s_Student student;
    vector<s_Student> students;
   
    for (int i = 0; i < 20; i++) {
        create_new_random_student(&student, &students);
    }
    print_students(students);

    
    return 0;

}

void create_new_random_student(s_Student *student, vector<s_Student> *students) {
    const vector<string> studentNames = {"John", "Jane", "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Heidi"};
    const vector<string> studentLastNames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};

    student->name = studentNames[rand() % studentNames.size()];
    student->lastName = studentLastNames[rand() % studentLastNames.size()];
    student->age = rand() % 100 + 10;
    int tmp = rand() % 20;
    for (const s_Student &s : *students) {
        if (s.id == tmp) {
            tmp = rand() % 20;
        }
    }
    student->id = tmp;
    students->push_back(*student);
}


void print_students(const vector<s_Student> &students) {
    for (const s_Student& student : students) {
        cout << "Student id: " << student.id << endl;
        cout << "Student last name: " << student.lastName << endl;
        cout << "Student name: " << student.name << endl;
        cout << "Student age: " << student.age << endl;
        cout << "----------------------" << endl;
    }
}