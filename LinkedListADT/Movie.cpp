//Ali Eren Günaltýlý 21801897 Section 01 CS
#include "Movie.h"
#include "ReservationList.h"
#include "SeatLinkedList.h"
#include "Seat.h"
#include <iostream>
#include <cstddef>
using namespace std;


Movie::Movie(const long movieID, const int audienceRadius, const int row, const int col) {
	setID(movieID);
	setRadius(audienceRadius);
	setColumn(col);
	setRow(row);
	//cout << " Movie Constructor " << endl;
	seats.createSeats(row, col, audienceRadius);
	//cout << " After seat constructor " << endl;
	setAvailableSeats(row * col);
}

bool Movie::getAvailablity(int r, int c) {
	return seats.getSeat(r, c);
}
Movie::Movie() {
	//default constructor
	//cout << "44 " << endl;
	//cout << " MOVIE CONST " << endl;
	row = 0;
	column = 0;
	movieID = 0;
	audienceRadius = 0;
	availableSeats = 0;
	//seats.createSeats(row, column, audienceRadius);
	//seats = SeatLinkedList();
}

SeatLinkedList Movie::getSeat() {
	return seats;
}

void Movie::copySeats(const SeatLinkedList& list) {
	seats = SeatLinkedList(list);
}
void Movie::setSeats(int r, int c, int radius) {
	seats.createSeats(r, c, radius);
}

Movie::~Movie() {
	//cout << " MOVIE DEST " << endl;
	//seats.~SeatLinkedList();
}



int Movie::getRadius() {
	return audienceRadius;
}
long Movie::getID() {
	return movieID;
}

void Movie::setID(const long id) {
	movieID = id;
}

void Movie::setRadius(const int radius) {
	if (radius >= 0 && radius <= 7) {
		audienceRadius = radius;
	}

	else {
		cout << "type valid radius value for movie " << endl;
	}
}

void Movie::setColumn(int movieCol) {
	if (movieCol > 0 && movieCol < 30) {
		column = movieCol;
	}
	else {
		column = 0;
	}
}

void Movie::setRow(int Mrow) {
	if (Mrow > 0 && Mrow < 32) {
		row = Mrow;
	}
	else {
		row = 0;
	}
}

void Movie::setAvailableSeats(int availableSeat) {
	availableSeats = availableSeat;
}

int Movie::getRow() {
	return row;
}

int Movie::getColumn() {
	return column;
}


int Movie::getAvailableSeats() {
	return availableSeats;
}

bool Movie::makeReservation(const int row, const int column) {
	bool flag = (seats).makeRes(row, column);
	if (flag) {
		availableSeats--;
	}

	return flag;
}

void Movie::cancelReservation(const int row, const int column) {
	//cout << "ONCE" << endl;
	bool flag = seats.cancelRes(row, column);
	//cout << "SONRA " << endl;
	if (flag) {
		availableSeats++;
	}
	
}

void Movie::printSeatOrder() {
	for (int i = 0; i < column; i++) {
		if (i == 0) {
			cout << "  ";
		}
		char ch = 65 + (i * (audienceRadius + 1));
		cout << " " << ch;
	}
	cout << endl;

	(seats).printList();
}


