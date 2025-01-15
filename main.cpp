#include "main.hpp"
#include "search.h"
#include <cstdlib>
#include <ctime>

int main(void) {
    srand(time(nullptr)); 
    int id = 0;
    int choice;
    string name;
    string lastName;
    int age;
    int nbStudents;


    do {
        cout << "1. Insert student" << endl;
        cout << "2. Search by id" << endl;
        cout << "3. Search by name" << endl;
        cout << "4. Search by last name" << endl;
        cout << "5. Search by age" << endl;
        cout << "6. Print students" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "How many students do you want to insert? ";
                cin >> nbStudents;
                for (int i = 0; i < nbStudents; i++) {
                    insert_student(id);
                    id++;
                }
                break;
            case 2:
                idSearch(students);
                break;
            case 3:
                cout << "Enter the name of the student you want to search: ";
                cin >> name;
                nameSearch(ROOT, name);
                break;
            case 4:
                cout << "Enter the last name of the student you want to search: ";
                cin >> lastName;
                lastNameSearch(ROOT, lastName);
                break;
            case 5:
                cout << "Enter the age of the student you want to search: ";
                cin >> age;
                ageSearch(ROOT, age);
                break;
            case 6:
                print_students(students);
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 7);
    

    return 0;
}

void insert_student(int id) {
    
    s_Student *tmp = new s_Student;
    tmp->id = id;
    tmp->leftChild = NULL;
    tmp->rightChild = NULL;
    
    s_Student *current;
    s_Student *parent;
    
    create_new_random_student(tmp, students);

    if (ROOT == NULL) {
        ROOT = tmp;
    } else {
        current = ROOT;
        parent = NULL;
        while (true) {
            parent = current;
            if (tmp->id < current->id) {
                current = current->leftChild;
                if (current == NULL) {
                    parent->leftChild = tmp;
                    return;
                }
            } else {
                current = current->rightChild;
                if (current == NULL) {
                    parent->rightChild = tmp;
                    return;
                }
            }
        }
    }
    
}

void create_new_random_student(s_Student *student, vector<s_Student> *students) {
    vector<string> studentNames = {"John", "Jane", "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Heidi"};

    vector<string> studentLastNames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};

    student->name = studentNames[rand() % studentNames.size()];
    student->lastName = studentLastNames[rand() % studentLastNames.size()];
    student->age = rand() % 100 + 10;
    students->push_back(*student);
}

void print_students(const vector<s_Student> *students) {
    for (const s_Student &student : *students) {
        cout << "Student id: " << student.id << endl;
        cout << "Student last name: " << student.lastName << endl;
        cout << "Student name: " << student.name << endl;
        cout << "Student age: " << student.age << endl;
        cout << "----------------------" << endl;
    }
}
