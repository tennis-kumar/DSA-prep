#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high, count;
    count = 0, low = 0, high = size-1;

    // start searching until low <= high
    while (low <= high)
    {
        count++;
        mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // Unsorted array for linear Search
    // int arr[] = {1,2,5,9,52,3,55,555,66,88,99,22,11,9,7};

    // Sorted array for Binary Search
    int arr[] = {1, 2, 3, 4, 5, 66, 77, 88, 99, 111, 222, 333};

    // Get the total size of the array in bytes
    int sizeInBytes = sizeof(arr);
    // Get the size of one element in the array
    int elementSize = sizeof(arr[0]);
    // Calculate the number of elements in the array
    int length = sizeInBytes / elementSize;

    int element = 77;

    // int searchIndex = linearSearch(arr,length,element);
    int searchIndex = binarySearch(arr, length, element);

    if (searchIndex == -1)
    {
        cout << "Element not found!!!" << endl;
    }
    else
    {
        cout << "The element " << element << " was found at index " << searchIndex << endl;
    }

    return 0;
}