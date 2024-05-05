class Calculator {
    // Addition method
    public static <T extends Number> T add(T num1, T num2) {
        if (num1 instanceof Integer) {
            return (T) Integer.valueOf(num1.intValue() + num2.intValue());
        } else if (num1 instanceof Float) {
            return (T) Float.valueOf(num1.floatValue() + num2.floatValue());
        } else {
            throw new IllegalArgumentException("Unsupported number type");
        }
    }

    // Subtraction method
    public static <T extends Number> T sub(T num1, T num2) {
        if (num1 instanceof Integer) {
            return (T) Integer.valueOf(num1.intValue() - num2.intValue());
        } else if (num1 instanceof Float) {
            return (T) Float.valueOf(num1.floatValue() - num2.floatValue());
        } else {
            throw new IllegalArgumentException("Unsupported number type");
        }
    }

    // Multiplication method
    public static <T extends Number> T multi(T num1, T num2) {
        if (num1 instanceof Integer) {
            return (T) Integer.valueOf(num1.intValue() * num2.intValue());
        } else if (num1 instanceof Float) {
            return (T) Float.valueOf(num1.floatValue() * num2.floatValue());
        } else {
            throw new IllegalArgumentException("Unsupported number type");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Integer calculation
        int intResultAdd = Calculator.add(5, 3);
        int intResultSub = Calculator.sub(10, 4);
        int intResultMulti = Calculator.multi(2, 6);
        System.out.println("Integer Addition: " + intResultAdd);
        System.out.println("Integer Subtraction: " + intResultSub);
        System.out.println("Integer Multiplication: " + intResultMulti);

        // Float calculation
        float floatResultAdd = Calculator.add(5.5f, 3.3f);
        float floatResultSub = Calculator.sub(10.5f, 4.2f);
        float floatResultMulti = Calculator.multi(2.5f, 6.2f);
        System.out.println("Float Addition: " + floatResultAdd);
        System.out.println("Float Subtraction: " + floatResultSub);
        System.out.println("Float Multiplication: " + floatResultMulti);
    }
}
