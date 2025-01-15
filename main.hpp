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
vector<s_Student> *students = new vector<s_Student>;


void idSearch(vector<s_Student>* students);

/*
    Insert student
    params:
        s_Student *student - pointer to student
        int id - id of student
    return:
        void
*/
void insert_student(int id);

/*
    Create random student
    params:
        s_Student *student - pointer to student
        vector<s_Student> *students - pointer to vector of students
    return:
        void
*/
void create_new_random_student(s_Student *student, vector<s_Student> *students);

/*
    Print students
    params:
        const vector<s_Student> *students - pointer to vector of students
    return:
        void
*/
void print_students(const vector<s_Student> *students);




#endif