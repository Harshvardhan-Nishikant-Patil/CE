#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}

    int size() const {
        int count = 0;
        const Node* temp = this;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void display() const {
        const Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    LinkedList intersection(const LinkedList& otherList) const {
        LinkedList result;
        unordered_set<int> set1;

        const Node* temp1 = head;
        while (temp1 != nullptr) {
            set1.insert(temp1->data);
            temp1 = temp1->next;
        }

        const Node* temp2 = otherList.head;
        while (temp2 != nullptr) {
            if (set1.find(temp2->data) != set1.end()) {
                result.insert(temp2->data);
            }
            temp2 = temp2->next;
        }

        return result;
    }

    LinkedList unionSet(const LinkedList& otherList) const {
        LinkedList result;
        unordered_set<int> resultSet;

        const Node* temp1 = head;
        while (temp1 != nullptr) {
            resultSet.insert(temp1->data);
            temp1 = temp1->next;
        }

        const Node* temp2 = otherList.head;
        while (temp2 != nullptr) {
            resultSet.insert(temp2->data);
            temp2 = temp2->next;
        }

        for (int val : resultSet) {
            result.insert(val);
        }

        return result;
    }

    int size() const {
        int count = 0;
        const Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    LinkedList vanilla, butterscotch;

    int n, val;

    cout << "Enter the number of students who like vanilla: ";
    cin >> n;

    cout << "Enter the student numbers for vanilla: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        vanilla.insert(val);
    }

    cout << "Enter the number of students who like butterscotch: ";
    cin >> n;

    cout << "Enter the student numbers for butterscotch: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        butterscotch.insert(val);
    }

    // a) Set of students who like both vanilla and butterscotch.
    LinkedList intersectionSet = vanilla.intersection(butterscotch);
    cout << "Students who like both vanilla and butterscotch: ";
    intersectionSet.display();

    // b) Set of students who like either vanilla or butterscotch or not both.
    LinkedList unionSet = vanilla.unionSet(butterscotch);
    cout << "Students who like either vanilla or butterscotch or not both: ";
    unionSet.display();

    // c) Number of students who like neither vanilla nor butterscotch.
    int totalStudents = unionSet.size();
    cout << "Number of students who like neither vanilla nor butterscotch: " << (totalStudents - intersectionSet.size()) << endl;

    return 0;
}
 