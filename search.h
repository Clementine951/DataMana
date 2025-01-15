#ifndef SEARCH_H
#define SEARCH_H

/*
Search / retrieval
Insertion
Deletion

----
Creation of a search tree by research
*/

#include <iostream>
#include <vector>
#include <string>
#include "main.hpp"

using namespace std;

// binary search tree
// create tree with ponly index and id
void idSearch(vector<s_Student>* students){
    int id;
    cout << "Enter the id of the student you want to search: ";
    cin >> id;
    s_Student *tmp = &students->at(id);
    cout << "Student found: " << tmp->name << " " << tmp->lastName << " " << tmp->age << endl;
}

void ageSearch(s_Student *student, int age){
    s_Student *tmp = student;
    if (tmp != NULL) {
        ageSearch(tmp->leftChild, age);
        ageSearch(tmp->rightChild, age);
        if (tmp->age == age) {
            cout << "Student found: " << tmp->name << " " << tmp->lastName << " " << tmp->age << endl;
        }
    }
    return;
}

void nameSearch(s_Student *student, string name){
    
    s_Student *tmp = student;
    if (tmp != NULL) {
        nameSearch(tmp->leftChild, name);
        nameSearch(tmp->rightChild, name);
        if (tmp->name == name) {
            cout << "Student found: " << tmp->name << " " << tmp->lastName << " " << tmp->age << endl;
        }
    }
    return;
}

void lastNameSearch(s_Student *student, string lastName){
    
    s_Student *tmp = student;
    if (tmp != NULL) {
        nameSearch(tmp->leftChild, lastName);
        nameSearch(tmp->rightChild, lastName);
        if (tmp->name == lastName) {
            cout << "Student found: " << tmp->name << " " << tmp->lastName << " " << tmp->age << endl;
        }
    }
    return;
}
#endif