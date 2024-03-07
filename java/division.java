import java.util.Scanner;

public class division{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        double number = scanner.nextDouble();

        double result = number / 0;

        System.out.println("Result of dividing by 1: " + result);
    }
}
