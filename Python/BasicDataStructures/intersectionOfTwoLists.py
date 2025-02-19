def intersection(lst1,lst2):
    return list(set(lst1) & set(lst2))
print(intersection([1,2,3,4,5],[4,5,6,7,8])) # [4, 5]