class student:
    def student_details(fname,lname):
        print("first name is:",fname)
        print("last name is:",lname)        
def __init__(self,fname,lname):
            self.fname=fname
            self.lname=lname


firstname=input(str("enter the first name:"))
lastname=input(str("enter the last name:"))            

m=student(firstname,lastname)
print("first name:",m.fname)
print("last name:",m.lname)

