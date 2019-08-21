/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package program;
import java.util.Scanner;
/**
 *
 * @author drutter5082
 */
public class MilesPerGallon
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Please chose a program. A/a for Summation or B/b for Runners Average.");
        String choice = scan.nextLine();
        switch (choice)
        {
            case("A"):
            case("a"): {
                int total = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
                System.out.println("Summation of sequence is ... " + total);
                break;
            }
            case("B"):
            case("b"): {
                //mile = 1.6km 14km 45m 30s avg mph
                double mileTotal = 14.0 / 8.0;
                mileTotal = mileTotal * 5.0;
                System.out.println(mileTotal);
                double seconds = 45.5 * 60.0;
                double avg = mileTotal / seconds;
                avg = avg * (60 * 60);
                System.out.println(avg);
                break;
            }
        }
    }

}
