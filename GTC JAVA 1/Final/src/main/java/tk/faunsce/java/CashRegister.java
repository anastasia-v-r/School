package tk.faunsce.java;

import javafx.util.Pair;

public class CashRegister {
    // Constructors
    public CashRegister(Pair<RetailItem, Integer>[] items) {
        this.items = items;
    }
    // Getters
    public double getSubTotal() {
        double subTotal = 0.0;
        for (Pair<RetailItem, Integer> item : items) {
            subTotal += (item.getKey().getPrice() * item.getValue());
            item.getKey().setUnitsOnHand(item.getKey().getUnitsOnHand() - item.getValue());
        }
        return subTotal;
    }
    public double getTax() {
        return getSubTotal() * .06;
    }
    public double getTotal() {
        return  getSubTotal() + getTax();
    }
    // Data
    Pair<RetailItem, Integer>[] items;
}
