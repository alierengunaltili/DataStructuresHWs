// LibrarySimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
#include <string.h>
#include "LibrarySystem.h"

int main()
{
	LibrarySystem LS;
	LS.addBook(1000, "Machine Learning", 1997);
	LS.addBook(1200, "Data Mining", 1991);
	LS.addBook(1300, "Problem S. with C++", 1991);
	LS.addBook(1400, "C++ How to Program", 2005);
	LS.addBook(1200, "Data Mining", 1991);
	LS.deleteBook(1300);
	LS.deleteBook(2000);
	LS.addBook(1500, "Pattern Recognition", 2000);
	cout << endl;
	LS.addStudent(21000000, "Selim Aksoy");
	LS.addStudent(21000011, "Ercument Cicek");
	LS.addStudent(21000011, "Aydamir Mirzayev");
	LS.addStudent(21000020, "Mert Duman");
	LS.addStudent(21000001, "Han Solo");
	LS.addStudent(21000005, "Jack Ryan");
	LS.deleteStudent(21000011);
	LS.deleteStudent(21000050);
	cout << endl;
	LS.checkoutBook(1200, 21000000);
	LS.checkoutBook(1400, 21000020);
	LS.checkoutBook(2050, 21000011);
	LS.checkoutBook(1000, 21000444);
	LS.checkoutBook(1500, 21000000);
	LS.checkoutBook(1400, 21000001);
	cout << endl;
	LS.showStudent(21000000);
	cout << endl;
	LS.showStudent(21000005);
	cout << endl;
	LS.showStudent(21000011);
	cout << endl;
	LS.showBook(1000);
	LS.showBook(1200);
	cout << endl;
	LS.showAllBooks();
	cout << endl;
	LS.returnBook(1200);
	LS.returnBook(1000);
	cout << "CH1" << endl;
	LS.checkoutBook(1200, 21000020);
	LS.checkoutBook(1000, 21000000);
	cout << "213123321" << endl;
	LS.showAllBooks();
	cout << endl;
	LS.deleteStudent(21000020);
	cout << endl;
	LS.deleteBook(1000);
	cout << endl;
	LS.showStudent(21000000);
	cout << endl;
	LS.showAllBooks();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
