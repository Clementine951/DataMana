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

void deleteByLastName(s_Student *root, const string lastName, vector<s_Student> *students) {
    if (!root) {
        return; 
    }

    deleteByLastName(root->leftChild, lastName, students);
    deleteByLastName(root->rightChild, lastName, students);

    if (root->lastName == lastName) {
        cout << "Deleting student: " << root->name << " " << root->lastName << " " << root->age << endl;

        // No children
        if (!root->leftChild && !root->rightChild) {
            students->erase(students->begin() + root->id);
            delete root;
            root = nullptr; 
        }

        // One child
        else if (!root->leftChild) {
            s_Student *tmp = root;
            root = root->rightChild; 
            students->erase(students->begin() + root->id);
            delete tmp;
        } else if (!root->rightChild) {
            s_Student *tmp = root;
            root = root->leftChild; 
            students->erase(students->begin() + root->id);
            delete tmp;
        }

        // Two children
        else {
            s_Student *successor = root->rightChild;
            while (successor->leftChild) {
                successor = successor->leftChild;
            }

            root->id = successor->id;
            root->name = successor->name;
            root->lastName = successor->lastName;
            root->age = successor->age;

            deleteByLastName(root->rightChild, successor->lastName, students);
        }
    }
}

#endif