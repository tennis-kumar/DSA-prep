#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; // Print each element in the array
    }
    cout << endl; // Move to the next line after printing the array
}

// Function to perform partitioning in the QuickSort algorithm
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low + 1;      // Initialize 'i' to start from the next element after pivot
    int j = high;         // Initialize 'j' to start from the last element

    // Loop to partition the array based on the pivot
    do
    {
        // Increment 'i' until an element greater than the pivot is found
        while (arr[i] <= pivot)
        {
            i++;
        }

        // Decrement 'j' until an element smaller than or equal to the pivot is found
        while (arr[j] > pivot)
        {
            j--;
        }

        // If 'i' is still less than 'j', swap the elements at 'i' and 'j'
        if (i < j)
            swap(arr[i], arr[j]);
    } while (i < j);

    // Swap the pivot element with the element at index 'j'
    swap(arr[low], arr[j]);

    // Return the partition index where the pivot element is placed
    return j;
}

// Function to perform QuickSort on the array
void quickSort(int arr[], int low, int high)
{
    if (low < high) // Check if the range has more than one element
    {
        // Partition the array and get the pivot index
        int partitionIndex = partition(arr, low, high);

        // Recursively sort the left subarray (elements less than pivot)
        quickSort(arr, low, partitionIndex - 1);

        // Recursively sort the right subarray (elements greater than pivot)
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    // Initialize an array of integers
    int arr[] = {85, 10, 56, 1024, 23, 10, 44, 20, 30, 44, 24, 3};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Print the array before sorting
    cout << "Array Before Sorting: " << endl;
    printArray(arr, n);

    // Perform QuickSort on the entire array
    quickSort(arr, 0, n - 1);

    // Print the array after sorting
    cout << "Array After Sorting: " << endl;
    printArray(arr, n);

    return 0; // End of the program
}
