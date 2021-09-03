#include "Student.h"

Student::Student() {
	this->id = 0;
	this->name = " ";
}

Student::~Student() {

}

Student::Student(int i, string n) {
	setID(i);
	setName(n);
}

void Student::setID(int i) {
	this->id = i;
}

void Student::setName(string n) {
	this->name = n;
}

int Student::getID() {
	return this->id;
}

string Student::getName() {
	return this->name;
}
