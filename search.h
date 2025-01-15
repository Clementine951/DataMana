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

void deleteById(s_Student*& root, int id, vector<s_Student> *students) {
    if (!root) {
        return; // Base case: the tree is empty or we've reached a leaf node.
    }

    if (id < root->id) {
        // Traverse left subtree.
        deleteById(root->leftChild, id, students);
    } else if (id > root->id) {
        // Traverse right subtree.
        deleteById(root->rightChild, id, students);
    } else {
        // Node with matching ID found.
        cout << "Deleting student: " << root->name << " " << root->lastName << " " << root->age << endl;

        // Remove from the vector.
        auto it = std::remove_if(students->begin(), students->end(), [id](const s_Student& student) {
            return student.id == id;
        });
        students->erase(it, students->end());

        // Handle node deletion (three cases).

        // Case 1: No children.
        if (!root->leftChild && !root->rightChild) {
            delete root;
            root = nullptr; // Update parent's pointer.
        }

        // Case 2: One child.
        else if (!root->leftChild) {
            s_Student* temp = root;
            root = root->rightChild; // Update parent's pointer.
            delete temp;
        } else if (!root->rightChild) {
            s_Student* temp = root;
            root = root->leftChild; // Update parent's pointer.
            delete temp;
        }

        // Case 3: Two children.
        else {
            // Find the in-order successor (smallest in the right subtree).
            s_Student* successor = root->rightChild;
            while (successor->leftChild) {
                successor = successor->leftChild;
            }

            // Replace root's data with the successor's data.
            root->id = successor->id;
            root->name = successor->name;
            root->lastName = successor->lastName;
            root->age = successor->age;

            // Delete the in-order successor.
            deleteById(root->rightChild, successor->id, students);
        }
    }
}

void deleteByAge(s_Student*& root, int age, vector<s_Student> *students) {
    if (!root) {
        return; // Base case: the tree is empty or we've reached a leaf node.
    }

    if (age < root->age) {
        // Traverse left subtree.
        deleteByAge(root->leftChild, age, students);
    } else if (age > root->age) {
        // Traverse right subtree.
        deleteByAge(root->rightChild, age, students);
    } else {
        // Node with matching age found.
        cout << "Deleting student: " << root->name << " " << root->lastName << " " << root->age << endl;

        // Remove from the vector.
        auto it = std::remove_if(students->begin(), students->end(), [age](const s_Student& student) {
            return student.age == age;
        });
        students->erase(it, students->end());

        // Handle node deletion (three cases).

        // Case 1: No children.
        if (!root->leftChild && !root->rightChild) {
            delete root;
            root = nullptr; // Update parent's pointer.
        }

        // Case 2: One child.
        else if (!root->leftChild) {
            s_Student* temp = root;
            root = root->rightChild; // Update parent's pointer.
            delete temp;
        } else if (!root->rightChild) {
            s_Student* temp = root;
            root = root->leftChild; // Update parent's pointer.
            delete temp;
        }

        // Case 3: Two children.
        else {
            // Find the in-order successor (smallest in the right subtree).
            s_Student* successor = root->rightChild;
            while (successor->leftChild) {
                successor = successor->leftChild;
            }

            // Replace root's data with the successor's data.
            root->id = successor->id;
            root->name = successor->name;
            root->lastName = successor->lastName;
            root->age = successor->age;

            // Delete the in-order successor.
            deleteByAge(root->rightChild, successor->age, students);
        }
    }
}


#endif