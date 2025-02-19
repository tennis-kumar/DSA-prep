def is_palindrome(s):
    return s == s[::-1]

print(is_palindrome('hello'))
print(is_palindrome('racecar'))