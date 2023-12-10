#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
class Linkedlist {
	Node* head;

public:
	Linkedlist() { head = NULL; }
	void insertNode(int);

	void printList();

};
void Linkedlist::insertNode(int data)
{
	Node* newNode = new Node(data);

	if (head == NULL) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}
void Linkedlist::printList()
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}


int main()
{   int element;

    int n;
    cout<<"Enter total number of elements: ";
    cin>>n;



	Linkedlist list;
	for (int i=0;i<n;i++){
		cout<<"enter element: ";
		cin>>element;
		list.insertNode(element);

	}

	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;
	return 0;
}
