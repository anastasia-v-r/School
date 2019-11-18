package tk.faunsce.java;

import tk.faunsce.java.Fan;

public class fan_class {
    public static void main(String[] args) {
        Fan fan1 = new Fan();
        fan1.setSpeed(new Fan().FAST);
        fan1.setRadius(10.0);
        fan1.setColor("yellow");
        fan1.setOn(true);
        Fan fan2 = new Fan();
        fan2.setSpeed(new Fan().MEDIUM);
        fan2.setRadius(5.0);
        fan2.setColor("blue");
        fan2.setOn(false);
        System.out.println(fan1.toString());
        System.out.println(fan2.toString());
    }
}
