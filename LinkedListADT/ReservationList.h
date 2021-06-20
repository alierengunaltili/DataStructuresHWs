#pragma once

class ReservationList {
public:
	ReservationList();
	ReservationList(const ReservationList& aList);
	~ReservationList();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index, int& resCode) const;
	bool insert(int index, int resCode);
	bool remove(int index);
	bool used_insert(int index, int resCode, int r, int c, long id);
	bool used_retrieve(int index, int& resCode, int& r, int& c, long& id) const;
	void setResCode(int index, int resCode);

private:
	struct ReservationNode {
		int row;
		int column;
		long movieID;
		int Code;
		ReservationNode* next;
	};
	int size;
	ReservationNode* head;
	ReservationNode* find(int index) const;

	// ...
	//you may define additional member functions and data members, if necessary 
};