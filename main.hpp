#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>

using namespace std;

typedef struct student{
    int id;
    string name;
    string lastName;
    int age;
    student* leftChild;
    student* rightChild;
    
} s_Student;

s_Student *ROOT = NULL;
s_Student *student = NULL;
vector<s_Student> *students = new vector<s_Student>;


void create_new_random_student(s_Student *student, vector<s_Student> *students);

void print_students(const vector<s_Student> *students);




#endif