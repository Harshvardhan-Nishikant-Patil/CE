#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class JobQueue {
private:
    Node* front;
    Node* rear;
public:
    JobQueue() : front(nullptr), rear(nullptr) {}

    void addJob(int job);
    void displayJobs();
    void deleteJob();
};

void JobQueue::addJob(int job) {
    Node* newNode = new Node;
    newNode->data = job;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Job added successfully.\n";
}

void JobQueue::displayJobs() {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* current = front;
    cout << "Jobs in the queue: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void JobQueue::deleteJob() {
    if (front == nullptr) {
        cout << "Queue is empty. No job to delete.\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    cout << "Job deleted: " << temp->data << endl;
    delete temp;
}

int main() {
    JobQueue jobQueue;

    int choice, job;

    do {
        cout << "1. Add Job\n";
        cout << "2. Display Jobs\n";
        cout << "3. Delete Job\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job number: ";
                cin >> job;
                jobQueue.addJob(job);
                break;
            case 2:
                jobQueue.displayJobs();
                break;
            case 3:
                jobQueue.deleteJob();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
