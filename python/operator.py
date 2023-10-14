a =int(input("enter the number"))
b = int(input ("enter the 2nd number"))
print("addition ;",a+b)
oper = input("Enter the type of operation you want to perform (+, -, *, /, %): ")

result = 0
if oper == "+":
    result = a+b 
elif oper == "-":
    result = a-b
elif oper == "*":
    result = a*b
elif oper == "/":
    result = a//b
elif oper == "%":
    result = a%b 
else:
    print("Invalid Input")
print("the Anuswer is :",result)
c =  int (input("enter the number"))
d =  int(input ("enter the 2nd number")) 
print("sum of two number;",c+d)
print("substraction of two number :",c-d)
print("miultply of two number :",c*d)
print("Division of two number :",c/d)
print("floor division of two number :",c//d)
print("exponential of two number :",c**d)
print("modules of two number :",c%d)