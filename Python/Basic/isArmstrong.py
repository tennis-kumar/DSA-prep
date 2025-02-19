def is_armstrong(n):
    return n == sum([int(i) ** len(str(n)) for i in str(n)])

print(is_armstrong(153))  # True
print(is_armstrong(370))  # True
print(is_armstrong(9474)) # True
print(is_armstrong(9475)) # False