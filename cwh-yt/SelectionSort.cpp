#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int n){
    for (int i=0;i<n-1;i++){
        int min_idx = i;

        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min_idx])min_idx = j;
        }

        // Swap the found minimum element with the i-th element
        // int temp = arr[i];
        // arr[i] = arr[min_idx];
        // arr[min_idx] = temp;
        swap(arr[i], arr[min_idx]);
        
    }
}

void selSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min_idx = i;

        // Find the minimum element in unsorted portion of the array
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min_idx])min_idx = j;
        }

        // Swap only if the current element is not the minimum element
        if(min_idx!=i){
            // int temp = arr[i];
            // arr[i] = arr[min_idx];
            // arr[min_idx] = temp;
            swap(arr[i], arr[min_idx]);
        }
    }
    
}


int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted Array: ";
    printArray(arr, n);
    // selectionSort(arr, n);
    selSort(arr, n);
    cout<<"Sorted Array: ";
    printArray(arr, n);
    return 0;
}