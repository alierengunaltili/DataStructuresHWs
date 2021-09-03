#include "Book.h"


Book::~Book() {

}

Book::Book() {
	bookId = 0;
	bookName = "";
	bookYear = 0;
	isCheckOut = false;
}


Book::Book(const int id, const string name, const int year) {
	this->bookId = id;
	this->bookName = name;
	this->bookYear = year;
	isCheckOut = false;
}


void Book::setBool(bool is) {
	isCheckOut = is;
}

void Book::setId(int id) {
	this->bookId = id;
}

void Book::setName(string name) {
	this->bookName = name;
}

void Book::setYear(int year) {
	this->bookYear = year;
}

bool Book::getBool() {
	return isCheckOut;
}

string Book::getBookName() {
	return this->bookName;
}

int Book::getId() {
	return this->bookId;
}

int Book::getYear() {
	return this->bookYear;
}


