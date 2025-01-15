# Data Management Project

This project is a simple data management system for handling student records. It allows you to insert, search, and delete student records using a binary search tree. The project is implemented in C++.

## Features

- Insert new student records
- Search for students by ID, name, last name, or age
- Print all student records
- Delete student records by ID or age

## Building the Project

To build the project, you need to have `g++` installed on your system. You can compile the project using the following command:

```sh
g++ -std=c++17 ./main.cpp -o main
```

This command specifies the C++17 standard and compiles `main.cpp` into an executable named `main`.

## Usage

After building the project, you can run the executable to interact with the data management system. The available options are:

1. Insert student
2. Search by ID
3. Search by name
4. Search by last name
5. Search by age
6. Print students
7. Remove student by ID
8. Remove student by age
0. Exit

Follow the on-screen prompts to perform the desired operations.

## File Structure

- `main.hpp`: Header file containing the student structure and function declarations.
- `main.cpp`: Main file containing the implementation of the data management system.
- `search.h`: Header file containing the search and delete functions.

## Example

To insert a new student, choose option 1 and specify the number of students you want to insert. The system will generate random student records and add them to the binary search tree.

To search for a student by ID, choose option 2 and enter the student's ID. The system will display the student's details if found.

To delete a student by age, choose option 8 and enter the age. The system will remove all students with the specified age from the records.
