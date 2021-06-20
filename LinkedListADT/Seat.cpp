//Ali Eren Günaltýlý 21801897 Section 01 CS
#include "Seat.h"
using namespace std;
#include <iostream>


Seat::Seat() {
	//cout << " SEAT CONST " << endl;
	isAvailable = true;
}

void Seat::setAvailable(const int no) {
	if (no == 0) {
		isAvailable = false;
	}
	if (no == 1) {
		isAvailable = true;
	}
}

bool Seat::getAvailable() {
	return isAvailable;
}