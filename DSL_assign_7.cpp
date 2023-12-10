#include <iostream>
#include <limits>
using namespace std;

class Seat {
public:
    int seatNumber;
    bool isBooked;
    Seat* next;
    Seat* prev;

    Seat(int num) : seatNumber(num), isBooked(false), next(nullptr), prev(nullptr) {}
};

class Row {
public:
    Seat* head;

    Row() : head(nullptr) {}
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

    ~CinemaxTheatre() {
        for (int i = 0; i < 10; i++) {
            delete rows[i];
        }
    }

    void displayAvailableSeats() {
        cout << "Available Seats:" << endl;
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
            cout << "Invalid seat selection for booking." << endl;
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

        cout << "Seat " << seat << " in Row " << row << " is already booked or invalid." << endl;
        return false;
    }

    bool cancelBooking(int row, int seat) {
        if (row < 1 || row > 10 || seat < 1 || seat > 7 || rows[row - 1] == nullptr) {
            cout << "Invalid seat selection for cancellation." << endl;
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

        cout << "Seat " << seat << " in Row " << row << " is not booked or invalid." << endl;
        return false;
    }
};

int main() {
    CinemaxTheatre theatre;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        // Clear input buffer and handle invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cin >> choice;

        switch (choice) {
            case 1:
                theatre.displayAvailableSeats();
                break;
            case 2:
                int bookRow, bookSeat;
                cout << "Enter row and seat number to book: ";
                cin >> bookRow >> bookSeat;
                theatre.bookSeat(bookRow, bookSeat);
                break;
            case 3:
                int cancelRow, cancelSeat;
                cout << "Enter row and seat number to cancel booking: ";
                cin >> cancelRow >> cancelSeat;
                theatre.cancelBooking(cancelRow, cancelSeat);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
