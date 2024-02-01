import java.util.Scanner;

class Student {
    String name;
    String city;
    int age;

    void addData() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter name: ");
        name = scanner.nextLine();

        System.out.print("Enter city: ");
        city = scanner.nextLine();

        System.out.print("Enter age: ");
        age = scanner.nextInt();
    }

    void printData() {
        System.out.println("Name: " + name);
        System.out.println("City: " + city);
        System.out.println("Age: " + age);
    }
}

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student();
        Student s2 = new Student();

        System.out.println("Enter details for Student 1:");
        s1.addData();

        System.out.println("\nEnter details for Student 2:");
        s2.addData();

        System.out.println("\nDetails for Student 1:");
        s1.printData();

        System.out.println("\nDetails for Student 2:");
        s2.printData();
    }
}
