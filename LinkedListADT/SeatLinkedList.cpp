#include "SeatLinkedList.h"
#include <cstddef>
#include <iostream>
using namespace std;

SeatLinkedList::~SeatLinkedList() {
	if (row_head != NULL) {
		SeatNode* cur_tmp = row_head;
		SeatNode* d;
		SeatNode* n;

		for (int i = 1; i < row + 1 ; i++) {
			n = cur_tmp->next;
			for (int j = 1; j < col + 1; j++) {
				d = cur_tmp->down;
				//cout << " SEAT DESTRUCTOR " << endl;

				delete cur_tmp;
				cur_tmp = d;
			}
			cur_tmp = n;
			//cout << endl;
		}
	}
}


SeatLinkedList::SeatLinkedList() {
	//cout << " EEEE " << endl;
	row = 0;
	col = 0;
	audienceRadius = 0;
	//cout << " SEAT LIST CONST  " << endl;
	row_head = NULL;
}

bool SeatLinkedList::isEmpty() {
	if (row < 1 || col < 1) {
		return false;
	}
	else
		return true;
}

SeatLinkedList::SeatLinkedList(const SeatLinkedList& aList) {
	row = aList.row;
	col = aList.col;
	row_head = aList.row_head;
	audienceRadius = aList.audienceRadius;
	if (row < 0 || col < 0 || row_head == NULL) {
		row = 0;
		col = 0;
		row_head = NULL;
	}
	else {
		//cout << " SEAT COPY " << endl;
		this->createSeats(row, col, audienceRadius);
		for (int i = 1; i < row + 1; i++) {
			for (int j = 1; j < col; j++) {
				find(i, j)->seat = aList.find(i, j)->seat;
			}
		}
	}
}

void SeatLinkedList::createSeats(int row, int col, int radius) {
	if (row < 1 || col < 1) {
		this->audienceRadius = 0;
		this->row = 0;
		this->col = 0;
		this->row_head = NULL;
		//cout << " invalid row and column value " << endl;
	}
	else {
		row_head = new SeatNode;
		//cout << " SEAT CREATION " << endl;
		this->audienceRadius = radius;
		this->row = row;
		this->col = col;
		SeatNode* stNode = row_head;
		for (int i = 1; i < row; i++) {
			SeatNode* down_tmp = stNode;
			for (int j = 1; j < col; j++) {
				down_tmp->down = new SeatNode;
				down_tmp = down_tmp->down;
				down_tmp->next = NULL;
			}
			down_tmp->down = NULL;
			stNode->next = new SeatNode;
			stNode = stNode->next;
		}
		SeatNode* tmp = stNode;
		stNode->next = NULL;
		for (int i = 1; i < col; i++) {
			tmp->down = new SeatNode;
			tmp = tmp->down;
			tmp->next = NULL;
		}
		//cout << " BASLANGIC" << endl;
		/*for (int i = 1; i < row + 1; i++) {
			for (int j = 1; j < col; j++) {
				down_tmp->down = new SeatNode;
				down_tmp = down_tmp->down;
				down_tmp->next = NULL;
				down_tmp->seat =Seat();
			}
			down_tmp->down = NULL;
			stNode->next = new SeatNode;
			stNode = stNode->next;
			down_tmp = stNode;
			stNode->seat =Seat();
		}
		stNode->next = NULL;
		*/

	}
	//cout << " BITIS" << endl;
}

int SeatLinkedList::getRow() const {
	return row;
}
int SeatLinkedList::getColumn() const {
	return col;
}
bool SeatLinkedList::retrieve(int row, int column, Seat& seatItem) const {
	if (row < 1 || col < 1 || row_head == NULL) {
		return false;
	}
	else {
		Seat s;
		SeatNode* node = find(row, column);
		s = (node->seat);
		seatItem = s;
		return true;
	}
}

SeatLinkedList::SeatNode* SeatLinkedList::find(int r, int c) const {

	if (r < 1 || r > getRow() || c > getColumn() || c < 1 || row_head == NULL) {
		//cout << " RERERERE" << endl;
		return NULL;
	}

	else {
		SeatNode* tmp = row_head;

		for (int i = 1; i < r; i++) {
			tmp = tmp->next;
		}

		for (int i = 1; i < c; i++) {
			tmp = tmp->down;
		}
		return tmp;
	}

}

bool SeatLinkedList::cancelRes(int row, int column) {

	if (row < 1 || row > this->row || column < 1 || column > col) {
		//cout << " type valid row and column for cancelling reservation " << endl;
		return false;
	}
	else {
		SeatNode* tmp = find(row, column);

		if (tmp->seat.getAvailable()) {
			//cout << " seat is already available " << endl;
			return false;
		}
		else {
			tmp->seat.setAvailable(1);
			//cout << " !!!!! " << endl;
			return true;
		}
	}
}

bool SeatLinkedList::getSeat(int r, int c) {
	if (row < 1 || row > this->row || c < 1 || c > col) {
		return false;
	}
	else {
		SeatNode* tmp = find(r, c);
		return (tmp->seat.getAvailable()); // return true mean, seat is not reserved
	}
}
bool SeatLinkedList::makeRes(int row, int column) {
	if (row < 1 || row > this->row || column < 1 || column > col) {
		//cout << " Type valid row and column for reservation " << endl;
		return false;
	}
	else {

		SeatNode* tmp = find(row, column);
		if (!(tmp->seat.getAvailable())) {
			//cout << " Seat is already reserved " << endl;
			return false;
		}
		else {
			//cout << row << "  " << column << endl;
			//cout << " 23232" << endl;
			(tmp->seat).setAvailable(0);
			return true;
		}
	}
}

void SeatLinkedList::printList() {

	//row_head->next->next->next->next = NULL;
	//if (row_head->next->next == NULL) {
		//cout << " HEAD IS NULL " << endl;
//	}
	SeatNode* tmp = row_head;
	SeatNode* row_tmp = row_head;

	for (int i = 1; i < row + 1; i++) {
		for (int j = 1; j < col + 1; j++) {
			if (j == 1) {
				cout << 1 + ((i-1) * (audienceRadius + 1));
				if ((1 + ((i-1) * (audienceRadius + 1))) >= 10) {
					cout << " ";
				}
				else {
					cout << "  ";
				}
			}
			if (tmp->seat.getAvailable()) {
				cout << "O ";
			}
			else {
				cout << "X ";
			}
			tmp = tmp->down;
		}
		row_tmp = row_tmp->next;
		tmp = row_tmp;
		cout << endl;
	}
}

/* 
int getRow() const;
	int getColumn() const;
	bool retrieve(int row, int column, Seat& seatItem) const;
	bool cancelRes(int row, int column, Seat& seat);
	bool makeRes(int row, int column, Seat& seat);
*/


