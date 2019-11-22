package tk.faunsce.java;

public class RetailItem {
    // Constructor
    RetailItem(String desc, int units, double price) {
        this.description = desc;
        this.unitsOnHand = units;
        this.price = price;
    }

    // Getters
    public String getDescription() {
        return this.description;
    }
    public int getUnitsOnHand() {
        return this.unitsOnHand;
    }
    public double getPrice() {
        return this.price;
    }

    // Setters
    public void setDescription(String description) {
        this.description = description;
    }
    public void setUnitsOnHand(int unitsOnHand) {
        this.unitsOnHand = unitsOnHand;
    }
    public void setPrice(double price) {
        this.price = price;
    }

    // Data
    private String description;
    private int unitsOnHand;
    private double price;
}
