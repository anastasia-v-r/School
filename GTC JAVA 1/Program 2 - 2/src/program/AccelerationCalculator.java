package program;

import java.util.*;

public class AccelerationCalculator {
    public static void main(String []args)
    {
        float v0, v1, time, avg;

        Scanner input = new Scanner(System.in);

        System.out.println("Please enter the starting velocity: ");
        v0 = input.nextFloat();
        System.out.println("Please enter the ending velocity: ");
        v1 = input.nextFloat();
        System.out.println("Please enter the total time span in seconds: ");
        time = input.nextFloat();

        avg = (v1 - v0) / time;

        System.out.println("Average acceleration is: " + avg);
    }
}
