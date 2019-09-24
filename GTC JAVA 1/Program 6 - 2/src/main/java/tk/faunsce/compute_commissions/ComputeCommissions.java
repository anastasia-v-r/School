package tk.faunsce.compute_commissions;

public class ComputeCommissions {
    public static void main(String[] args) {
        System.out.println("Sales Amount Commission");
        for (int  i = 10000; i <= 100000; i += 5000) {
            System.out.println(i + " " + computeCommission(i));
        }
    }

    public static  double computeCommission(double salesAmount) {
        double commission = 0;
        int counter = 0;
        double percent;
        while (salesAmount > 0) {
            double remainder = (salesAmount % 5000);
            double tempAm = (remainder == 0) ? 5000 : remainder;
            salesAmount -= tempAm;
            if (counter == 0) {
                percent = .08;
            } else if (counter == 1) {
                percent = .10;
            } else {
                percent = .12;
            }
            commission += tempAm * percent;
            counter++;
        }
        return commission;
    }
}
