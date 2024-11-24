#include <iostream>
using namespace std;

// Node 
struct Node {
    int data; //variable to store data
    Node* next; // pointer 

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// CircularLinkedList class
class CircularLinkedList {
private:
    Node* head; // Pointer for the head node

public:
    // Constructor with head ptr set as null
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Make it circular
        }
    }

    // Function to display the list
    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        // Find the node to delete
        do {
            if (current->data == value) {
                if (current == head && current->next == head) {
                    // Only one node in the list
                    delete current;
                    head = nullptr;
                    return;
                } else if (current == head) {
                    // Deleting the head node
                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    head = head->next;
                    temp->next = head;
                    delete current;
                    return;
                } else {
                    // Deleting any other node
                    previous->next = current->next; //pointer of the next node
                    delete current; //delete the current node
                    return;
                }
            }
            previous = current; // make the current node as the previous node
            current = current->next; // update the current to point to the next node
        } while (current != head);

        cout << "Value not found in the list!" << endl;
    }
};

int main() {
    CircularLinkedList list;
    cout << "Initial Circular Linked List: ";
    list.display();
    // Insert elements into the circular linked list
    list.insertEnd(10);
    cout << "Circular Linked List after insertion: ";
    list.display();
    list.insertEnd(20);
    cout << "Circular Linked List after insertion: ";
    list.display();
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Circular Linked List: ";
    list.display();

    // Delete an element
    cout << "Deleting 20..." << endl;
    list.deleteNode(20);

    cout << "Circular Linked List after deletion: ";
    list.display();

    return 0;
}
