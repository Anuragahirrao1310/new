import java.util.Scanner;

class Student2 {
    private String name;
    private int rollNumber;

    public void getData() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("enter student name");
        name =scanner.nextLine();
         System.out.println("enter student roll no.");
        rollNumber =scanner.nextInt();
    }

    public void printData() {
        System.out.println("Name: " + name);
        System.out.println("Roll Number: " + rollNumber);
    }
}
    public class STtest {
    public static void main(String[] args) 
    {
        Student2 s1 = new Student2();
        Student2 s2 = new Student2();


        s1.getData();


        s2.getData();

        
        System.out.println("Data for s1:");
        s1.printData();

        System.out.println("\nData for s2:");
        s2.printData();
    }
}
    
