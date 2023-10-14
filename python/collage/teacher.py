class Teacher:
    def __init__(self, name, employee_id, department):
        self.name = name
        self.employee_id = employee_id
        self.department = department

class TeacherDatabase:
    def __init__(self):
        self.teachers = []

    def add_teacher(self, teacher):
        self.teachers.append(teacher)

    def display_teachers(self):
        for teacher in self.teachers:
            print("\nTeacher Information:")
            print(f"Teacher Name: {teacher.name}")
            print(f"Employee ID: {teacher.employee_id}")
            print(f"Department: {teacher.department}")
