package tk.faunsce.java;

import java.util.*;

public class points_calc {
    public static void main(String[] args) {
        double p1a = 0, p1b = 0, p2a = 0, p2b = 0, p3a = 0, p3b = 0;
        double lowestDistance = Double.POSITIVE_INFINITY;
        double scale = Math.pow(10, 3);
        int size = (int)(Math.random() * (50 - 3 + 1)) + 3; // RNG for Size between 3 and 50
        double[][] points = new double[size][3];
        for (int i = 0; i < size; i++) { // Populate with random numbers
            for (int j = 0; j < 3; j++) {
                points[i][j] = Math.round( ((Math.random() * (10 - 0 + 1) ) + 0) * scale) / scale; // RNG for Size between 0 and 10
            }
        }
        for (int i = 0; i < size; i++) { // Calculate the lowest distance between any two Vector3's
            for (int j = i + 1; j < size - 1; j++) {
                double dist = (Math.sqrt(
                        Math.abs(Math.pow((points[i][0] - points[j + 1][0]), 2)) +
                        Math.abs(Math.pow((points[i][1] - points[j + 1][1]), 2)) +
                        Math.abs(Math.pow((points[i][2] - points[j + 1][2]), 2))
                ));
                if (dist < lowestDistance) {
                    lowestDistance = dist;
                    p1a = points[i][0];
                    p1b = points[j + 1][0];
                    p2a = points[i][1];
                    p2b = points[j + 1][1];
                    p3a = points[i][2];
                    p3b = points[j + 1][2];
                }
            }
        }
        System.out.println("The smallest distance was " + Math.round( lowestDistance * scale) / scale + " between (" + p1a + ", " + p2a + ", " + p3a + ") and (" + p1b + ", " + p2b + ", " + p3b + ")");
    }
}
