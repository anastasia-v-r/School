package tk.faunsce.letter_to_grade;

import java.util.Scanner;

public class LetterToGrade {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        str = str.toUpperCase();
        char let = str.charAt(0);
        int grade;
        switch (let)
        {
            case 'A':
                grade = 90;
                break;
            case 'B':
                grade = 80;
                break;
            case 'C':
                grade = 75;
                break;
            case 'D':
                grade = 70;
                break;
            case 'F':
                grade = 0;
                break;
            default:
                grade = 1;
                break;
        }
        System.out.println("Letter " + let + " is grade : " + grade);
    }
}
