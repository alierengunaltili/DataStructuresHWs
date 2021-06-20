//Ali Eren Günaltýlý 21801897 Section 01 CS
#pragma once

class Seat {

public:
	Seat();
	//~Seat();
	void setAvailable(const int no);
	bool getAvailable();
private:
	bool isAvailable;
};

