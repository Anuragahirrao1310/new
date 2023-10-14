class Student:
    def __init__(self, name, student_id, major):
        self.name = name
        self.student_id = student_id
        self.major = major

class StudentDatabase:
    def __init__(self):
        self.students = []

    def add_student(self, student):
        self.students.append(student)

    def display_students(self):
        for student in self.students:
            print("\nStudent Information:")
            print(f"Student Name: {student.name}")
            print(f"Student ID: {student.student_id}")
            print(f"Major: {student.major}")
