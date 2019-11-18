package tk.faunsce.java;

public class Fan {
    // Constructors
    public Fan() {
        this.speed = SLOW;
        this.on = false;
        this.radius = 5.0;
        this.color = "blue";
    }
    // Getters
    public int getSpeed() {
        return this.speed;
    }
    public boolean isOn() {
        return this.on;
    }
    public double getRadius() {
        return this.radius;
    }
    public String getColor() {
        return this.color;
    }
    // Setters
    public void setSpeed(int speed) {
        this.speed = speed;
    }
    public void setOn(boolean on) {
        this.on = on;
    }
    public void setRadius(double radius) {
        this.radius = radius;
    }
    public void setColor(String color) {
        this.color = color;
    }
    // Processor
    public String toString() {
        if (this.on) {
            return ("Fan Speed [" + this.speed + "] Fan Radius [" + this.radius + "] Fan Color [" + this.color + "]");
        } else {
            return ("The fan is off");
        }
    }
    // Data
    public final int SLOW = 1;
    public final int MEDIUM = 2;
    public final int FAST = 3;
    private int speed;
    private boolean on;
    private double radius;
    private String color;
}
