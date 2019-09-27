package tk.faunsce.population_calculator;

import java.text.DecimalFormat;
import java.util.Scanner;

public class population_calculator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        DecimalFormat format = new DecimalFormat("0.00");
        System.out.println("What is the starting size of your population");
        int populationBase = input.nextInt();
        while (populationBase < 2) {
            System.out.println("Please enter an integer larger than 2");
            populationBase = input.nextInt();
        }
        System.out.println("Please enter your average daily population increase (.05 == %5)");
        double populationIncrease = input.nextDouble();
        while (populationIncrease < 0) {
            System.out.println("Please enter a non negative value");
            populationIncrease = input.nextDouble();
        }
        System.out.println("Please enter the number of days this will occur over");
        int days = input.nextInt();
        while (days < 1) {
            System.out.println("Please enter an integer above 0");
            days = input.nextInt();
        }
        double population = populationBase;
        for (int i = 0; i < days; i++) {
            System.out.println("Day [" + (i + 1) + "] Population [" + format.format(population) + "]");
            population += population * populationIncrease;
        }
    }
}
