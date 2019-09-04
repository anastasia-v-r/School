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
public class RunnersAverage
{
    public static void main(String[] args)
    {
        double mileTotal = 14.0 / 8.0;
        mileTotal = mileTotal * 5.0;
        System.out.println(mileTotal);
        double seconds = 45.5 * 60.0;
        double avg = mileTotal / seconds;
        avg = avg * (60 * 60);
        System.out.println(avg);
    }

}
