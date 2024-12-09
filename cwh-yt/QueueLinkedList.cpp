#include <iostream>
using namespace std;

// Node representing a single node in the linked list
class Node{
public:
    int data;
    Node* next;

    // Constructor
    Node(int value){
        this->data = value;
        this->next = nullptr;
    }
};

class Queue {

    // Pointer to the front and rear of the linked list
    Node *front,*rear;

public:
    //Constructor
    Queue(){front=rear=nullptr;}

    bool isEmpty(){
        if(front==nullptr)return true;
        return false;
    }

    // Function to add an element to the queue
    void enqueue(int value){

        //Create a new node
        Node* new_node = new Node(value);

        if(this->isEmpty()){
            front=rear=new_node;
            return;
        }
        rear->next=new_node;
        rear=new_node;
    }

    void dequeue(){
        if(this->isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if(front == nullptr)rear=nullptr;

        // Deallocate memory of the old front node
        delete temp;
    }

    int getFront(){
        if (this->isEmpty()){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return front->data;
    }

    int getRear(){
        if(this->isEmpty()){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        return rear->data;
    }
};


int main(){

    Queue q;

    cout<<q.isEmpty()<<endl;

    q.enqueue(10);
    q.enqueue(20);

    cout<<"Queue Front: "<<q.getFront()<<endl;
    cout<<"Queue Rear: "<<q.getRear()<<endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(40);
    q.enqueue(30);
    q.enqueue(50);

    q.dequeue();

    cout<< "Queue Front: "<<q.getFront()<<endl;
    cout<<"Queue Rear: "<<q.getRear()<<endl;

    cout<<q.isEmpty()<<endl;

    return 0;
}