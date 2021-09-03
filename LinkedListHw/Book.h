#include <iostream>
#include <string>
using namespace std;

#pragma once
class Book
{
private:
	bool isCheckOut;
	int bookId;
	string bookName;
	int bookYear;
public:
	~Book();
	Book();
	Book(const int id, const string name, const int year);
	void setBool(bool isC);
	void setId(int id);
	void setName(string name);
	void setYear(int year);
	int getId();
	int getYear();
	bool getBool();
	string getBookName();
};

