#include <iostream>
using namespace std;



void display(int arr[], int n){

    // Traversal
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"\n"; 
}


int indexInsertion(int arr[],int size, int element, int capacity, int index){
    if(size>=capacity){
        cout<<"array is full"<<endl;
        cout<<"Insertion failed"<<endl;
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index] = element;
    size++;
    cout<<"Insertion successfull"<<endl;
    display(arr,size);
    return 1;
}

int main(){

    int arr[100] = {1,2,3,4,5};
    int size = 5, element = 24, index = 2;
    display(arr, size);
    indexInsertion(arr, size, element, 100, index);
    size++;



    return 0;
}