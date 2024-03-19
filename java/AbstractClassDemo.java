abstract class Shape {

     abstract void drawShape();
    
    void draw() {
        System.out.println("Parent Abstract Class...");
    }
}


class Triangle extends Shape {

   void drawShape() {
        System.out.println("This is triangle");
    }
}


class Square extends Shape {

    void drawShape() {
        System.out.println("This is square");
    }
}



public class AbstractClassDemo {
    public static void main(String[] args) {

        Triangle T = new Triangle();
        Square S = new Square();
    


        T.drawShape(); 
        S.drawShape();



    }
}