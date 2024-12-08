#include <iostream>
using namespace std;

class Queue
{
    // Initialize front and rear
    int rear, front;
    int size;
    int *arr;

public:
    // Constructor
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
    {
        cout << "Queue is Full!" << endl;
    }
    // Insert First Element
    else if (front == -1)
    {
        front = rear = 0;
        arr[front] = value;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
    else
    {
        rear++;
        arr[rear] = value;
    }
}

int Queue::deQueue()
{

    if (front == -1)
    {
        cout << "Queue is Empty!" << endl;
        return INT_MIN;
    }
    int data = arr[front];
    arr[front] = -1;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}


// Funciton to Display elements of Circular Queue

void Queue::displayQueue(){
    if (front == -1)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    cout<<"ELements in ciruclar Queue are: "<<endl;
    if(rear >=front){
        for (int i = front; i <=rear; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    else {
        for(int i=front; i<size;i++){
            cout<<arr[i]<<" ";
        }

        for(int i=0;i<rear;i++){
            cout<<arr[i]<<" ";
        }
    }

    cout<<endl;
    
}

int main()
{

    Queue q(5);

    q.displayQueue();

    q.enQueue(2);
    q.enQueue(22);
    q.enQueue(44);
    q.enQueue(24);
    q.enQueue(46);
    q.enQueue(66);

    q.displayQueue();

    cout<<endl<<"Deleted Value = "<<q.deQueue()<<endl;
    q.displayQueue();
    cout<<endl<<"Deleted Value = "<<q.deQueue()<<endl;

    q.enQueue(20);
    q.enQueue(10);

    q.displayQueue();

    return 0;
}