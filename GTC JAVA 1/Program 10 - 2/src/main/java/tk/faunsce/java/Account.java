package tk.faunsce.java;

import java.util.Date;

public class Account {
    // Constructors
    public Account() {
        this.id = 0;
        this.balance = 0.0;
        this.annualInterestRate = 0.0;
        this.dateCreated = new Date();
    }
    public Account(int id, double balance) {
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = 0.0;
        this.dateCreated = new Date();
    }
    // Getters
    public int getId() {
        return this.id;
    }
    public double getBalance() {
        return this.balance;
    }
    public double getAnnualInterestRate() {
        return this.annualInterestRate;
    }
    public Date getDateCreated() {
        return this.dateCreated;
    }
    // Setters
    public void setId(int id) {
        this.id = id;
    }
    public void setBalance(double balance) {
        this.balance = balance;
    }
    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = (annualInterestRate / 100.0);
    }
    // Processors
    public double getMonthlyInterestRate() {
        return annualInterestRate / 12;
    }
    public double getMonthlyInterest() {
        return (balance * getMonthlyInterestRate());
    }
    public double withdraw(double amount) {
        this.balance -= amount;
        return amount;
    }
    public void deposit(double amount) {
        this.balance += amount;
    }
    // Data
    private int id;
    private double balance;
    private double annualInterestRate;
    private Date dateCreated;

}
