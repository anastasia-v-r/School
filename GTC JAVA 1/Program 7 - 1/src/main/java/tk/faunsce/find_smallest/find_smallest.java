package tk.faunsce.find_smallest;

import java.lang.reflect.Array;
import java.util.Scanner;

public class find_smallest {
    public static void main(String[] args) {
        double[] doubleArray = new double[10];
        Scanner input = new Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            double temp = 0.0;
            do {
                System.out.println("Please enter a positive floating point number");
                temp = input.nextDouble();
                if (temp < 0.0)
                    System.out.println(temp + " is less than 0.0");
                else if (temp == 0.0)
                    System.out.println(temp + " is 0.0");
            } while (temp < 0.0);
            doubleArray[i] = temp;
        }
        System.out.println(min(doubleArray));
    }

    public static double min(double[] array) {
        double lowest = array[0];
        for (double element : array) {
            if (element < lowest) {
                System.out.println(element + " is lower than " + lowest);
                lowest = element;
            }
        }
        return lowest;
    }
}
