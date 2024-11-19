#include <iostream>
using namespace std;


void display(int arr[], int n){

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<endl; 
}

// fun for deleting element at given index
int deleteAtIndex(int arr[],int index, int size){ 

    if(index <0 || index >size){
        cout<<"Invalid index"<<endl;
        return -1;
    }
    

    for (int i = index; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    size-=1;
    cout<<"Deletion Successfull"<<endl<<"Updated array after deletion is :"<<endl;
    display(arr,size);
    

    return 1;

}

int main(){
    int arr[100] = {1,2,3,4,5,6,7};
    int size = 5, element = 24, index = 2, capacity = 100;
    cout<<"array before deletion"<<endl;
    display(arr,size);

    deleteAtIndex(arr,index,size);


    return 0;
}