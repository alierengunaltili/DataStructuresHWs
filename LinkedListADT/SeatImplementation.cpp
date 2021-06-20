// SeatImplementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;
#include "MovieBookingSystem.h"

int main()
{
    std::cout << "Hello World!\n";
    /*SeatLinkedList s1(5, 4, 3);
    Seat seat;
    //s1.retrieve(2, 2, seat);
    s1.printList();
    s1.makeRes(4, 4);
    cout << " --------------" << endl;
    s1.printList();
    s1.cancelRes(4, 4);
    cout << " ------------ " << endl;
    s1.printList();
    s1.makeRes(3, 5);
    s1.makeRes(2, 1);
    s1.makeRes(2, 3);
    s1.printList();
    */
    cout << " *****************************" << endl;

    /*Movie movie(13432434, 5, 4, 4);
    movie.printSeatOrder();
    movie.makeReservation(3, 3);
    cout << endl;
    movie.printSeatOrder();
    cout << " -----------------" << endl;
    movie.cancelReservation(3, 3);
    movie.printSeatOrder();
    */
    /*cout << " ---------------BELOW-----------" << endl;
    int* codes = new int[2];
    ReservationList RL;
    MovieBookingSystem M;
    M.showAllMovies();
    M.addMovie(1614791273, 0);
    M.addMovie(1614801273, 3);
    M.addMovie(1615801273, 1);
    cout << endl;
    M.showAllMovies();
    cout << "**********" << endl;
    M.showMovie(1614791273);
    cout << endl;
    M.cancelMovie(1614791273);
    cout << endl;
    M.showMovie(1614791273);
    cout << " ---------" << endl;
    M.showAllMovies();
    cout << "-----------" << endl;
    M.addMovie(1614791273,5);
    cout << " --------------" << endl;
    M.showMovie(1614791273);
    M.showAllMovies();
    //M.makeReservation(1614801273, 13, 'H');
    //M.makeReservation(1614791273, 1, 'A');
    M.showMovie(1614791273);
    M.showMovie(1614801273);
    codes[0] = M.makeReservation(1614801273, 25, 'Q');
    codes[1] = M.makeReservation(1614801273, 29, 'Y');
    RL.insert(1, codes[0]);
    RL.insert(1, codes[1]);
    int num1, num2;
    RL.retrieve(1, num1);
    RL.retrieve(2, num2);
    cout << "!!!!!!!!" << num1 << " " << num2 << endl;
    M.showMovie(1614801273);
    M.cancelReservations(RL);
    M.showMovie(1614801273);
    */
    //-----------------------------------------

    MovieBookingSystem M;
    int* codes = new int[2];
    ReservationList RL;
    M.showAllMovies();
    cout << endl;
    M.addMovie(1614791273, 0);
    M.addMovie(1614801273, 3);
    M.addMovie(1615801273, 1);
    cout << endl;
    M.showAllMovies();
    cout << endl;
    M.addMovie(1614791273, 2);
    cout << endl;
    codes[1] = M.makeReservation(1614801273, 1, 'A');
    codes[0] = M.makeReservation(1614801273, 9, 'A');
    RL.insert(1, codes[1]);
    RL.insert(1, codes[0]);
    cout << endl;
    M.showMovie(1614801273);
    cout << endl;
    M.showReservation(codes[0]);
    cout << endl;
    M.cancelReservations(RL);
    cout << endl; codes[0] = M.makeReservation(1614801273, 1, 'A');
    M.makeReservation(1614801273, 1, 'A');
    M.makeReservation(1614801273, 5, 'E');
    M.makeReservation(1614801273, 5, 'M');
    cout << endl;
    RL.remove(1);
    RL.remove(1);
    RL.insert(1, -1);
    RL.insert(1, codes[0]);
    M.cancelReservations(RL);
    M.showReservation(codes[0]);
    cout << endl;
    M.makeReservation(1614801273, 12, 'D');
    cout << endl;
    M.showMovie(1614801273);
    cout << endl;
    M.cancelMovie(1614801273);
    M.showReservation(codes[0]);
    cout << endl;
    M.cancelMovie(1614801273);
    M.addMovie(1614801273, 4);
    M.showMovie(1614801273);
    M.showAllMovies();
    M.cancelMovie(1614791273);
    M.showMovie(1614791273);
    M.showAllMovies();
    M.addMovie(1614791273, 3);
    M.showMovie(1614791273);
    int num = M.makeReservation(1614791273, 25, 'Y');
    RL.remove(1);
    RL.remove(1);
    RL.insert(1, num);
    M.showReservation(num);
    M.showMovie(1614791273);
    M.cancelReservations(RL);
    M.showMovie(1614791273);
    //cout << " 22222222222222222222222222222222222" << endl;
    delete[] codes;
    return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
