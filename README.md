Periodic Table of Elements (Menu-Driven Program) 

Overview

This program is a menu-driven application designed to interact with data from the Periodic Table of Elements using a struct ADT (Abstract Data Type). The application offers various functionalities, including loading, displaying, searching, sorting, and updating element data. It works with binary files and uses dynamic arrays for managing the data of elements.

Author:
Koisochukwu Nwambuonwor
Date: 03-10-2023
Course: COMP 121 - Exam 1

Features

The program offers the following features:

Dynamic Array of Structure Elements:
Load elements from a binary file into a dynamic array.
Display all 118 elements from the dynamic array.
Sort elements in ascending or descending order by atomic number.
Search for an element by atomic number (binary search) or by symbol (sequential search).
Update an element's data.
Save the updated data back into a binary file.
Structure Elements from a Binary File:
Load elements directly from a binary file.
Display all elements in the file.
Sequentially search for an element's atomic number or symbol in the file.
Update an element in the binary file directly.
Extra Features:
View detailed memory size information of the Element structure.
How to Run

Prerequisites:
C++ compiler (such as g++).
Basic understanding of C++ and structs.
Input binary data file (for loading the periodic table elements).
Compilation:
Compile the program using your preferred C++ compiler. For example:

bash
Copy code
g++ main.cpp -o periodic_table
Running:
Execute the compiled program:

bash
Copy code
./periodic_table
Navigation:
The program is menu-driven, offering multiple options for interaction:

Option A: Work with dynamic arrays and binary files.
Option B: Work with elements stored in a binary file.
Option C: View the size details of the Element structure.
Option X: Exit the program.
Key Functions

menuOption1(): Handles dynamic array operations such as loading, displaying, sorting, searching, and updating elements.
menuOption2(): Manages file operations, including displaying, searching, and updating elements directly from a binary file.
inputChar(), inputInteger(), inputString(), inputDouble(): Helper functions for user input.
displayElement(), printPeriodicTable(), printPeriodicTableNum(): Functions for displaying element details and the periodic table.
Notes

Ensure that the binary input file is available and correctly formatted.
The program handles up to 118 elements, corresponding to the elements of the Periodic Table.
The program supports sorting by atomic number and searching by atomic number and symbol.
