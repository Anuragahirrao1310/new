import java.util.Scanner;

class Vehicle {
    String registrationNumber;
    String color;
    String type;

    public Vehicle(String registrationNumber, String color, String type) {
        this.registrationNumber = registrationNumber;
        this.color = color;
        this.type = type;
    }
}

class Car extends Vehicle {
    String make;

    public Car(String registrationNumber, String color, String type, String make) {
        super(registrationNumber, color, type);
        this.make = make;
    }
}

class Truck extends Vehicle {
    int CC;

    public Truck(String registrationNumber, String color, String type, int CC) {
        super(registrationNumber, color, type);
        this.CC = CC;
    }
}

class Motorcycle extends Vehicle {
    String fuelType;

    public Motorcycle(String registrationNumber, String color, String type, String fuelType) {
        super(registrationNumber, color, type);
        this.fuelType = fuelType;
    }
}

public class VehicleDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for Car
        System.out.println("Enter Car details:");
        System.out.print("Registration Number: ");
        String carRegNumber = scanner.next();
        System.out.print("Color: ");
        String carColor = scanner.next();
        System.out.print("Type: ");
        String carType = scanner.next();
        System.out.print("Make: ");
        String carMake = scanner.next();

        Car car = new Car(carRegNumber, carColor, carType, carMake);

        System.out.println("\nEnter Truck details:");
        System.out.print("Registration Number: ");
        String truckRegNumber = scanner.next();
        System.out.print("Color: ");
        String truckColor = scanner.next();
        System.out.print("Type: ");
        String truckType = scanner.next();
        System.out.print("CC: ");
        int truckCC = scanner.nextInt();

        Truck truck = new Truck(truckRegNumber, truckColor, truckType, truckCC);

        System.out.println("\nEnter Motorcycle details:");
        System.out.print("Registration Number: ");
        String motorcycleRegNumber = scanner.next();
        System.out.print("Color: ");
        String motorcycleColor = scanner.next();
        System.out.print("Type: ");
        String motorcycleType = scanner.next();
        System.out.print("Fuel Type: ");
        String motorcycleFuelType = scanner.next();

        Motorcycle motorcycle = new Motorcycle(motorcycleRegNumber, motorcycleColor, motorcycleType, motorcycleFuelType);

        System.out.println("\nCar Details:");
        System.out.println("Registration Number: " + car.registrationNumber);
        System.out.println("Color: " + car.color);
        System.out.println("Type: " + car.type);
        System.out.println("Make: " + car.make);

        System.out.println("\nTruck Details:");
        System.out.println("Registration Number: " + truck.registrationNumber);
        System.out.println("Color: " + truck.color);
        System.out.println("Type: " + truck.type);
        System.out.println("CC: " + truck.CC);

        System.out.println("\nMotorcycle Details:");
        System.out.println("Registration Number: " + motorcycle.registrationNumber);
        System.out.println("Color: " + motorcycle.color);
        System.out.println("Type: " + motorcycle.type);
        System.out.println("Fuel Type: " + motorcycle.fuelType);

        scanner.close();
    }
}
