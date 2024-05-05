import java.util.Random;

class RandomNumberGenerator implements Runnable {
    private Random random = new Random();
    
    @Override
    public void run() {
        try {
            while (true) {
                int randomNumber = random.nextInt(100);
                System.out.println("Generated Number: " + randomNumber);
                if (randomNumber % 2 == 0) {
                    Thread squareThread = new Thread(new SquareCalculator(randomNumber));
                    squareThread.start();
                } else {
                    Thread cubeThread = new Thread(new CubeCalculator(randomNumber));
                    cubeThread.start();
                }
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class SquareCalculator implements Runnable {
    private int number;
    
    public SquareCalculator(int number) {
        this.number = number;
    }
    
    @Override
    public void run() {
        int square = number * number;
        System.out.println("Square of " + number + ": " + square);
    }
}

class CubeCalculator implements Runnable {
    private int number;
    
    public CubeCalculator(int number) {
        this.number = number;
    }
    
    @Override
    public void run() {
        int cube = number * number * number;
        System.out.println("Cube of " + number + ": " + cube);
    }
}

public class Main {
    public static void main(String[] args) {
        Thread randomThread = new Thread(new RandomNumberGenerator());
        randomThread.start();
    }
}
