
def palindrome(n):
    return n == n[::-1]

print palindrome("123")
print palindrome("12321")
print palindrome("abcdedcba")
