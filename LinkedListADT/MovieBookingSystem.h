#pragma once
#include "ReservationList.h"
#include "Movie.h"
#include "Seat.h"
#include "SeatLinkedList.h"

class MovieBookingSystem {
public:
	const static int numOfRow = 30;
	const static int numOfColumn = 26;
	MovieBookingSystem();
	~MovieBookingSystem();
	void addMovie(const long movieID, const int audienceRadius);
	void cancelMovie(const long movieID);
	void showAllMovies() const; void showMovie(const long movieID) const;
	int makeReservation(const long movieID, const int row, const char
		col);
	void cancelReservations(ReservationList resCode);
	void showReservation(const int resCode) const;
private:
	ReservationList reservationCodes;
	struct MovieNode {
		MovieNode* next;
		Movie movie;
	};
	int resCode;
	int size;
	MovieNode* head;
	MovieNode* find(int index) const;
	void cancelReservation(int resCode);
	// ...
	//you may define additional member functions and data members, if necessary.
};