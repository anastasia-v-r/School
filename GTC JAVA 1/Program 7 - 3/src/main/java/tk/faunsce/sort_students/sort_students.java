package tk.faunsce.sort_students;

import java.util.*;

public class sort_students {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("How many students will you be tracking?");
        int size = input.nextInt();
        String[] stuName = new String[size];
        Integer[] stuScore = new Integer[size];
        for (int i = 0; i < size; i++) {
            System.out.println("Please enter the students name");
            stuName[i] = input.next();
            System.out.println("Please enter the score of " + stuName[i]);
            stuScore[i] = input.nextInt();
        }
        boolean noswap = true;
        for (int i = 1; i < size; i++) {
            noswap = true;
            for (int j = 0; j < size - i; j++) {
                if (stuScore[j] > stuScore[j + 1]) {
                    Integer temp = stuScore[j];
                    stuScore[j] = stuScore[j + 1];
                    stuScore[j + 1] = temp;
                    noswap = false;
                }
            }
            if (noswap)
                break;
        }
        for (int i = size - 1; i >= 0; i--) {
            System.out.println("Student \"" + stuName[i] + "\" Score : [" + stuScore[i] + "]");
        }
    }
}
