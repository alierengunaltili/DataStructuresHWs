#include "LibrarySystem.h"

LibrarySystem::~LibrarySystem() {

}
LibrarySystem::LibrarySystem() {
	headCout = NULL;
	headBook = NULL;
	headStu = NULL;
	bookListSize = 0;
	stuListSize = 0;
	chechOutSize = 0;
}


void LibrarySystem::addStudent(const int studentId, const string studentName) {
	if (stuListSize == 0) {
		headStu = new NodeStudent;
		headStu->stuItem = Student(studentId, studentName);
		stuListSize++;
		headStu->nextStu = NULL;
		cout << "Student " << studentId << " has been added. " << endl;
	}
	else {
		bool isAlreadyThere = false;
		NodeStudent* tmp = NULL;
		for (int i = 0; i < stuListSize; i++) {
			tmp = findStu(i);
			if (tmp->stuItem.getID() == studentId) {
				isAlreadyThere = true;
				cout << "Student " << studentId << " is already exists. " << endl;
				break;
			}
		}
		if (!isAlreadyThere) {
			tmp->nextStu = new NodeStudent;
			tmp = tmp->nextStu;
			tmp->stuItem = Student(studentId, studentName);
			stuListSize++;
			tmp->nextStu = NULL;
			cout << "Student " << studentId << " has been added. " << endl;
		}
	}
}

void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear) {
	if (bookListSize == 0) {
		headBook = new NodeBook;
		headBook->bookItem = Book(bookId, bookName, bookYear);
		bookListSize++;
		headBook->nextBook = NULL;
		cout << "Book " << bookId << " has been added." << endl;
	}
	else {
		bool isAlreadyThere = false;
		NodeBook* tmp = NULL;
		for (int i = 0; i < bookListSize; i++) {
			tmp = findBook(i);
			if (tmp->bookItem.getId() == bookId) {
				isAlreadyThere = true;
				cout << "Book that you are trying to add is already exists. " << endl;
				break;
			}
		}
		if (!isAlreadyThere) {
			tmp->nextBook = new NodeBook;
			tmp = tmp->nextBook;
			tmp->bookItem = Book(bookId, bookName, bookYear);
			bookListSize++;
			tmp->nextBook = NULL;
			cout << "Book " << bookId << " has been added." << endl;
		}
	}
}

LibrarySystem::NodeBook* LibrarySystem::findBook(int index) const {
	if (index >= bookListSize) {
		return NULL;
	}
	else {
		NodeBook* tmp = headBook;
		for (int i = 0; i < index; i++) {
			tmp = tmp->nextBook;
		}
		return tmp;
	}
}
LibrarySystem::NodeStudent* LibrarySystem::findStu(int index) const {
	if (index >= stuListSize) {
		return NULL;
	}
	else {
		NodeStudent* tmp = headStu;
		for (int i = 0; i < index; i++) {
			tmp = tmp->nextStu;
		}
		return tmp;
	}
}

LibrarySystem::NodeCheckOut* LibrarySystem::findCout(int index) const {
	if (index >= chechOutSize || index < 0) {
		return NULL;
	}
	else {
		NodeCheckOut* tmp = headCout;
		for (int i = 0; i < index; i++) {
			tmp = tmp->nextCout;
		}
		return tmp;
	}
}

void LibrarySystem::deleteBook(const int bookId) {
	bool isThere = false;
	NodeBook* tmp;
	int pre, curr;
	for (int i = 0; i < bookListSize; i++) {
		tmp = findBook(i);
		if (tmp->bookItem.getId() == bookId) {
			isThere = true;
			pre = i - 1;
			curr = i;
			break;
		}
	}
	if (isThere) {
		NodeBook* curBook;
		curBook = findBook(curr);
		if (curr == -1) {
			cout << "Book " << curBook->bookItem.getId() << " has been deleted22. " << endl;
			NodeBook* preBook;
			preBook = findBook(pre);
			preBook->nextBook = NULL;
			delete curBook;
		}
		else if (curr == 0) {
			//deleted book is head of the list.
			cout << "Book " << curBook->bookItem.getId() << " has been deleted." << endl;
			NodeBook* newHead = curBook->nextBook;
			curBook->nextBook = NULL;
			delete curBook;
			headBook = newHead;
		}
		else {
			cout << "Book " << curBook->bookItem.getId() << " has been deleted111." << endl;
			NodeBook* preBook = findBook(pre);
			preBook->nextBook = curBook->nextBook;
			curBook->nextBook = NULL;
			delete curBook;
		}
		bookListSize--;
	}
}

void LibrarySystem::deleteStudent(const int studentId) {
	bool isThere = false;
	NodeStudent* tmp;
	int pre, curr;
	for (int i = 0; i < stuListSize; i++) {
		tmp = findStu(i);
		if (tmp->stuItem.getID() == studentId) {
			isThere = true;
			pre = i - 1;
			curr = i;
			break;
		}
	}

	if (isThere){
		NodeStudent* currStu;
		currStu = findStu(curr);
		if (curr == stuListSize - 1) {
			cout << "Student " << currStu->stuItem.getID() << " has been deleted." << endl;
			NodeStudent* preStu;
			preStu = findStu(pre);
			preStu->nextStu = NULL;
			delete currStu;
			stuListSize--;
		}
		else if(curr == 0){
			cout << "Student " << currStu->stuItem.getID() << " has been deleted." << endl;
			NodeStudent* newHead = currStu->nextStu;
			currStu->nextStu = NULL;
			delete currStu;
			headStu = newHead;
			stuListSize--;
		}
		else {
			cout << "Student " << currStu->stuItem.getID() << " has been deleted." << endl;
			NodeStudent* preStu;
			preStu = findStu(pre);
			preStu->nextStu = currStu->nextStu;
			currStu->nextStu = NULL;
			delete currStu;
			stuListSize--;
		}
	}
}

void LibrarySystem::showBook(const int bookId) const{
	bool isExist = false;
	NodeBook* tmp = NULL;
	for (int i = 0; i < bookListSize; i++) {
		tmp = findBook(i);
		if (tmp->bookItem.getId() == bookId) {
			isExist = true;
			break;
		}
	}
	if (isExist) {
		cout << "Book Id" << "\t" << "Book Name" << "\t" << "Year" << endl;
		cout << tmp->bookItem.getId() << "\t" << tmp->bookItem.getBookName() << "\t" << tmp->bookItem.getYear() << endl;
	}
	else {
		cout << "Book trying to showed does not exist." << endl;
	}
}

void LibrarySystem::showStudent(const int studentId) const {
	bool isExist = false;
	NodeStudent* tmp = NULL;
	for (int i = 0; i < stuListSize; i++) {
		tmp = findStu(i);
		if (tmp->stuItem.getID() == studentId) {
			isExist = true;
			break;
		}
	}
	if (isExist) {
		cout << "Student Id " << tmp->stuItem.getID() << " with name " << tmp->stuItem.getName() << endl;
	}
	else{
		cout << "Student trying to showed does not exist. " << endl;
	}
}


void LibrarySystem::checkoutBook(const int bookId, const int studentId) {
	bool isBookExist = false;
	bool isCheckOut = true;
	NodeBook* tmp = NULL;
	for (int i = 0; i < bookListSize; i++) {
		tmp = findBook(i);
		if (tmp->bookItem.getId() == bookId) {
			isBookExist = true;
			isCheckOut = tmp->bookItem.getBool();
			break;
		}
	}
	if (isBookExist) {
		if (!isCheckOut) {
			if (chechOutSize == 0) {
				headCout = new NodeCheckOut;
				headCout->nextCout = NULL;
				headCout->bookId = bookId;
				headCout->stuId = studentId;
				chechOutSize++;
				tmp->bookItem.setBool(true);
			}
			else {
				NodeCheckOut* tmpCout = NULL;
				tmpCout = findCout(chechOutSize - 1);
				tmpCout->nextCout = new NodeCheckOut;
				tmpCout = tmpCout->nextCout;
				tmpCout->bookId = bookId;
				tmpCout->stuId = studentId;
				tmpCout->nextCout = NULL;
				chechOutSize++;
				tmp->bookItem.setBool(true);
			}
			cout << "Book " << bookId << " is checked out by student " << studentId << endl;
		}
		else {
			cout << "Book is already checked out by other student. " << endl;
		}
	}
	else {
		cout << "Book for checkout does not exists. " << endl;
	}
}

void LibrarySystem::returnBook(const int bookId) {
	bool isOnList = false;
	NodeCheckOut* tmp = NULL;
	NodeCheckOut* prev = NULL;
	int index = -1;
	for (int i = 0;  i < chechOutSize; i++) {
		tmp = findCout(i);
		if (tmp->bookId == bookId) {
			index = i;
			isOnList = true;
			break;
		}
	}
	if (isOnList) {
		if (index == 0) {
			if (chechOutSize > 1){
				NodeCheckOut* newhead = headCout->nextCout;
				headCout->nextCout = NULL;
				delete headCout;
				headCout = newhead;
				chechOutSize--;
			}
			else {
				headCout->nextCout = NULL;
				delete headCout;
				chechOutSize = 0;
			}
		}
		else {
			NodeCheckOut* prev = findCout(index - 1);
			prev->nextCout = tmp->nextCout;
			tmp->nextCout = NULL;
			NodeBook* book = NULL;
			for (int i = 0; i < bookListSize; i++) {
				book = findBook(i);
				if (book->bookItem.getId() == bookId) {
					book->bookItem.setBool(false);
					break;
				}
			}
			delete tmp;
			chechOutSize--;
		}
		cout << "Book " << bookId << " is succesfully returned to the library. " << endl;
	}
}

void LibrarySystem::showAllBooks() const{
	NodeBook* tmp = NULL;
	int studentId = 0;
	cout << "Book Id" << "\t" << "Book Name" << "\t" << "Year" << "\t" << "Status" << endl;
	for (int i = 0; i < bookListSize; i++) {
		tmp = findBook(i);
		if (tmp->bookItem.getBool()) {
			for (int i = 0; i < chechOutSize; i++) {
				NodeCheckOut* cot = findCout(i);
				if (cot->bookId == tmp->bookItem.getId()) {
					studentId = cot->stuId;
				}
			}
			cout << tmp->bookItem.getId() << "\t" << tmp->bookItem.getBookName() << "\t" << tmp->bookItem.getYear() << "\t" << "Checked by student number " << studentId << endl;
		}
		else {
			cout << tmp->bookItem.getId() << "\t" << tmp->bookItem.getBookName() << "\t" << tmp->bookItem.getYear() << "\t" << "Not taken" << endl;
		}
	}
}











