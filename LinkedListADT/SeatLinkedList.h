#pragma once
#include "Seat.h"
class SeatLinkedList
{
public:
	SeatLinkedList();
	//SeatLinkedList(int row , int col, int radius);
	~SeatLinkedList();
	SeatLinkedList(const SeatLinkedList& aList);
	bool isEmpty();
	int getRow() const;
	int getColumn() const;
	bool retrieve(int row, int column, Seat& seatItem) const;
	bool cancelRes(int row, int column);
	bool makeRes(int row, int column);
	void printList();
	void createSeats(int row, int col, int radius);
	bool getSeat(int row, int col);
private:
	struct SeatNode {
		Seat seat;
		SeatNode* down;
		SeatNode* next;
	};
	int audienceRadius;
	int row;
	int col;
	SeatNode* row_head;
	SeatNode* find(int r, int c) const;

};



