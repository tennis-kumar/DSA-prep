def merge_sorted_lists(a,b):
    return sorted(a+b)

print(merge_sorted_lists([1,2,3],[4,5,6])) # [1, 2, 3, 4, 5, 6]
print(merge_sorted_lists([1,3,5],[2,4,6])) # [1, 2, 3, 4, 5, 6]