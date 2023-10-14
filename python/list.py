hat_list = [1, 2, 3, 4, 5]
print("original list content :", hat_list)

a = int(input("enter the number to change no.2:"))
hat_list[1] = a
print("user changer in row no.2: \n",hat_list)
b = int(input("enter the number to change no.3:"))
hat_list[2] = b
print("user changer in row no.3: \n",hat_list)
c = int(input("enter the number to change no.4:"))
hat_list[3] = c
print("user changer in row no.4: \n",hat_list)
del hat_list[4]
print(" new length of list", len(hat_list))
print(hat_list)