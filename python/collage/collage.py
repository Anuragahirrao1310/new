from student import Student, StudentDatabase
from teacher import Teacher, TeacherDatabase

def main():
    print("College Information")
    print("===================")

    # Create a StudentDatabase and add student records
    student_db = StudentDatabase()
    student_db.add_student(Student("anurag", "22231027", "Computer Science"))
    student_db.add_student(Student("madhur", "22231032", "Biology"))

    # Create a TeacherDatabase and add teacher records
    teacher_db = TeacherDatabase()
    teacher_db.add_teacher(Teacher("Prof. Smith", "T9876", "Mathematics"))
    teacher_db.add_teacher(Teacher("Dr. Johnson", "T5432", "History"))

    # Display student and teacher information
    student_db.display_students()
    teacher_db.display_teachers()

if __name__ == "__main__":
    main()
