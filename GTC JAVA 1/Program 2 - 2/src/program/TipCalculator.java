package program;

import java.util.*;

public class TipCalculator {
    public static void main(String []args)
    {
        float gratuity, subTotal, finalTotal;

        Scanner input = new Scanner(System.in);
        System.out.println("Please Input the subtotal: ");
        subTotal = input.nextFloat();
        System.out.println("Please enter the gratiuty percentage (Input: 15 -> 15%): ");
        gratuity = input.nextFloat();
        gratuity = subTotal * (gratuity / 100);
        finalTotal = subTotal + gratuity;
        System.out.println("Gratuity is $" + gratuity + ", and your final total is $" + finalTotal);
    }
}
