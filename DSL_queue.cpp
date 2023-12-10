#include <iostream>

using namespace std;

class Queue
{
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    void enqueue(int value)
    {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            arr[++rear] = value;
            cout << "Enqueued " << value << " successfully." << endl;
        }
    }

    void dequeue()
    {
        if (front == -1) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            cout << "Dequeued " << arr[front++] << " successfully." << endl;
            if (front > rear) {
                front = rear = -1;
            }
        }
    }

    void display()
    {
        if (front == -1) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue queue;
    int choice, element;

    do {
        cout << "Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element to enqueue: ";
            cin >> element;
            queue.enqueue(element);
            break;

        case 2:
            queue.dequeue();
            break;

        case 3:
            queue.display();
            break;

        case 4:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}