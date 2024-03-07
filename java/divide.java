 import java.util.Scanner;

public class divide{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        int b=0;


        try{
            System.out.println(num /b);
        }
         
        catch ( ArithmeticException e){
            System.out.println(" Divided by zero operation cannot possible");
        }

    }

}
