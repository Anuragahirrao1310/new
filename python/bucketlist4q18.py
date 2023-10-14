def is_palindrome(lst):
    # Compare the elements from the beginning and end of the list
    for i in range(len(lst) // 2):
        if lst[i] != lst[-i - 1]:
            return False
    return True

# Test cases
print(is_palindrome([1, 2, 3, 2, 1]))  # True   
print(is_palindrome([1, 2, 3, 4, 5]))  # False
print(is_palindrome(['a', 'b', 'c', 'b', 'a']))  # True
print(is_palindrome(['hello', 'world', 'hello']))  # False