#include <iostream>
#include <string>
#include "Student.h"
#include "Book.h"
using namespace std;

#pragma once
class LibrarySystem {
public:
	LibrarySystem();
	~LibrarySystem();
	void addBook(const int bookId, const string bookName, const int bookYear);
	void deleteBook(const int bookId);
	void addStudent(const int studentId, const string studentName);
	void deleteStudent(const int studentId);
	void checkoutBook(const int bookId, const int studentId);
	void returnBook(const int bookId);
	void showAllBooks() const;
	void showBook(const int bookId) const;
	void showStudent(const int studentId) const;
private:
	struct NodeCheckOut {
		NodeCheckOut* nextCout;
		int stuId;
		int bookId;
	};
	NodeCheckOut* headCout;
	int chechOutSize;

	struct NodeBook{
		NodeBook* nextBook;
		Book bookItem;
	};
	NodeBook* headBook;
	int bookListSize;

	struct NodeStudent {
		NodeStudent* nextStu;
		Student stuItem;
	};
	NodeStudent* headStu;
	int stuListSize;

	NodeCheckOut* findCout(int index)const;
	NodeBook* findBook(int index) const;
	NodeStudent* findStu(int index) const;
};
