package program;

import java.util.*;
import java.text.DecimalFormat;

public class CornerPointCoords {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Please enter the radius of your pentagon's bounding circle : ");
        double radius = input.nextDouble();
        double x, y;
        for (double i = 0; i < 5; i++) {
            double angle = ((360.0 / 5.0) * i);
            x = (radius * Math.sin(Math.toRadians(angle)));
            y = (radius * Math.cos(Math.toRadians(angle)));
            DecimalFormat dec = new DecimalFormat("#0.00");
            System.out.println("Point " + (i + 1) + "'s positions is (" + dec.format(x) + ", " + dec.format(y) + ")");
        }
    }
}
