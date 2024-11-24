#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
    Node *head;

public:
    // Constructor to initialize default values
    DoublyLinkedList() : head(nullptr) {}
    // Function to Insert a new node at the beginning of the list
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;    // Point newNode's next to current head
        newNode->prev = nullptr; // New Node has no previous node

        // If the list is not empty, update the previous head's prev pointer
        if (head != nullptr)
            head->prev = newNode;

        head = newNode;
    }

    // Function Insert a new node at the end of the list
    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        // If the list is empty, update the head to the new node
        if (!head)
        {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        // Update pointers to insert the new node
        temp->next = newNode; // Last node's next points to the new node
        newNode->prev = temp; // New node's prev points to the last node
    }

    // Function to Insert a new node at a specific position in the list
    void insertAtPosition(int value, int position)
    {
        if (position < 1)
        {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }

        Node *newNode = new Node();
        newNode->data = value;

        // Traverse to the node before the desired position
        Node *temp = head;
        for (int i = 1; i < position - 1 && temp; ++i)
        {
            temp = temp->next;
        }

        // If the position is out of range, print an error message
        if (!temp)
        {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        // Insert the new node at the desired position
        newNode->next = temp->next;
        newNode->prev = temp;
        // temp->next = newNode;

        // Check if there is a node after the insertion point
        if (temp->next != nullptr)
            temp->next->prev = newNode; // Update its `prev` pointer to the new node

        temp->next = newNode;
    }

    // Function to Delete the first node of the list
    void deleteFromBeginning()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head; // Save current head
        head = head->next; // update head to next node

        // If the list is not empty after deletion
        if (head)
            head->prev = nullptr; // Set the new head's prev pointer to nullptr
        delete temp;              // free memory of old head
    }

    // Function to Delete the last node of the list
    void deleteFromEnd()
    {
        if (!head)
        { // Check if list is empty
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next)
        { // Only one node in the list
            delete head;
            head = nullptr; // update head to nullptr after deletion
            return;
        }

        // Traverse to the last node
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        // Update the previous node's next pointer to nullptr
        temp->prev->next = nullptr;

        //  Delete the last node
        delete temp;
    }

    // Function to Delete a node at a specific position in the list
    void deleteFromPosition(int position)
    {
        if (position < 1)
        {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1)
        {
            deleteFromBeginning();
            return;
        }

        // Traverse to the node at the specified position
        Node *temp = head;
        for (int i = 1; i < position && temp; ++i)
        {
            temp = temp->next;
        }

        // Check if the position is valid
        if (!temp)
        {
            cout << "Position out of range." << endl;
            return;
        }

        // update next pointer of previous node, if it exists
        if (temp->prev)
            temp->prev->next = temp->next;

        // update prev pointer of next node, if it exists
        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
    }

    void displayForward()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << " END " << endl;
    }

    void displayReverse()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp->next)
        { // Traverse to the last node
            temp = temp->next;
        }

        cout << "Backward: ";
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "START" << endl;
    }
};

int main()
{
    DoublyLinkedList dll;

    // Inserting at the beginning
    cout << "Inserting 10, 20, 30 at the beginning of the list:" << endl;
    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtBeginning(30);
    dll.displayForward();
    dll.displayReverse();

    // Inserting at the end
    cout << "\nInserting 40, 50 at the end of the list:" << endl;
    dll.insertAtEnd(40);
    dll.insertAtEnd(50);
    dll.displayForward();
    dll.displayReverse();

    // Inserting at specific positions
    cout << "\nInserting 25 at position 3:" << endl;
    dll.insertAtPosition(25, 3);
    dll.displayForward();
    dll.displayReverse();

    cout << "\nInserting 5 at position 1:" << endl;
    dll.insertAtPosition(5, 1);
    dll.displayForward();
    dll.displayReverse();

    cout << "\nInserting 60 at position 10 (out of range):" << endl;
    dll.insertAtPosition(60, 10); // Invalid position
    dll.displayForward();
    dll.displayReverse();

    // Deleting from the beginning
    cout << "\nDeleting from the beginning:" << endl;
    dll.deleteFromBeginning();
    dll.displayForward();
    dll.displayReverse();

    // Deleting from the end
    cout << "\nDeleting from the end:" << endl;
    dll.deleteFromEnd();
    dll.displayForward();
    dll.displayReverse();

    // Deleting from specific positions
    cout << "\nDeleting node at position 3:" << endl;
    dll.deleteFromPosition(3);
    dll.displayForward();
    dll.displayReverse();

    cout << "\nDeleting node at position 1:" << endl;
    dll.deleteFromPosition(1);
    dll.displayForward();
    dll.displayReverse();

    cout << "\nDeleting node at position 10 (out of range):" << endl;
    dll.deleteFromPosition(10); // Invalid position
    dll.displayForward();
    dll.displayReverse();

    return 0;
}
