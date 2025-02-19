def second_largest(arr):
    unique_arr = sorted((set(arr)),reverse=True) # remove duplicates and sort in decending order
    return unique_arr[1] if len(unique_arr) > 1 else None

print(second_largest([1,2,3,4,5])) # 4
print(second_largest([1,1,1,1,1])) # None