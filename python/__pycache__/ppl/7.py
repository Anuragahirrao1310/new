
import datetime
import sys

def find_max_of_three(num1, num2, num3):
    return max(num1, num2, num3)

def multiply_list(numbers):
    result = 1
    for number in numbers:
        result *= number
    return result

def even_numbers_between_19_and_88():
    even_nums = [num for num in range(19, 89) if num % 2 == 0]
    return even_nums

def display_date_time_and_python_version():
    current_date_time = datetime.datetime.now()
    python_version = sys.version
    return current_date_time, python_version

num1 = 42
num2 = 73
num3 = 28
max_value = find_max_of_three(num1, num2, num3)

number_list = [2, 4, 6, 8]
product = multiply_list(number_list)

even_nums_list = even_numbers_between_19_and_88()

current_date_time, python_version = display_date_time_and_python_version()

print("Max of three numbers:", max_value)
print("Product of numbers in the list:", product)
print("Even numbers between 19 and 88:", even_nums_list)
print("Current date and time:", current_date_time)
print("Python version:", python_version)
