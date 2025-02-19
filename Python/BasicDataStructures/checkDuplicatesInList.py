def check_duplicates(lst):
    return len(lst) != len(set(lst))

print(check_duplicates([1,2,3,4,5])) # False
print(check_duplicates([1,2,3,4,1])) # True
print(check_duplicates([1,1,1,1,1])) # True