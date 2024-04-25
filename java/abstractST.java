import java.util.Scanner;

abstract class Student {
    protected String name;
    protected int rollNo;

    abstract void enterDetails();
    abstract void displayDetails();
}

class ConcreteStudent extends Student {
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

public class abstractST {
    public static void main(String[] args) {
        Student student = new ConcreteStudent();
        student.enterDetails();
        System.out.println("\nStudent Details:");
        student.displayDetails();
    }
}
