#include "ReservationList.h"
#include <cstddef>
#include <iostream>
using namespace std;

ReservationList::ReservationList() {
	//cout << " RLIST CONST " << endl;
	head = NULL;
	size = 0;
}

ReservationList::ReservationNode* ReservationList::find(int index) const {
	if (index < 1 || index > size || size == 0 || head == NULL) {
		return NULL;
	}
	else {
		ReservationNode* tmp = head;
		for (int i = 1; i < index; i++) {
			tmp = tmp->next;
		}
		return tmp;
	}
}


ReservationList::ReservationList(const ReservationList& aList) {
	if (aList.size < 1 || aList.head == NULL) {
		this->head = NULL;
		this->size = 0;
	}
	else {
		head = NULL;
		size = aList.size;
		head = new ReservationNode;
		head->Code = aList.head->Code;
		head->column = aList.head->column;
		head->movieID = aList.head->movieID;
		head->row = aList.head->row;
		// copy rest of list
		ReservationNode* newPtr = head;  // new list ptr

		for (ReservationNode* origPtr = aList.head->next;
			origPtr != NULL;
			origPtr = origPtr->next) {
			newPtr->next = new ReservationNode;
			newPtr = newPtr->next;
			newPtr->Code = origPtr->Code;
			newPtr->column = origPtr->column;
			newPtr->row = origPtr->row;
			newPtr->movieID = origPtr->movieID;
		}
		newPtr->next = NULL;
	}
}

ReservationList::~ReservationList() {
	ReservationNode* tmp = head;
	ReservationNode* cur = head;

	while (cur != NULL) {
		tmp = cur->next;
		//cout << " RESLIST DEST " << endl;
		delete cur;
		cur = tmp;
	}
}

bool ReservationList::isEmpty() const {
	return (head == NULL);
}

int ReservationList::getLength() const {
	return size;
}

bool ReservationList::used_retrieve(int index, int& resCode, int& r, int& c, long& id) const{
	if (index < 1 || index > size) {
		return false;
	}
	else {
		ReservationNode* tmp = head;
		for (int i = 1; i < index; i++) {
			tmp = tmp->next;
		}
		resCode = tmp->Code;
		r = tmp->row;
		c = tmp->column;
		id = tmp->movieID;
		return true;
	}
}

bool ReservationList::retrieve(int index, int& resCode) const {
	if (index < 1 || index > size) {
		return false;
	}
	else {
		ReservationNode* tmp = head;
		for (int i = 1; i < index; i++) {
			tmp = tmp->next;
		}
		resCode = tmp->Code;
		return true;
	}
}

bool ReservationList::used_insert(int index, int resCode, int r, int c, long id) {
	int newLength = getLength() + 1;

	if ((index < 1) || (index > newLength)) {
		return false;
	}

	ReservationNode* newPtr = new ReservationNode;
	size = newLength;
	newPtr->Code = resCode;
	newPtr->column = c;
	newPtr->row = r;
	newPtr->movieID = id;

	if (index == 1) {
		newPtr->next = head;
		head = newPtr;
	}
	else {
		ReservationNode* prev = find(index - 1);
		newPtr->next = prev->next;
		prev->next = newPtr;
	}
	return true;
}
void ReservationList::setResCode(int index, int resCode) {
	if (index < 1 || index > getLength()) {
		return;
	}
	else {
		ReservationNode* tmp = find(index);
		tmp->Code = resCode;
	}
}

bool ReservationList::insert(int index, int resCode) {
	//index = index + 1;

	int newLength = getLength() + 1;

	if ((index < 1) || (index > newLength))
		return false;

	ReservationNode* newPtr = new ReservationNode;
	size = newLength;
	newPtr->Code = resCode;
	newPtr->column = -2;
	newPtr->row = -2;
	newPtr->movieID = 0;
	

	if (index == 1) {
		newPtr->next = head;
		head = newPtr;
	}
	else {
		ReservationNode* prev = find(index - 1);
		newPtr->next = prev->next;
		prev->next = newPtr;
	}
	return true;
}

bool ReservationList::remove(int index) {
	ReservationNode* cur;
	//index = index + 1;
	if ((index < 1) || (index > getLength()))
		return false;

	--size;
	if (index == 1) {
		cur = head;
		head = head->next;
	}
	else {
		ReservationNode* prev = find(index - 1);
		cur = prev->next;
		prev->next = cur->next;
	}
	delete cur;
	//cur->next = NULL;
	//delete cur;
	cur = NULL;
	return true;
}