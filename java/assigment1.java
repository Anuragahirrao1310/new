import java.util.Scanner;

public class assigment1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first integer: ");
        int num1 = scanner.nextInt();

        System.out.print("Enter the second integer: ");
        int num2 = scanner.nextInt();

        System.out.print("Enter the third integer: ");
        int num3 = scanner.nextInt();

        System.out.print("Enter the fourth integer: ");
        int num4 = scanner.nextInt();

        if (num1 == num2 && num2 == num3 && num3 == num4) {
            System.out.println(" All integer are Equal");
        } else {
            System.out.println("all integer are Not Equal");
        }
        
        scanner.close();
    }
}