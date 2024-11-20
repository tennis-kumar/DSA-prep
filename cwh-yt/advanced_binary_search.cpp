#include <iostream>
using namespace std;

// Struct to hold both index and count
struct SearchResult {
    int index;
    int iterations;
};

SearchResult binarySearch(int arr[], int size, int element) {
    int low = 0, high = size - 1, count = 0;

    while (low <= high) {
        int mid = (high + low) / 2;
        count++;

        if (arr[mid] == element) {
            return {mid, count};
        }
        if (arr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return {-1, count}; // Return -1 if not found, along with iteration count
}

int main() {
    // Sorted array for Binary Search
    int arr[] = {1, 2, 3, 4, 5, 66, 77, 88, 99, 111, 222, 333};

    // Get the total size of the array in bytes
    int sizeInBytes = sizeof(arr);
    // Get the size of one element in the array
    int elementSize = sizeof(arr[0]);
    // Calculate the number of elements in the array
    int length = sizeInBytes / elementSize;

    int element = 222;

    // Call binarySearch
    SearchResult result = binarySearch(arr, length, element);

    if (result.index == -1) {
        cout << "Element not found!!!" << endl;
    } else {
        cout << "The element " << element << " was found at index " << result.index << endl;
        cout << "Number of iterations: " << result.iterations << endl;
    }

    return 0;
}
