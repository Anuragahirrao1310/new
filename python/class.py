class Student:
    def input(self, name, grade):
        self.name = name
        self.grade = grade

student = Student("John Doe", "A")

def display_info(student):
    print(f"Name: {student.name}")
    print(f"Grade: {student.grade}")

display_info(student)
