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

/*
6.36 (Geometry: area of a regular polygon) A regular polygon is an n-sided
polygon in which all sides are of the same length and all angles have
the same degree (i.e., the polygon is both equilateral and equiangular). The
formula for computing the area of a regular polygon is
Area=n×s24×tan (πn)
Write a method that returns the area of a regular polygon using the
following header:
public static double area(int n, double side)

Write a main method that prompts the user to enter the number of sides and
the side of a regular polygon and displays its area. Here is a sample run:
Enter the number of sides: 5
Enter the side: 6.5
The area of the polygon is 72.69017017488385
 */