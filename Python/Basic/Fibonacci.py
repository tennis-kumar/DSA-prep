def fibonacci(n):
    a,b =0,1
    for _ in range(n): # loop skips when input is 0, _ is a placeholder
        a,b = b,a+b

    return a

print(fibonacci(0))  # 0
print(fibonacci(1))  # 1
print(fibonacci(2))  # 1
print(fibonacci(3))  # 2