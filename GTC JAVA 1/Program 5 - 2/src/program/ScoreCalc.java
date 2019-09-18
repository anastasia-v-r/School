package program;

import java.util.*;

public class ScoreCalc {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("How many students are there?");
        int students = input.nextInt();
        Map<String, Integer> studentMap = new HashMap<String, Integer>();
        Integer highScore = 0;
        String topStudent = "";
        for (int i = 0; i < students; i++) {
            String name;
            Integer score;
            System.out.println("Enter the name of Student[" + (i + 1) + "]");
            name = input.next();
            System.out.println("Now their score");
            score = input.nextInt();
            if (score > highScore) {
                highScore = score;
                topStudent = name;
            }
            studentMap.put(name, score);
        }
        System.out.println("The top student was " + topStudent + " with a score of " + highScore);
    }
}
