package program;

import java.text.DecimalFormat;

public class ComputeFutureTuition {
    public static void main(String[] args){
        DecimalFormat df = new DecimalFormat(("0,000.00"));
        double tuition = 10000.0;
        System.out.println("Initial cost of tuition is $" + df.format(tuition));
        for (int i = 0; i < 10; i++) {
            tuition *= 1.05;
            System.out.println("Tuition after " + (i + 1) + " years is $" + df.format(tuition));
        }
        System.out.println("Cost of 4 years of tuition after year 10 is $" + (df.format(tuition * 4)));
    }
}

/* 5.7 (Financial application: compute future tuition) Suppose the tuition
        for a university is $10,000 this year and increases 5% every year. In one
        year, the tuition will be $10,500. Write a program that displays the tuition in
        10 years, and the total cost of four years’ worth of tuition after the tenth
        year.

 */