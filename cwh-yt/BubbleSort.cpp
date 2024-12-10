#include <iostream>
#include <vector>
using namespace std;

// An Optimized version of Bubble Sort 
void bubbleSort(vector<int>& arr){
    int n = arr.size();

    // flag to detect if any swapping happens
    bool swapped;

    for(int i = 0; i<n; i++){
        swapped=false;

        // Last i elements are already sorted
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped)break;
    }
}

void printVector(const vector<int>& arr){
    for(int num:arr)
    cout<<" "<<num;
}

int main(){

    vector<int> arr = {64,32,25,12,22,10,98};

    bubbleSort(arr);
    cout<<" Sorted array: "<<endl;
    printVector(arr);

    return 0;
}