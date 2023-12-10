    #include <iostream>
    #include <unordered_set>
    using namespace std;

    //creating node
    class Node {
    public:
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    //element insert
    void insert(Node*& head, int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    //elements in linked list
    void display(Node* head) {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int main() {

        Node* setA = nullptr;
        Node* setB = nullptr;


        insert(setA, 1); 
        insert(setA, 2); 
        insert(setB, 2); 
        insert(setB, 3); 

        //both vanilla and chocolate
        Node* bothLiked = nullptr;
        Node* tempA = setA;
        while (tempA != nullptr) {
            int studentA = tempA->data;
            Node* tempB = setB;
            while (tempB != nullptr) {
                if (studentA == tempB->data) {
                    insert(bothLiked, studentA);
                    break;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }

        //either vanilla or butterscotch or not both
        Node* eitherOr = nullptr;
        Node* tempA2 = setA;
        Node* tempB2 = setB;

        //students from set A who don't like both
        while (tempA2 != nullptr) {
            int studentA = tempA2->data;
            bool found = false;
            tempB2 = bothLiked;
            while (tempB2 != nullptr) {
                if (studentA == tempB2->data) {
                    found = true;
                    break;
                }
                tempB2 = tempB2->next;
            }
            if (!found) {
                insert(eitherOr, studentA);
            }
            tempA2 = tempA2->next;
        }

        // students from set B who don't like both
        tempB2 = setB;
        while (tempB2 != nullptr) {
            int studentB = tempB2->data;
            bool found = false;
            tempA2 = bothLiked;
            while (tempA2 != nullptr) {
                if (studentB == tempA2->data) {
                    found = true;
                    break;
                }
                tempA2 = tempA2->next;
            }
            if (!found) {
                insert(eitherOr, studentB);
            }
            tempB2 = tempB2->next;
        }

        //students who like neither vanilla nor butterscotch
        unordered_set<int> students;
        tempA2 = setA;
        while (tempA2 != nullptr) {
            students.insert(tempA2->data);
            tempA2 = tempA2->next;
        }
        tempB2 = setB;
        while (tempB2 != nullptr) {
            students.insert(tempB2->data);
            tempB2 = tempB2->next;
        }

        cout << "Set of students who like both vanilla and butterscotch: ";
        display(bothLiked);

        cout << "Set of students who like either vanilla or butterscotch or not both: ";
        display(eitherOr);

        cout << "Number of students who like neither vanilla nor butterscotch: " << (setA == nullptr && setB == nullptr ? 0 : students.size()) << endl;
        

        return 0;
    }
