package program;

import java.util.*;

public class EnergyCalculator {
    public static void main(String[] args) {
        float water, iTemp, fTemp, energy;

        Scanner input = new Scanner(System.in);

        System.out.println("Please enter the initial temperature: ");
        iTemp = input.nextFloat();
        System.out.println("Please enter the final temperature: ");
        fTemp = input.nextFloat();
        System.out.println("Please enter the amount of water: ");
        water = input.nextFloat();

        energy = water * (fTemp - iTemp) * 4184;

        System.out.println("The total amount of energy needed to head " + water + "Kg of water is " + energy + "J.");
    }
}
