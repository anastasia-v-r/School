package program;

import java.text.DecimalFormat;
import java.util.Scanner;

public class LoanComparison {
    public static void main(String[] args) {
        DecimalFormat per = new DecimalFormat("0.000%");
        DecimalFormat total = new DecimalFormat("$0,000.00");
        DecimalFormat month = new DecimalFormat("000.00");
        Scanner input = new Scanner(System.in);
        System.out.println("Please enter your principal loan amount.");
        int principal = input.nextInt();
        System.out.println("Please enter the period of the loan in years.");
        int years = input.nextInt();
        System.out.println("Interest Rate Monthly Payment Total Payment");
        for (float i = .05f; i <= .081f; i += .00125f) {
            float A = principal;
            for (int j = 0; j < years; j++) {
                for (int k = 0; k < 12; k++) {
                    A += A * i;
                }
            }
            System.out.println(per.format(i) + " " + month.format((A - principal) / (12 * years)) + " " + total.format(A));
        }
    }
}
