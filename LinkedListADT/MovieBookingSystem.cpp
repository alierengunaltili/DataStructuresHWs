
#include "MovieBookingSystem.h"
#include <cstddef>
#include <iostream>
#include <time.h>
#include <ctime>
#include <string>
#pragma warning(disable : 4996)
using namespace std;


/*MovieBookingSystem();
~MovieBookingSystem();
void addMovie(const long movieID, const int audienceRadius);
void cancelMovie(const long movieID);
void showAllMovies() const; void showMovie(const long movieID) const;

int makeReservation(const long movieID, const int row, const char
	col);
void cancelReservations(ReservationList resCode);
void showReservation(const int resCode) const;
*/

//constructor
MovieBookingSystem::MovieBookingSystem() {
	head = NULL;
	size = 0;
	resCode = 1;
	cout << "--------------------------" << endl;
	cout << "When using ReservationList class methods I implemented them similar to lecture slides." << endl; 
	cout << "Therefore, it's starting index is 1 not 0." << endl;
	cout << "To see it workes properly;" << endl;
	cout << "it needs RL.remove(1) not RL.remove(0) or it needs to get RL.insert(1, codes[0]) not RL.insert(0, codes[0])" 
		<< endl;
		cout << "-----------------------" << endl;
	cout << endl;
	//cout << " BOOKING SYSTEM CONST " << endl;
}

//destructor
MovieBookingSystem::~MovieBookingSystem() {
	if (size <= 0) {

	}
	else {
		//cout << " BOOKING SYSTEM DEST " << endl;
		if (head != NULL) {
			MovieNode* tmp = head;
			MovieNode* next_tmp = head;
			for (int i = 1; i < size + 1; i++) {
				next_tmp = next_tmp->next;
				delete tmp;
				tmp = next_tmp;
			}
		}
	}
}

void MovieBookingSystem::showReservation(const int resCode)const {
	if (resCode <= 0) {
		cout << "No reservation with code " << resCode << endl;
	}
	bool isAvailable = false;
	bool isExist = false;
	int cod;
	int row;
	int column;
	long id;
	int radius = 0;
	for (int i = 1; i < reservationCodes.getLength() + 1; i++) {
		reservationCodes.used_retrieve(i, cod, row, column, id);
		if (resCode == cod) {
			isExist = true;
			for (int i = 1; i < size + 1; i++) {
				MovieNode* tmp = find(i);
				if (id == tmp->movie.getID()) {
					radius = tmp->movie.getRadius();
					isAvailable = tmp->movie.getAvailablity(row, column);
				}
			}
			const char ch = 65 + (((column - 1) * (radius + 1)));
			time_t rawtime;
			rawtime = (const time_t)id;
			if (!isAvailable) {
				cout << "Reservation with Code:  " << resCode << ": Seat " << ch << (((row - 1) * (radius + 1)) + 1)
					<< " in Movie at " << ctime(&rawtime);
			}
			else {
				cout << "No reservation with Code " << resCode << endl;
			}
		}
	}
	if (!(isExist)) {
		cout << "No reservation with code " << resCode << endl;
	}
}

void MovieBookingSystem::cancelReservation(int resCode) {
	bool isExist = false;
	int tmp;
	int row, column;
	long id;
	int indexOfResList;
	for (int i = 1; i < reservationCodes.getLength() + 1; i++) {
		reservationCodes.used_retrieve(i, tmp, row, column, id);
		if (tmp == resCode && row != -2 && column != -2 && id != 0) {
			//cout << "offffff " << id <<  endl;
			//cout << "1111---" << row << " " << column << endl;
			isExist = true;
			if (isExist) {
				//reservationCodes.setResCode(indexOfResList, -5);
				MovieNode* mov;
				for (int i = 1; i < size + 1; i++) {
					//cout << " 55555 ___ " << i  << endl;
					mov = find(i);
					if (mov->movie.getID() == id) {
						//cout << "222222----" << row << " " << column << endl;

						//cout << "row " << row << " column " << column << " " <<
							//mov->movie.getID() << " available seats " << mov->movie.getAvailableSeats() << endl;
						//cout << "99999 " << endl;
						//mov->movie.printSeatOrder();
						//Movie newMovie = Movie(mov->movie.getID(), mov->movie.getRadius(), mov->movie.getRow(), mov->movie.getColumn());
						//newMovie.copySeats(mov->movie.getSeat());
						//mov->movie.printSeatOrder();
						mov->movie.cancelReservation(row, column);
						//cout << "00000---" << row << " " << column << endl;
						const char ch = 65 + (((column - 1) * (mov->movie.getRadius() + 1)));
						time_t rawtime;
						rawtime = (const time_t)id;
						cout << "Res Code:  " << (resCode) << " , " << ch << (((row - 1) * (mov->movie.getRadius() + 1)) + 1)
							<< " is cancelled for movie " << ctime(&rawtime) << endl;
					}
				}
			}
			//indexOfResList = i;
		}
	}
	
}
void MovieBookingSystem::cancelReservations(ReservationList rList) {
	int num;
	bool canCancel = true;

	//if (rList.getLength() > reservationCodes.getLength()) {
		//canCancel = false;
	//}

	for (int i = 1; i < rList.getLength() + 1; i++) {
		rList.retrieve(i, num);
		//cout << "NUMMM" << " " << num << endl;
		if (num <= 0) {
			canCancel = false;
		}
	}
	//cout << " can cancel " << canCancel << endl;
	int tmp1, tmp2;
	if (canCancel) {
		for (int i = 1; i < reservationCodes.getLength() + 1; i++) {
			reservationCodes.retrieve(i, tmp1);
			for (int j = 1; j < rList.getLength() + 1; j++) {
				rList.retrieve(j, tmp2);
				if (tmp1 == tmp2) {
					//cout << " burasiii " << tmp1 <<  endl;
					cancelReservation(tmp1);
				}
			}
		}
	}
	else {
		cout << "Some reservation codes do not exist. Cancellation is failed. " << endl;
	}
}

int MovieBookingSystem::makeReservation(const long movieID, const int row, const char col) {
	if (size == 0) {
		cout << "There is no movie to make reservation on the list. " << endl;
		return -1;
	}
	time_t rawtime;
	rawtime = (const time_t)movieID;
	int tmp_row;
	int tmp_col;
	bool isFinded = false;
	MovieNode* tmp = head;
	MovieNode* reservedOne = NULL;
	for (int i = 1; i < size + 1; i++) {
		tmp = find(i);
		if (tmp->movie.getID() == movieID) {
			isFinded = true;
			reservedOne = tmp;
		}
	}
	//cout << " is FINDED  " << isFinded << endl;
	if (isFinded) {
		//tmp->makeReservation(row, col);
		bool isOccupied;
		if ((row - 1) % (reservedOne->movie.getRadius() + 1) == 0) {
			tmp_row = (row - 1) / (reservedOne->movie.getRadius() + 1);
		}
		else {
			time_t rawtime;
			rawtime = (const time_t)movieID;
			cout << "Seat " << col << row << " is not occupiable movie at " << ctime(&rawtime);
			return -1;
		}
		tmp_col = col - 65;
		if ((tmp_col % (reservedOne->movie.getRadius() + 1)) == 0) {
			tmp_col = tmp_col / (reservedOne->movie.getRadius() + 1);
		}
		else {
			cout << "Invalid row and column for movie with ID: " << movieID << endl;
			return -1;
		}

		isOccupied = reservedOne->movie.makeReservation(tmp_row + 1 , tmp_col + 1);

		if (!isOccupied) {
			cout << "Seat " << col << row << " is not available for " << ctime(&rawtime);
			return -1;
		}
		cout << "Reservation is done for the seat " << col << row << ", in Movie at " << ctime(&rawtime);
		reservationCodes.used_insert(1, resCode, tmp_row + 1, tmp_col + 1, movieID);
		//cout << " ERQEREQREQQ" << resCode << endl;
		resCode++;
		return (resCode - 1);
	}
}

void MovieBookingSystem::showMovie(const long movieID) const {
	bool isExist = false;
	MovieNode* tmp = NULL;
	//Movie movie_tmp;

	for (MovieNode* origPtr = head;
		origPtr != NULL;
		origPtr = origPtr->next) {

		if (origPtr->movie.getID() == movieID) {
			isExist = true;
			//movie_tmp = origPtr->movie;
			tmp = origPtr;
		}
	}

	if (isExist) {
		time_t rawtime;
		rawtime = (const time_t)tmp->movie.getID();
		cout << "Movie has " << tmp->movie.getAvailableSeats() << " available seats, which is at " << ctime(&rawtime);
		tmp->movie.printSeatOrder();
		tmp = NULL;
		//tmp->movie.printSeatOrder();
		//tmp->movie.printSeatOrder();
	} 
	else {
		time_t rawtime;
		rawtime = (const time_t)movieID;
		cout << "Movie is not exists which is at " << ctime(&rawtime); 
	}
}





void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius) {
	int row, column;
	time_t rawtime;

	if (audienceRadius > 7 || audienceRadius < 0) {
		cout << "Type valid audience radius for movie between 7 and 0 inclusive.  " << endl;
		return;
	}
	for (int i = 1; i < size + 1; i++) {
		MovieNode* tmp;
		tmp = find(i);
		if (tmp->movie.getID() == movieID) {
			rawtime = (const time_t)movieID;
			cout << "Movie is already exists which is at " << ctime(&rawtime);
			return;
		}
	}

	if (numOfColumn % (audienceRadius + 1) == 0) {
		column = numOfColumn / (audienceRadius + 1);
	}
	else {
		column = (numOfColumn / (audienceRadius + 1)) + 1;
	}
	if (numOfRow % (audienceRadius + 1) == 0) {
		row = numOfRow / (audienceRadius + 1);
	}
	else {
		row = (numOfRow / (audienceRadius + 1)) + 1;
	}

	rawtime = (const time_t)movieID;
	cout << "Addition of movie is done , Currently added movie at " << ctime(&rawtime);
	if (size == 0) {
		//cout << " ?????" << endl;
		head = new MovieNode;
		//cout << " XXXXX" << endl;
//		head->movie = Movie(movieID, audienceRadius, row, column);
		head->movie.setID(movieID);
		head->movie.setColumn(column);
		head->movie.setRadius(audienceRadius);
		head->movie.setRow(row);
		//cout << " ZZZZZ" << endl;
		head->movie.getSeat().~SeatLinkedList();
		head->movie.setSeats(row, column, audienceRadius);
		head->movie.setAvailableSeats(row * column);
		//cout << "YYYYY" << endl;
		size++;
		head->next = NULL;
	}
	else {
		//cout << " CH " << endl;
		MovieNode* ptr = find(size);
		//cout << " CH222" << endl;
		ptr->next = new MovieNode;
		ptr = ptr->next;
		ptr->movie.setID(movieID);
		ptr->movie.setColumn(column);
		ptr->movie.setRow(row);
		ptr->movie.setRadius(audienceRadius);
		ptr->movie.getSeat().~SeatLinkedList();
		ptr->movie.setSeats(row, column, audienceRadius);
		ptr->movie.setAvailableSeats(row * column);
		size++;
		ptr->next = NULL;
	}
}

void MovieBookingSystem::cancelMovie(const long movieID) {
	bool isFinded = false;

	MovieNode* prev = NULL;
	MovieNode* cancelled = NULL;
	int i = 0;
	int index = 0;
	for (MovieNode* mov = head;
		mov != NULL;
		mov = mov->next) {
		i++;
		if (mov->movie.getID() == movieID) {
			isFinded = true;
			index = i;
		}
	}
	time_t rawtime;
	rawtime = (const time_t)movieID;

	if (isFinded) {
		if (index == 1) {
			//head is the one cancelled
			cancelled = head;
			head = head->next;
			cancelled->next = NULL;
			//cout << " 222222 " << endl;
			delete cancelled;
			cancelled = NULL;
			size--;
			int tmp_code;
			int tmp_row;
			int tmp_col;
			long tmp_id;
			for (int i = 1; i < reservationCodes.getLength() + 1; i++) {
				reservationCodes.used_retrieve(i, tmp_code, tmp_row, tmp_col, tmp_id);
				if (movieID == tmp_id) {
					reservationCodes.setResCode(i, -5);
				}
			}
			cout << " Movie is cancelled which is at " << ctime(&rawtime);
		}
		else {
			MovieNode* origPtr = find(index - 1);
			cancelled = find(index);
			origPtr->next = cancelled->next;
			cancelled->next = NULL;
			//cout << " 333333 " << endl;
			delete cancelled;
			cancelled = NULL;
			origPtr = NULL;
			size--;
			int tmp_code;
			int tmp_row;
			int tmp_col;
			long tmp_id;
			for (int i = 1; i < reservationCodes.getLength() + 1; i++) {
				reservationCodes.used_retrieve(i, tmp_code, tmp_row, tmp_col, tmp_id);
				if (movieID == tmp_id) {
					reservationCodes.setResCode(i, -5);
				}
			}
			cout << " Movie is cancelled which is at " << ctime(&rawtime);
		}
	}
	else {
		cout << " Movie to be cancelled is not exists which is at " << ctime(&rawtime);
		return;
	}
}

MovieBookingSystem::MovieNode* MovieBookingSystem::find(int index) const {
	if (index < 1 || index > size || size == 0) {
		return NULL;
	}
	else {
		MovieNode* tmp = head;
		for (int i = 1; i < index; i++) {
			tmp = tmp->next;
		}
		return tmp;
	}
}

void MovieBookingSystem::showAllMovies() const {

	if (size == 0) {
		cout << "No movie is on show currently. " << endl;
	}
	time_t rawtime;
	cout << endl;
	cout << "Movies on show: " << endl;
	for (MovieNode* origptr = head;
		origptr != NULL;
		origptr = origptr->next) {
		rawtime = (const time_t)origptr->movie.getID();
		cout <<"Movie has " << origptr->movie.getAvailableSeats() << " available seats. Movie is at " << ctime(&rawtime);
	}
	cout << endl;
}




