import java.util.Scanner;

interface StudentInterface {
    void enterDetails();
    void displayDetails();
}

class Student implements StudentInterface {
    private String name;
    private int rollNo;

    public void enterDetails() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter name: ");
        name = scanner.nextLine();
        System.out.print("Enter roll number: ");
        rollNo = scanner.nextInt();
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Roll No: " + rollNo);
    }
}

public class interfaceST {
    public static void main(String[] args) {
        StudentInterface student = new Student();
        student.enterDetails();
        System.out.println("\nStudent Details:");
        student.displayDetails();
    }
}
