#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    struct Node {
        int data;
        int priority;

        bool operator<=(const Node& other) const {
            return priority <= other.priority;
        }
    };

    vector<Node> queue;

public:
    void enqueue(int data, int priority) {
        Node newNode{data, priority};
        int i = 0;
        while (i < queue.size() && newNode <= queue[i]) {
            i++;
        }
        queue.insert(queue.begin() + i, newNode);
    }

    void dequeue() {
        if (!queue.empty()) {
            queue.erase(queue.begin());
        }
    }

    void display() {
        for (const auto& node : queue) {
            cout << "Data: " << node.data << " Priority: " << node.priority << endl;
        }
    }
};

int main() {
    PriorityQueue priorityQueue;

    int choice;
    do {
        cout << "1. Enqueue  2. Dequeue  3. Display  4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data, priority;
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter priority: ";
                cin >> priority;
                priorityQueue.enqueue(data, priority);
                break;
            }
            case 2:
                priorityQueue.dequeue();
                break;
            case 3:
                priorityQueue.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
