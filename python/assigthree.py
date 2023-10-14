#define string as anurag
name = input("enter the string name:")
name2 = input("enter the string name:")
name1 = input("enter the substring name:")
string = name 
string1 = name2
#we are copy string 
copy = string

# we are combine two string together
concatenated = string + string1

# we define another string as anu
substring = name1
#we check substring present in srting
is_substring = substring in string

#we reversed the last later of string
reversed_string = string[::-1]

#we measure the length pf string
length = len(string)

# Printing the results
print("Original string:", string)
print("Copied string:", copy)
print("Concatenated string:", concatenated)
print("Is substring 'anu' present?", is_substring)
print("Reversed string:", reversed_string)
print("Length of the string:", length)
#code by anurag ahirrao