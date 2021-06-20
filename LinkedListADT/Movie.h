//Ali Eren Günaltýlý 21801897 Section 01 CS
#include "Seat.h"
#include "SeatLinkedList.h"
#pragma once
class Movie
{
public:
	Movie();
	Movie(const long movieID, const int audienceRadius, const int row, const int col);
	~Movie();
	void setID(long ID);
	void setRadius(int radius);
	long getID();
	int getRadius();
	int getRow();
	int getColumn();
	void setRow(int ro);
	void setColumn(int col);
	int getAvailableSeats();
	void setAvailableSeats(int availableSeat);
	void printSeatOrder();
	bool makeReservation(const int row, const int column);
	//Seat** getSeatOrder();
	void cancelReservation(const int row, const int column);
	void setSeats(int row, int col, int radius);
	SeatLinkedList getSeat();
	void copySeats(const SeatLinkedList& list);
	bool getAvailablity(int row, int col);
	//void deleteSeats();
	//void copySeats(Seat** s, const int r, const int c);
private:
	long movieID;
	int audienceRadius;
	int row;
	int column;
	int availableSeats;
	SeatLinkedList seats;
};
