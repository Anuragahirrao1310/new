
import java.util.Random;
public class multithredding {
    public static void main(String[] args) {
        Thread t1 = new Thread(new RandomIntGenerator());
        t1.start();
}
}
class RandomIntGenerator implements Runnable{
    private int count = 0; 
    public void run(){
        while ( count < 5) {
        Random rand = new Random();
            int n = rand.nextInt(100);
            System.out.println("Random number: "+n);
            if(n%2==0){
                Thread t2 = new Thread(new Square(n));
                t2.start();
            }
            else{
                Thread t3 = new Thread(new Cube(n));
                t3.start();
            }
            try{
                Thread.sleep(1000);
            }
            catch(InterruptedException e){
                System.out.println(e);
            }
            count++;
        }
    }
    }

class Square implements Runnable{
    int n;
    Square(int n){
        this.n = n;
    }
    public void run(){
        System.out.println("Square of "+n+" is: "+n*n);
    }
}
class Cube implements Runnable{
    int n;
    Cube(int n){
        this.n = n;
    }
    public void run(){
        System.out.println("Cube of "+n+" is: "+n*n*n);
    }
}

