#include <stdio.h>

void printArray(int* a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int n){
    int temp;
    for (int i = 0; i < n-1; i++) // Number of passes
    {
        for (int j = 0; j < n-1-i; j++) // Comparisons in each pass
        {
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        
    }
    
}

int main(){
    int a[] = {3, 5, 1, 4, 2};
    int n = 5;
    printf("Unsorted array: ");
    printArray(a, n);
    bubbleSort(a, n);
    printf("Sorted array: ");
    printArray(a, n);
    return 0;
}