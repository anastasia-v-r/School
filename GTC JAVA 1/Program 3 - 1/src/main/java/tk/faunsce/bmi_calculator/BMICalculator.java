package tk.faunsce.bmi_calculator;

import java.util.*;

public class BMICalculator {
    public static void main(String[] args) {
        double weight, feet, inches;
        Scanner input = new Scanner(System.in);

        System.out.println("Please enter your weight : ");
        weight = input.nextDouble();
        System.out.println("Please enter your height measurements feet amount : ");
        feet = input.nextDouble();
        System.out.println("Please enter your height measurement inches reamainder : ");
        inches = input.nextDouble();

        final	double	KILOGRAMS_PER_POUND	= 0.45359237;
        final	double	METERS_PER_INCH	= 0.0254;

        double	weightInKilograms =	weight * KILOGRAMS_PER_POUND;
        double	heightInMeters = ((feet * 12) + inches) * METERS_PER_INCH;
        double	bmi	= weightInKilograms / (heightInMeters	* heightInMeters);

        System.out.println("Your BMI is " + bmi);
        if (bmi < 18.5)
            System.out.println("Underweight");
        else if (bmi < 25)
            System.out.println("Normal");
        else if (bmi < 30)
            System.out.println("Overweight");
        else
            System.out.println("Obese");
    }
}
