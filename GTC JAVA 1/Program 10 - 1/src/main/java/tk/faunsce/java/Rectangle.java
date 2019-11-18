package tk.faunsce.java;

public class Rectangle
{
    // Constructors
    public Rectangle() {
        this.width = 1;
        this.height = 1;
    }
    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }
    // Getters
    public double getWidth() {
        return this.width;
    }
    public double getHeight() {
        return this.height;
    }
    // Processors
    public double getArea() {
        return (width * height);
    }
    public double getPerimeter() {
        return ((width * 2) + (height * 2));
    }
    // Data
    private double width;
    private double height;
}