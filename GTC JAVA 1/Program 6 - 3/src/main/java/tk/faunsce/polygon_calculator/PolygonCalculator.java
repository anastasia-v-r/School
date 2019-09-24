package tk.faunsce.polygon_calculator;

import org.graalvm.compiler.phases.graph.ScheduledNodeIterator;

import java.util.Scanner;

public class PolygonCalculator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Please enter the number of side of your regular polygon");
        int sides = input.nextInt();
        System.out.println("now enter the length of the sides");
        double length = input.nextDouble();
        System.out.println("The area is : [" + area(sides, length) + "]");
    }
    public  static double area(int n, double side) {
        return (n * side * side) / (4 * Math.tan(Math.PI / n));
    }
}
