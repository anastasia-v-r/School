package tk.faunsce.hotel_occupancy;

import java.text.DecimalFormat;
import java.util.Scanner;

public class hotel_occupancy {
    public static void main(String[] args) {
        DecimalFormat output = new DecimalFormat("0.00");
        Scanner input = new Scanner(System.in);
        System.out.println("How many floors does this hotel have?");
        int floors = input.nextInt();
        while (floors < 1) {
            System.out.println("Please enter a valid larger than 0 for the number of floors");
            floors = input.nextInt();
        }
        int rooms = 0, occupied = 0;
        for(int i = 0; i < floors; i++) {
            System.out.println("How many rooms are on floor [" + (i + 1) + "]");
            int roomsThisFloor = input.nextInt();
            while (roomsThisFloor < 10) {
                System.out.println("Please enter a value 10 or larger for the number of rooms");
                roomsThisFloor = input.nextInt();
            }
            rooms += roomsThisFloor;
            System.out.println("And how many of the [" + roomsThisFloor + "] rooms are occupied on this floor");
            int occupiedThisFloor = input.nextInt();
            while (occupiedThisFloor > roomsThisFloor || occupiedThisFloor < 0) {
                System.out.println("Please enter a value both larger than 0 and less than the number of rooms this floor for occupied rooms");
                occupiedThisFloor = input.nextInt();
            }
            occupied += occupiedThisFloor;
        }
        System.out.println("Out of the " + floors + " floors, and their rooms totaling " + rooms + ", " + occupied +
                " are occupied which is a rate of %" + (output.format( ((double)occupied / (double)rooms) * 100 )));
    }
}
