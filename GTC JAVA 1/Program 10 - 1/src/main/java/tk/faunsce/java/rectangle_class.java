package tk.faunsce.java;

import tk.faunsce.java.Rectangle;

public class rectangle_class {
    public static void main(String[] args) {
        Rectangle rect1 = new Rectangle(4.0, 40.0);
        Rectangle rect2 = new Rectangle(3.5, 35.9);
        System.out.println("The width and height of Rect1 are W[" + rect1.getWidth() + "] H[" + rect1.getHeight() + "]");
        System.out.println("The are is " + rect1.getArea() + " and the perimeter is " + rect1.getPerimeter());
        System.out.println("The width and height of Rect2 are W[" + rect2.getWidth() + "] H[" + rect2.getHeight() + "]");
        System.out.println("The are is " + rect2.getArea() + " and the perimeter is " + rect2.getPerimeter());
    }
}
