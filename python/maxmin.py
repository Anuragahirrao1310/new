min = int (input("enter the lower limits"))
max = int (input("enter the upper limits"))
count=0
for i in range(min , max):
    if (i%5==0 and i%9==0):
        print(i,"is divisible by 5 and multiple of 9")
        count = count +1
    else:
        continue
    if (count == 0):
        print("No numbers are divisible by 5 and multiple of 9")