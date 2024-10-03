#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

// Name: Kosi 
// Date: 3/12/2023
// Chemistry Element (struct) contains these properties(fields/attributes) 
struct Element
{
	int atomicNumber = 0;
	char name[25] = "unknown";
	char symbol[3] = "  ";
	double atomicMass = 0.0;
	int state = 0;
	int type = 0;
	char discoverer[100] = "unknown";
	int discoveredYear = 0;
};

//lookup arrays
const string states[] = { "unknown", "Solid", "Liquid", "Gas" };
const string types[] = { "unknown", "Actinide", "Alkali Metal", "Alkaline Earth Metal", "Halogen", "Lanthanide", "Metalloid", "Noble Gas", "Reactive Nonmetal", "Post-Transition Metal",  "Transition Metal" };

//precodition  : e (an Element structure)
//postcondition: none
// display an element's fields/attibutes
void displayElement(const Element e)
{
	cout << "\n\tAtomic number   : " << e.atomicNumber;
	cout << "\n\tSymbol          : " << e.symbol;
	cout << "\n\tName            : " << e.name;
	cout << "\n\tType            : " << e.type << " (" << types[e.type] << ")";
	cout << "\n\tAtomic mass     : " << e.atomicMass;
	cout << "\n\tStandard state  : " << e.state << " (" << states[e.state] << ")";
	cout << "\n\tDiscovered by   : " << e.discoverer;
	cout << "\n\tDiscovered year : " << e.discoveredYear << "\n";
}

//precodition  : pointer to an array of Element structure)
//               size (integer of the arrary size)
//postcondition: none
// display all elements from the dynamic array
void displayPeriodicTableElements(const Element* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\n\tPeriodic Table element[" << i << "]";
		cout << "\n\t" << string(70, '-') << endl;
		displayElement(arr[i]);
	}
}

void printPeriodicTable()
{
	cout << "\033[1;33m  [  H ]                                                                                              \033[0;91m  [ He ]\n"
		<< "  \033[1;36m[ Li ]\033[0;31m[ Be ]                                                            \033[1;34m[  B ]\033[1;33m[  C ][  N ][  O ]\033[0m[  F ]\033[0;91m[ Ne ]\n"
		<< "\033[1;36m  [ Na ]\033[0;31m[ Mg ]                                                            \033[1;32m[ Al ]\033[1;34m[ Si ]\033[1;33m[  P ][  S ]\033[0m[ Cl ]\033[0;91m[ Ar ]\n"
		<< "\033[1;36m  [  K ]\033[0;31m[ Ca ]\033[1;35m[ Sc ][ Ti ][ V  ][ Cr ][ Mn ][ Fe ][ Co ][ Ni ][ Cu ][ Zn ]\033[0;32m[ Ga ]\033[1;34m[ Ge ]\033[1;34m[ As ]\033[1;33m[ Se ]\033[0m[ Br ]\033[0;91m[ Kr ]\n"
		<< "\033[1;36m  [ Rb ]\033[0;31m[ Sr ]\033[1;35m[ Y  ][ Zr ][ Nb ][ Mo ][ Tc ][ Ru ][ Rh ][ Pd ][ Ag ][ Cd ]\033[0;32m[ In ][ Sn ]\033[1;34m[ Sb ][ Te ]\033[0m[  I ]\033[0;91m[ Xe ]\n"
		<< "\033[1;36m  [ Cs ]\033[0;31m[ Ba ]  \033[0m*   \033[1;35m[ Hf ][ Ta ][ W  ][ Re ][ Os ][ Ir ][ Pt ][ Au ][ Hg ]\033[0;32m[ Tl ][ Pb ][ Bi ][ Po ][ At ]\033[0;91m[ Rn ]\n"
		<< "\033[1;36m  [ Fr ]\033[0;31m[ Ra ] \033[0m **  \033[1;35m[ Rf ][ Db ][ Sg ][ Bh ][ Hs ]\033[0;90m[ Mt ][ Ds ][ Rg ][ Cn ][ Nh ][ Fl ][ Mc ][ Lv ][ Ts ][ Og ]\n"
		<< "\n"
		<< "\033[0;33m              \033[0m  *   \033[0;34m [ La ][ Ce ][ Pr ][ Nd ][ Pm ][ Sm ][ Eu ][ Gd ][ Tb ][ Dy ][ Ho ][ Er ][ Tm ][ Yb ][ Lu ]\n"
		<< "               \033[0m **  \033[0;33m [ Ac ][ Th ][ Pa ][ U  ][ Np ][ Pu ][ Am ][ Cm ][ Bk ][ Cf ][ Es ][ Fm ][ Md ][ No ][ Lr ]\n"
		<< "\033[0m";
}

void printPeriodicTableNum() 
{
	cout << "\033[1;33m  [  1 ]                                                                                              \033[0;91m  [  2 ]\n"
		<< "  \033[1;36m[  3 ]\033[0;31m[  4 ]                                                            \033[1;34m[  5 ]\033[1;33m[  6 ][  7 ][  8 ]\033[0m[  9 ]\033[0;91m[ 10 ]\n"
		<< "\033[1;36m  [ 11 ]\033[0;31m[ 12 ]                                                            \033[1;32m[ 13 ]\033[1;34m[ 14 ]\033[1;33m[ 15 ][ 16 ]\033[0m[ 17 ]\033[0;91m[ 18 ]\n"
		<< "\033[1;36m  [ 19 ]\033[0;31m[ 20 ]\033[1;35m[ 21 ][ 22 ][ 23 ][ 24 ][ 25 ][ 26 ][ 27 ][ 28 ][ 29 ][ 30 ]\033[0;32m[ 31 ][ 32 ]\033[1;34m[ 33 ][ 34 ]\033[0m[ 35 ]\033[0;91m[ 36 ]\n"
		<< "\033[1;36m  [ 37 ]\033[0;31m[ 38 ]\033[1;35m[ 39 ][ 40 ][ 41 ][ 42 ][ 43 ][ 44 ][ 45 ][ 46 ][ 47 ][ 48 ]\033[0;32m[ 49 ][ 50 ]\033[1;34m[ 51 ][ 52 ]\033[0m[ 53 ]\033[0;91m[ 54 ]\n"
		<< "\033[1;36m  [ 55 ]\033[0;31m[ 56 ]\033[1;35m[ 57 ][ 72 ][ 73 ][ 74 ][ 75 ][ 76 ][ 77 ][ 78 ][ 79 ][ 80 ]\033[0;32m[ 81 ][ 82 ][ 83 ][ 84 ][ 85 ]\033[0;91m[ 86 ]\n"
		<< "\033[1;36m  [ 87 ]\033[0;31m[ 88 ]  \033[0m*   \033[1;35m[ 89 ][ 104 ][ 105 ][ 106 ][ 107 ][ 108 ][ 109 ][ 110 ][ 111 ]\033[0;90m[ 112 ][ 114 ][ 116 ][ 118 ]\n"
		<< "\033[1;36m  [  1 ]\033[0;31m[  2 ] \033[0m **  \033[1;35m[ 57 ][ 89 ][ 90 ][ 91 ][ 92 ][ 93 ][ 94 ][ 95 ][ 96 ][ 97 ][ 98 ][ 99 ][ 100 ][ 101 ][ 102 ]\n"
		<< "\033[0m";
}
void updateElement(Element& e)
{
	string symbol = inputString("\n\tEnter a new symbol: ", false);
	for (int i = 0; i < symbol.length(); i++)
		symbol[i] = (i == 0) ? toupper(symbol[i]) : tolower(symbol[i]);

	strcpy_s(e.symbol, sizeof(e.symbol), symbol.c_str());

	string name = inputString("\tEnter a new name: ", false);
	for (int i = 0; i < symbol.length(); i++)
		name[i] = (i == 0) ? toupper(name[i]) : tolower(name[i]);

	strcpy_s(e.name, sizeof(e.name), name.c_str());
	e.state = inputInteger("\tEnter a new state (0-unknown, 1-Solid, 2-Liquid, or 3-Gas): ", 0, 3);
	e.atomicMass = inputDouble("\tEnter a new atomic mass: ", true);
	e.type = inputInteger("\tEnter a new type (0-unknown, 1-Actinide, 2-Alkali Metal, 3-Alkaline Earth Metal,\n\t\t\t  4-Halogen, 5-Lanthanide, 6-Metalloid, 7-Noble Gas,\n\t\t\t  8-Reactive Nonmetal, 9-Post-Transition Metal, or 10-Transition Metal): ", 0, 10);
	strcpy_s(e.discoverer, sizeof(e.discoverer), inputString("\tEnter a new discoverer: ", true).c_str());
	e.discoveredYear = inputInteger("\tEnter a new year discovered: ", true);
}


