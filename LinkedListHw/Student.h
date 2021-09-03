#include <iostream>
using namespace std;
#include <string>

#pragma once
class Student
{
private:
	int id;
	string name;
public:
	Student();
	Student(int i, string n);
	~Student();
	int getID();
	string getName();
	void setID(int i);
	void setName(string n);
};

