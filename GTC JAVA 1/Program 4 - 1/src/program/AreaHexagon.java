package program;

import java.util.*;

public class AreaHexagon {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Please enter the length of the side of the hexagon in cm: ");
        double hexSide = input.nextFloat();
        double hexArea = ((3 * Math.sqrt(3))/(2)) * (hexSide * hexSide);
        System.out.println("Hexagon Area : " + hexArea + "cm");
    }
}
