#include <iostream>
using namespace std;

class Seat {
public:
    int seatNumber;
    bool isBooked;
    Seat* next;
    Seat* prev;

    Seat(int num) {
        seatNumber = num;
        isBooked = false;
        next = prev = nullptr;
    }
};
class Row {
public:
    Seat* head; 
    Row() {
        head = nullptr;
    }
};
class CinemaxTheatre {
public:
    Row* rows[10];

    CinemaxTheatre() {
        for (int i = 0; i < 10; i++) {
            rows[i] = new Row;
            for (int j = 1; j <= 7; j++) {
                Seat* seat = new Seat(j);
                if (rows[i]->head == nullptr) {
                    rows[i]->head = seat;
                    seat->next = seat;
                    seat->prev = seat;
                } else {
                    Seat* lastSeat = rows[i]->head->prev;
                    lastSeat->next = seat;
                    seat->prev = lastSeat;
                    seat->next = rows[i]->head;
                    rows[i]->head->prev = seat;
                }
            }
        }
    }
    void displayAvailableSeats() {
        for (int i = 0; i < 10; i++) {
            Seat* current = rows[i]->head;
            cout << "Row " << i + 1 << ": ";
            do {
                if (current->isBooked) {
                    cout << "B  ";
                } else {
                    cout << current->seatNumber << "  ";
                }
                current = current->next;
            } while (current != rows[i]->head);
            cout << endl;
        }
    }

    bool bookSeat(int row, int seat) {
        if (row < 1 || row > 10 || seat < 1 || seat > 7 || rows[row - 1] == nullptr) {
            cout << "Invalid seat selection." << endl;
            return false;
        }

        Seat* current = rows[row - 1]->head;
        do {
            if (current->seatNumber == seat && !current->isBooked) {
                current->isBooked = true;
                cout << "Seat " << seat << " in Row " << row << " has been booked." << endl;
                return true;
            }
            current = current->next;
        } while (current != rows[row - 1]->head);

        cout << "Seat " << seat << " in Row " << row << " is already booked." << endl;
        return false;
    }
    bool cancelBooking(int row, int seat) {
        if (row < 1 || row > 10 || seat < 1 || seat > 7 || rows[row - 1] == nullptr) {
            cout << "Invalid seat selection." << endl;
            return false;
        }

        Seat* current = rows[row - 1]->head;
        do {
            if (current->seatNumber == seat && current->isBooked) {
                current->isBooked = false;
                cout << "Booking for Seat " << seat << " in Row " << row << " has been canceled." << endl;
                return true;
            }
            current = current->next;
        } while (current != rows[row - 1]->head);

        cout << "Seat " << seat << " in Row " << row << " is not booked." << endl;
        return false;
    }
};

int main() {
    CinemaxTheatre theatre;
    theatre.bookSeat(1, 3);
    theatre.bookSeat(5, 2);
    theatre.bookSeat(7, 5);
    theatre.bookSeat(2, 1);
    theatre.bookSeat(3, 7);
    theatre.bookSeat(8, 6);
    theatre.bookSeat(10, 2);
    
    cout << "Available Seats:" << endl;
    theatre.displayAvailableSeats();

    theatre.cancelBooking(5, 2);
    theatre.cancelBooking(2, 1);

    cout << "Available Seats after cancellation:" << endl;
    theatre.displayAvailableSeats();

    return 0;
}
