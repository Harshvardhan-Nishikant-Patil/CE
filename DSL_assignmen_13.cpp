#include <iostream>

using namespace std;

class Deque {
private:
    static const int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    int front, rear;

public:
//initializing to -1 that means it shows empty queue
    Deque() : front(-1), rear(-1) {}

    void enqueueFront(int value) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
            cout << "Deque is full. Cannot enqueue at the front." << endl;
        } 
        else {
            if (front == -1) {
                front = rear = 0;
            }
            else if (front == 0) {
                front = MAX_SIZE - 1;
            }
            else {
                front--;
            }
            arr[front] = value;
            cout << "Enqueued at the front: " << value << " successfully." << endl;
        }
    }

    void enqueueRear(int value) {
        if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
            cout << "Deque is full. Cannot enqueue at the rear." << endl;
        }
        else {
            if (front == -1) {
                front = rear = 0;
            }
            else if (rear == MAX_SIZE - 1) {
                rear = 0;
            }
            else {
                rear++;
            }
            arr[rear] = value;
            cout << "Enqueued at the rear: " << value << " successfully." << endl;
        }
    }

    void dequeueFront() {
        if (front == -1) {
            cout << "Deque is empty. Cannot dequeue from the front." << endl;
        } 
        else {
            cout << "Dequeued from the front: " << arr[front] << " successfully." << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else if (front == MAX_SIZE - 1) {
                front = 0;
            }
            else {
                front++;
            }
        }
    }

    void dequeueRear() {
        if (front == -1) {
            cout << "Deque is empty. Cannot dequeue from the rear." << endl;
        }
        else {
            cout << "Dequeued from the rear: " << arr[rear] << " successfully." << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else if (rear == 0) {
                rear = MAX_SIZE - 1;
            }
            else {
                rear--;
            }
        }
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty." << endl;
        } 
        else {
            cout << "Deque elements: ";
            int i = front;
            do {
                cout << arr[i] << " ";
                if (i == rear) {
                    break;
                }
                i = (i + 1) % MAX_SIZE;
            } while (i != front);
            cout << endl;
        }
    }
};

int main() {
    Deque deque;
    int choice, element;

    do {
        cout << "Menu:" << endl;
        cout << "1. Enqueue at the front" << endl;
        cout << "2. Enqueue at the rear" << endl;
        cout << "3. Dequeue from the front" << endl;
        cout << "4. Dequeue from the rear" << endl;
        cout << "5. Display" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue at the front: ";
                cin >> element;
                deque.enqueueFront(element);
                break;

            case 2:
                cout << "Enter element to enqueue at the rear: ";
                cin >> element;
                deque.enqueueRear(element);
                break;

            case 3:
                deque.dequeueFront();
                break;

            case 4:
                deque.dequeueRear();
                break;

            case 5:
                deque.display();
                break;

            case 6:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}