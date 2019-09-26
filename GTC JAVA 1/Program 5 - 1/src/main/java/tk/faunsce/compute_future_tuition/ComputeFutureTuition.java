package tk.faunsce.compute_future_tuition;

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
