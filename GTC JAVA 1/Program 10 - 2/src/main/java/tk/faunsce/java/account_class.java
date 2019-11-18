package tk.faunsce.java;

import tk.faunsce.java.Account;

import java.text.DecimalFormat;

public class account_class {
    public static void main(String[] args) {
        DecimalFormat format = new DecimalFormat("#,###,###.00");
        Account acc = new Account(1122, 20000);
        acc.setAnnualInterestRate(4.5);
        acc.withdraw(2500);
        acc.deposit(3000);
        System.out.println(" Account balance is now $" + format.format(acc.getBalance()) + " with a monthly interest of " + format.format(acc.getMonthlyInterest()) + " an was created on " + acc.getDateCreated());
    }
}
