def insertion_sort(arr):
    for i in range(1, len(arr)): # start from second element
        key = arr[i] # the current element to be inserted
        j = i-1 # Index of the element to the left

        # Move elements of arr[0,...,I-1], that are greater than key to one position ahead of their current position
        while j >=0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key # Insert the key in its correct position
    return arr

arr = [64, 25, 12, 22, 11,55, 33, 44, 66, 77, 88, 99, 100]
print(insertion_sort(arr))
# Output: [11, 12, 22, 25, 33, 44, 55, 64, 66, 77, 88, 99, 100]