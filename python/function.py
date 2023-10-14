import datetime
import platform

def max_of_two(x, y):
    if x > y:
        return x
    return y

def max_of_three(x, y, z):
    return max_of_two(x, max_of_two(y, z))

def multiply_list(numbers):
    result = 1
    for num in numbers:
        result *= num
    return result

def even_numbers_between_range(start, end):
    even_numbers = [num for num in range(start, end+1) if num % 2 == 0]
    return even_numbers

def display_datetime_and_version():
    current_datetime = datetime.datetime.now()
    python_version = platform.python_version()
    return current_datetime, python_version

# Test the max_of_three function
print(max_of_three(3, 6, -5))

# Test the multiply_list function
numbers_to_multiply = [2, 3, 4]
print(multiply_list(numbers_to_multiply))

# Test the even_numbers_between_range function
even_numbers = even_numbers_between_range(19, 88)
print(even_numbers)

# Test the display_datetime_and_version function
current_datetime, python_version = display_datetime_and_version()
print("Current Date and Time:", current_datetime)
print("Python Version:", python_version)
