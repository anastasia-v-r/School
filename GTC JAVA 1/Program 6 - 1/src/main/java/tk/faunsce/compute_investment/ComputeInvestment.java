package tk.faunsce.compute_investment;

import java.util.Scanner;

public class ComputeInvestment {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter investment amount :");
        double principal = input.nextDouble();
        System.out.println("Enter annual interest rate in decimal (5% == .05) :");
        double interestRate = input.nextDouble();
        System.out.println("Enter number of years : ");
        int years = input.nextInt();
        System.out.println("Future favlue is :" + futureInvestmentValue(principal, interestRate, years));
    }

    public static  double futureInvestmentValue(double investmentAmount, double monthlyInterestRate, int years) {
        double yield = investmentAmount * (1 + monthlyInterestRate) * (years * 12);
        return yield;
    }
}

/*
futureInvestmentValue = investmentAmount × (1 + monthlyInterestRate)
numberOfYears*12

Unclear mathematical function?
 */