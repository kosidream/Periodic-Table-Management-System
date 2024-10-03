//
// main.cpp
// koisochukwu Nwambuonwor 
// 03-10-2023
// COMP 121
// EXAM 1
// This program is a menu driven program that for Periodic Table of Elements (using struct ADT)
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "input.h"
#include "Element.h"

using namespace std;

// function prototypes
void challenge1();
int menuOption1();
int menuOption2();;

int main()
{
    Element periodicTable[118]; // dynamic array of structure elements
    char option;
    string options = "ABCX";
    string prompt = "   Option: ";

    // Display menu
    do {

        cout << endl;

        printPeriodicTable();

        cout << endl << endl;
        cout << "   In chemistry, the periodic table is a tabular display of the chemical elements. It is widely used" << endl;
        cout << "   in chepistry, physics, and other sciences, and is generally seen as an icon of chemistry. It is a graphic " << endl;
        cout << "   formulation of the periodic law, which states that the properties of the chemical elements exhibit a" << endl;
        cout << "   periodic dependence on their atomic numbers." << endl;
        cout << endl << endl;

        cout << "   CMPR121 EXAM 1 - Periodic Table of Elements (using struct ADT) by kosi Nwambuonwor 3-10-2023" << endl;
        cout << "   ---------------------------------------------------------------------------------------------------" << endl;
        cout << "        A. Dynamic Array of Structure Elements" << endl;
        cout << "        B. Structure Elements from Binary File" << endl;
        cout << "        C. Structure Element size info (5pts Extra)" << endl;
        cout << "------------------------------------------------------------------------------------------------------" << endl;
        cout << "           X. Exit the program" << endl;
        cout << "------------------------------------------------------------------------------------------------------" << endl;

        option = inputChar(prompt, options);

        switch (toupper(option))
        {
        case 'A':
            // Code for option A
            menuOption1();
            break;
        case 'B':
            // Code for option B
            menuOption2();
            break;
        case 'C':
        {
            // Code for option C
            cout << endl;

            //  Structure Element size info
            Element e;
            std::cout << "  Element structure size              : " << sizeof(Element) << " byte(s)" << std::endl;
            std::cout << "          Atomic          int         : " << sizeof(e.atomicNumber) << " byte(s)" << std::endl;
            std::cout << "          Symbol          char(3)     : " << sizeof(e.symbol) << " byte(s)" << std::endl;
            std::cout << "          Name            char(25)    : " << sizeof(e.name) << " byte(s)" << std::endl;
            std::cout << "          Type            int         : " << sizeof(e.type) << " byte(s)" << std::endl;
            std::cout << "          Atomic mass     double      : " << sizeof(e.atomicMass) << " byte(s)" << std::endl;
            std::cout << "          Standard state  int         : " << sizeof(e.state) << " byte(s)" << std::endl;
            std::cout << "          Discovered by   char(100)   : " << sizeof(e.discoverer) << " byte(s)" << std::endl;
            std::cout << "          Discovered year int         : " << sizeof(e.discoveredYear) << " byte(s)" << std::endl;
        }


            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            return 1;

            break;
        case 'X':
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }

    } while (options.find(option) == string::npos); // continue running until a valid option is entered
}

int menuOption1()
{
    // Clear console
    system("cls");

    // variable declare
    Element* array = nullptr;
    do
    {
        cout << "\nDynamic Array of structure elements";
        cout << "\n" << string(60, char(205));
        cout << "\n     1. Read binary structure input data file and store elements into an dynamic array";
        cout << "\n     2. Display 118 elements from the dynamic array";
        cout << "\n     3. Sort ascending order the dynamic array by atomic number(5 points Extra)";
        cout << "\n     4. Sort descending order the dynamic array by atomic number(5 points Extra)";
        cout << "\n     5. Binary search for an element's atomic number from the array (10 points Extra)";
        cout << "\n     6. Sequencial search for an element's symbol from the array";
        cout << "\n     7. Update an element by atomic number from the array(10 points Xtra)";
        cout << "\n     8. Save the dynamic array into a binary data file";
        cout << "\n" << string(60, char(196));
        cout << "\n         0. Return";
        cout << "\n" << string(60, char(205));

        switch (inputInteger("\nOption: ", 0, 8))
        {
        case 0:
            delete[] array;
            return 1;

            /*
            * Precondition: None.
            Postcondition: 
            -If the input file specified by the user is opened successfully, the program reads the binary structure data from the file and stores it in a 
            dynamically allocated array of Element objects.
            -If the input file cannot be opened, the program displays an error message and returns to the main menu.
            */

        case 1:
        {
            // Dynamically allocate an array of 118 Element objects
            array = new Element[118];

            // Prompt user to enter the input file name
            string filename = inputString("\n Enter the binary structure input file name to read from: ", false);

            // Attempt to open the input file in binary mode
            fstream inputfile(filename, ios::in | ios::binary);

            // If the input file could not be opened, display an error message and return to the main menu
            if (!inputfile.is_open()) {
                cout << "Error opening file!" << endl;
                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
                break;
            }

            // Display a message indicating that the structure data is being read and stored into the dynamic array
            cout << "Completed read structure data and stored into an dynamic array." << endl;

            // Initialize an index variable to keep track of the number of elements read from the input file
            int index = 0;

            // Read Element objects from the input file and store them into the dynamic array until the end of the file is reached
            while (inputfile.read(reinterpret_cast<char*>(&array[index]), sizeof(Element)))
            {
                index++;
            }

            // Close the input file
            inputfile.close();

            // Display a message indicating that the input file has been read and closed
            cout << "The input file " << filename << " has been read and closed." << endl;

            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            system("cls"); // Clear console screen

        }
        break;
        /*
        Precondition: The dynamic array of Element objects has been successfully populated with data from the input file (Case 1).
        Postcondition: The 118 elements from the dynamic array have been displayed to the user.
        */
        // Display 118 elements from the dynamic array

        case 2:
        {
            // Check if array is not empty
            if (!array) {
                cout << "Please read the input file first (Option 1)!" << endl;
                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
                break;
            }
            displayPeriodicTableElements(array, 118);

            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            system("cls"); // Clear console screen
        }
        break;

        /*
        Precondition: The dynamic array of Element objects has been successfully populated with data from the input file (Case 1).
        Postcondition: The dynamic array of Element objects has been sorted in ascending order by atomic number,
        and a message indicating successful sorting has been displayed to the user.
        */

        // Sort the dynamic array in ascending order by atomic number

        case 3:
        {
            // Check if array is not empty
            if (!array) {
                cout << "Please read the input file first (Option 1)!" << endl;
                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
                break;
            }
            // Sort the array
            for (int i = 0; i < 118; i++)
            {
                for (int j = i + 1; j < 118; j++)
                {
                    if (array[i].atomicNumber > array[j].atomicNumber)
                    {
                        Element temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                }
            }
            cout << "Array sorted in ascending order by atomic number.\n";

            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            system("cls"); // Clear console screen
        }
        break;

             // This case sorts the array of elements in descending order by atomic number
            // If the array is not initialized, the user is prompted to read the input file first (Option 1)
            // After sorting the array, the user is prompted to press any key to continue and return to the main menu
        case 4:
        {
            // check if file inputted succesfully 
            if (!array) {
                cout << "Please read the input file first (Option 1)!" << endl;

                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
                break;
            }
            const int numElements = 118;

            // Sort the array in descending order by atomic number
            for (int i = 0; i < numElements; i++)
            {
                for (int j = i + 1; j < numElements; j++)
                {
                    if (array[i].atomicNumber < array[j].atomicNumber)
                    {
                        std::swap(array[i], array[j]);
                    }
                }
            }
            cout << "Array sorted in descending order by atomic number.\n";

            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            system("cls"); // Clear console screen

        }
        break;

            // This case searches for an element with a specific atomic number entered by the user
           // If the array is not initialized, the user is prompted to read the input file first (Option 1)
           // The user is prompted to enter an atomic number between 1 and 118 (inclusive), or 0 to stop
           // If the entered atomic number is valid, the array is sorted by atomic number
           // The program performs binary search on the sorted array to find the element with the entered atomic number
           // If the element is found, it is displayed and the user is prompted to press any key to continue and return to the main menu
           // If the element is not found, an error message is displayed and the user is prompted to press any key to continue and return to the main menu

        case 5:
        {

            system("cls");

            // check if file inputted succesfully 
            if (!array) {
                cout << "Please read the input file first (Option 1)!" << endl;
                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
                break;
            }

            // Clear console
            system("cls");

            cout << endl;

            printPeriodicTableNum();

            cout << endl;

            // prompt user 
            int atomicNumber = inputInteger("\nEnter an atomic number (1...118 or 0 - stop) to be searched:", 0, 118);

            if (atomicNumber == 0)
                break;

            // Sort the array by atomic number
            for (int i = 0; i < 117; i++)
            {
                for (int j = 0; j < 117 - i; j++)
                {
                    if (array[j].atomicNumber > array[j + 1].atomicNumber)
                    {
                        Element temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }

            // Perform binary search
            int low = 0, high = 117, mid;
            while (low <= high)
            {
                mid = (low + high) / 2;

                if (array[mid].atomicNumber == atomicNumber)
                {
                    displayElement(array[mid]);

                    // RETURN TO MENU
                    cout << "\nPress any key to continue...";
                    cin.get(); // Wait for user to press any key
                    system("cls"); // Clear console screen
                    break;
                }
                else if (array[mid].atomicNumber < atomicNumber)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            if (low > high) {
                cout << "\nERROR: The element with atomic number(" << atomicNumber << ") not found.\n";

                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
            }
        }
        break;

        /*
        Precondition: The input file has been read and the array of Element objects has been initialized.
        Postcondition: The user has been prompted to enter an atomic symbol. If the symbol is found in the array, 
        the details of the corresponding Element object are displayed. If the symbol is not found, an error message is displayed. 
        In both cases, the user is prompted to press any key to continue, and the console is cleared.
        */
        
        case 6:
        {
            system("cls");

            // check if file inputted succesfully 
            if (!array) {
                cout << "Please read the input file first (Option 1)!" << endl;
                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
                break;
            }

            // Clear console
            system("cls");


            bool bfound = false;
            cout << endl;

            // display table 
            printPeriodicTable();

            cout << endl;


            // prompt user 
            string atomicSymbol = inputString("\nEnter an atomic symbol: ", false);
            for (int i = 0; i < 118; i++)
            {
                if (strcmp(atomicSymbol.c_str(), array[i].symbol) == 0)
                {
                    displayElement(array[i]);
                    bfound = true;
                    break;
                }
            }

            if (!bfound)
                cout << "\nERROR: The element with symbol(" << atomicSymbol << ") not found.\n";

            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            system("cls"); // Clear console screen
        }
        break;

        /*
        Precondition: The input file has been read and the array of Element objects has been initialized.
        Postcondition: The user has been prompted to enter an atomic number to update. If an Element object with the entered atomic number is 
        found in the array, the details of the corresponding Element object are displayed and the user is prompted to enter new information
        to update the Element. If no Element object with the entered atomic number is found, an error message is displayed.
        In both cases, the user is prompted to press any key*/
        
        case 7:
        {
            system("cls");

            // check if file inputted succesfully 
            if (!array) 
            {
                cout << "Please read the input file first (Option 1)!" << endl;
                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
                break;
            }
            cout << endl;
            printPeriodicTableNum();
            cout << endl;

            // prompt user 
            int atomicNumber = inputInteger("\nEnter an atomic number (1...118 or 0 - stop) to update: ");
            bool bfound = false;
            for (int i = 0; i < 118; i++)
            {
                if (array[i].atomicNumber == atomicNumber)
                {
                    displayElement(array[i]);
                    bfound = true;

                    // update the element
                    strcpy_s(array[i].symbol, inputString("\nEnter a new symbol: ", false).c_str());
                    strcpy_s(array[i].name, inputString("\nEnter a new name: ", false).c_str());
                    array[i].state = inputInteger("\nEnter a new state (0-unknown, 1-Solid, 2-Liquid, or 3-Gas): ", 1, 3);
                    array[i].atomicMass = inputDouble("\nEnter a new atomic mass: ");
                    array[i].type = inputInteger("\nEnter a new type (0-unknown, 1-Actinide, 2-Alkali Metal, 3-Alkaline Earth Metal, 4-Halogen, 5-Lanthanide, 6-Metalloid, 7-Noble Gas, 8-Reactive Nonmetal, 9-Post-Transition Metal, or 10-Transition Metal): ", 0, 10);
                    strcpy_s(array[i].discoverer, inputString("\nEnter a new discoverer: ", false).c_str());
                    array[i].discoveredYear = inputInteger("\nEnter a new year discovered: ", 0, 2023);
                    cout << "\nElement with atomic #" << atomicNumber << " has been updated with new information.\n";

                    // RETURN TO MENU
                    cout << "\nPress any key to continue...";
                    cin.get(); // Wait for user to press any key
                    system("cls"); // Clear console screen

                    break;
                }
            }

            if (!bfound)
                cout << "\nERROR: The element with atomic number(" << atomicNumber << ") not found.\n";

            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            system("cls"); // Clear console screen
        }
        break;

        /*
        Precondition: The input file has been read and the array of Element objects has been initialized.
        Postcondition: The user has been prompted to enter a filename for the binary file to be written. 
        If the file is successfully opened, the Element objects in the array are written to the file in binary format. 
        If the file cannot be opened, an error message is displayed. In both cases, the user is prompted to press any key to continue, 
        and the console is cleared.
        */

        case 8:
        {

            system("cls");

            // check if file inputted succesfully 
            if (!array)
            {
                cout << "Please read the input file first (Option 1)!" << endl;
                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
                break;
            }

            // prompt user 
            string filename = inputString("\nEnter a binary file to write:", false);

            fstream outputfile(filename, ios::out | ios::binary);
            if (!outputfile.is_open()) {
                cout << "Error opening file!" << endl;

                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen

                break;
            }

            for (int i = 0; i < 118; i++)
            {
                outputfile.write(reinterpret_cast<char*>(&array[i]), sizeof(Element));
            }

            outputfile.close();

            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            system("cls"); // Clear console screen
        }
        break;
        }
    } while (true);

    return 0;
}
int menuOption2()
{
    system("cls"); // Clear console screen
    Element* array = nullptr;
    string filename;

    int choice;
    do
    {
        cout << "Random Access structure elements from File\n"
            << "---------------------------------------------------------------------------------------------\n"
            << "        1. Specify the binary structure input/output data file\n"
            << "        2. Display ALL elements from the file\n"
            << "        3. Sequential search for an element's atomic number from the file\n"
            << "        4. Sequential search for an element's symbol from the file\n"
            << "        5. Directly update an element by its atomic number into the file (10 points Xtra)\n"
            << "        --------------------------------------------------------------------------------------\n"
            << "        0. Return\n"
            << "-----------------------------------------------------------------------------------------------\n";

        choice = inputInteger(" Option: ", 0, 5);

        switch (choice)
        {

            // pre condition: none
            // post condtion : 
                   // This code block loads binary data from a file into an array of 118 Elements.
                 // The filename is obtained from the user through the inputString() function.
                 // If the file cannot be opened or read, an error message is displayed.
                // Otherwise, a success message is displayed and the user is prompted to continue by pressing any key.
                // Finally, the console screen is cleared and the program returns to the main menu.
     
        case 1:
        {
            // Get the filename from the user
            filename = inputString("\nEnter the binary structure input/output data file: ", false);

            // Open the file for reading
            fstream file(filename, ios::binary | ios::in);

            // Check if the file was successfully opened
            if (!file.is_open())
            {
                cout << "\nERROR: Failed to open file(" << filename << ") for reading.\n";
                break;
            }

            // Create an array to hold the data from the file
            Element array[118];

            // Read binary data from the file into the array
            file.read(reinterpret_cast<char*>(array), sizeof(array));

            // Check if the data was successfully read from the file
            if (file.fail())
            {
                cout << "\nERROR: Failed to read binary data from file(" << filename << ").\n";
                break;
            }

            // Close the file
            file.close();

            // Notify the user that the binary data has been loaded
            cout << "\nBinary data loaded from file(" << filename << ").\n";

            // RETURN TO MENU
            // Wait for the user to press any key and clear the console screen
            cout << "\nPress any key to continue...";
            cin.get();
            system("cls");
        
        }
        break;

        /*Preconditions:

        The input file containing binary structure input / output data must exist and be accessible by the program.
            The binary data in the input file must conform to the expected format and size for the Element data structure.
            The displayElement() function must be defined and correctly implemented.
            The system being used must support the "system" and "cls" functions.

            Postconditions:

        If the input file is successfully opened and read, the program will display the binary data in the console using the displayElement() function.
            If the input file fails to open or read, an error message will be displayed in the console.
            The console screen will be cleared and the user will be prompted to press any key to continue.
            The program will return to the main menu.*/

        case 2:
        {
            // Open the binary input file for reading
            ifstream file(filename, ios::binary);

            // Check if the file is successfully opened
            if (!file.is_open())
            {
                cout << "\nERROR: Failed to open file(" << filename << ") for reading.\n";

                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen

                break;
            }

            // Read each element from the file and display its contents
            Element temp;

            while (file.read(reinterpret_cast<char*>(&temp), sizeof(Element)))
            {
                displayElement(temp);
            }

            // Check if the file read operation is successful or not
            if (file.fail() && !file.eof())
            {
                cout << "\nERROR: Failed to read binary data from file(" << filename << ").\n";
                break;
            }

            // Close the input file
            file.close();

            cout << "\nBinary data loaded from file(" << filename << ").\n";

            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            system("cls"); // Clear console screen
        }
        break;
        

      ////  PreCondition: The user has selected the option to search for an element's atomic number from the binary file, and the file
      //  containing the data is already present in the directory.

      //   //   PostCondition : The program searches the binary file for the element with the given atomic number, and if found, 
      //  displays the information for the element on the console.If not found, the program informs the user that the element was not found in the file.

        case 3:
        {
            // Code to sequential search for an element's atomic number from the file

            fstream file(filename, ios::binary | ios::in); // Open file for binary input

            if (!file.is_open())
            {
                cout << "\nERROR: Failed to open file(" << filename << ") for reading.\n";

                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen

                break;
            }

            cout << endl;
            printPeriodicTableNum(); // Display periodic table with atomic numbers
            cout << endl;

            int atomicNumber = inputInteger("\nEnter the element's atomic number to search for: ");

            Element element;
            bool found = false;

            while (file.read(reinterpret_cast<char*>(&element), sizeof(Element))) // Read elements from file
            {
                if (element.atomicNumber == atomicNumber) // If atomic number matches
                {
                    found = true;
                    displayElement(element); // Display element's details

                    // RETURN TO MENU
                    cout << "\nPress any key to continue...";
                    cin.get(); // Wait for user to press any key
                    system("cls"); // Clear console screen

                    break;
                }
            }

            file.close();

            if (!found) // If element not found
            {
                cout << "\nElement with atomic number " << atomicNumber << " not found in file.\n";

                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
            }
        }
        break;

        /////*preCondition: The user has selected the option to search for an element's symbol from the binary file, and the file 
        //containing the data is already present in the directory.

        ////    PostCondition : The program searches the binary file for the element with the given symbol, and if found,
        //  */displays the information for the element on the console.If not found, the program informs the user that the element was not found in the file
      
        case 4:
        {
            fstream file(filename, ios::binary | ios::in); // Open file for binary input

            if (!file.is_open())
            {
                cout << "\nERROR: Failed to open file(" << filename << ") for reading.\n";
                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen

                break;
            }

            cout << endl;
            printPeriodicTable(); // Display periodic table with element symbols
            cout << endl;

            string symbol = inputString("\nEnter the element's symbol to search for: ", true);

            Element element;

            bool found = false;

            while (file.read(reinterpret_cast<char*>(&element), sizeof(Element))) // Read elements from file
            {
                if (strcmp(element.symbol, symbol.c_str()) == 0) // If symbol matches
                {
                    found = true;
                    displayElement(element); // Display element's details

                    // RETURN TO MENU
                    cout << "\nPress any key to continue...";
                    cin.get(); // Wait for user to press any key
                    system("cls"); // Clear console screen

                    break;
                }
            }

            file.close();

            if (!found) // If element not found
            {
                cout << "\nElement with symbol \"" << symbol << "\" not found in file.\n";
                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen
            }

            // RETURN TO MENU
            //cout << "\nPress any key to continue...";
            //cin.get(); // Wait for user to press any key
            //system("cls"); // Clear console screen
        }
        break;


          /* Precondition:
            The user must have selected option 5 from the menu.
            The file containing the periodic table data must exist and be accessible.
            The file must have write permission.


            Postcondition :
            The user is prompted to enter the atomic number of the element to update.
            If the atomic number is found in the file, the program displays the current data for the element and prompts the user to update it.
            If the user confirms the changes, the program updates the data in the file and displays a message indicating that the changes have been saved.
            If the user does not confirm the changes, the program discards the changes and displays a message indicating that the changes have been discarded.
            If the atomic number is not found in the file, the program displays a message indicating that the element could not be found.
            The program returns to the main menu after the operation is complete.*/

        case 5:
        {
            // Open file in read mode
            fstream file(filename, ios::binary | ios::in);

            // Check if file was opened successfully
            if (!file.is_open())
            {
                cout << "\nERROR: Failed to open file(" << filename << ") for reading.\n";

                // RETURN TO MENU
                cout << "\nPress any key to continue...";
                cin.get(); // Wait for user to press any key
                system("cls"); // Clear console screen

                break;
            }

            // Get the atomic number of the element to update
            int atomicNumber;
            cout << "\nEnter the atomic number of the element to update: ";
            cin >> atomicNumber;

            // Create an element object
            Element element;

            bool found = false;

            // Loop through the file to find the element with the matching atomic number
            while (file.read(reinterpret_cast<char*>(&element), sizeof(Element)))
            {
                if (element.atomicNumber == atomicNumber)
                {
                    found = true;

                    // Display the current element data
                    cout << "\nCurrent Element Data:\n";
                    displayElement(element);

                    cin.ignore();

                    // Update the element data
                    updateElement(element);

                    // Display the updated element data
                    cout << "\nUpdated Element Data:\n";
                    displayElement(element);

                    // Ask user if they want to commit the changes to the file
                    cout << "\nDo you want to commit the changes? (Y-yes or N-no) ";
                    char confirm;
                    cin >> confirm;
                    if (confirm == 'Y' || confirm == 'y')
                    {
                        // Write the updated element data to the file
                        file.seekp(-static_cast<int>(sizeof(Element)), ios::cur);
                        file.write(reinterpret_cast<char*>(&element), sizeof(Element));
                        cout << "\nChanges saved to file(" << filename << ").\n";
                    }
                    else
                    {
                        cout << "\nChanges discarded.\n";
                    }

                    break;
                }
            }

            // If element with matching atomic number was not found in the file
            if (!found)
            {
                cout << "\nElement with atomic number " << atomicNumber << " not found in file.\n";
            }

            // Close the file
            file.close();

            // RETURN TO MENU
            cout << "\nPress any key to continue...";
            cin.get(); // Wait for user to press any key
            system("cls"); // Clear console screen
        }
        break;


        case 0:
            return 1;

        default:

            // User entered an invalid option, so we inform them and loop again
            cout << "Invalid option. Please try again.\n";
            break;
        }

    } while (choice != 0);

    return choice;
}
