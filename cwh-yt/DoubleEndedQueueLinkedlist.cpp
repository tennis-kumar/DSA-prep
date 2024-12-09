#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DEQueue {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DEQueue() : head(nullptr), tail(nullptr) {}

    // Insert at the front of the deque
    void insertAtFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // If deque is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the rear of the deque
    void insertAtRear(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) { // If deque is empty
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete from the front of the deque
    void deleteFromFront() {
        if (head == nullptr) { // If deque is empty
            cout << "Deque Underflow: Cannot delete from front." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) { // If deque becomes empty after deletion
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
    }

    // Delete from the rear of the deque
    void deleteFromRear() {
        if (tail == nullptr) { // If deque is empty
            cout << "Deque Underflow: Cannot delete from rear." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail == nullptr) { // If deque becomes empty after deletion
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        delete temp;
    }

    // Display the deque from front to rear
    void display() {
        if (head == nullptr) {
            cout << "Deque is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DEQueue deque;

    deque.insertAtFront(10);
    deque.insertAtFront(20);
    deque.insertAtRear(30);
    deque.insertAtRear(40);

    cout << "Deque after insertions: ";
    deque.display();

    deque.deleteFromFront();
    cout << "Deque after deleting from front: ";
    deque.display();

    deque.deleteFromRear();
    cout << "Deque after deleting from rear: ";
    deque.display();

    deque.deleteFromFront();
    deque.deleteFromFront();
    cout << "Deque after deleting all elements: ";
    deque.display();

    return 0;
}
