package program;

import java.util.*;

public class PalindromeIntChecker {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean pal = false;
        boolean repeat = true;
        String sign =  "";
        while (repeat) {
            repeat = false;
            pal = false;
            System.out.println("Please enter a 3 digit integer :");
            int num = input.nextInt();
            if (num < 0) {
                num = 0 - num;
                sign = "-";
            }
            while (num < 100 || num > 999) {
                if (num < 100) {
                    System.out.println("That number was too small, please try again : ");
                } else {
                    System.out.println("That number was too big, please try again : ");
                }
                num = input.nextInt();
                if (num < 0) {
                    num = 0 - num;
                    sign = "-";
                }
            }
            for (int i = 1; i < 9; i++) {
                int hun = (num - (num % (i * 100))) / 100;
                int one = num % 10;
                if (hun == one) {
                    pal = true;
                    break;
                }
            }
            if (pal) {
                System.out.println("The number " + sign + num + " is a palindrome.");
            } else {
                System.out.println("The number " + sign + num + " is not a palindrome.");
            }
            System.out.println("Would you like to go again? [y/n]");
            String cont = input.nextLine();
            cont = input.nextLine();
            if (cont.equals("y") || cont.equals("Y")) {
                repeat = true;
            }
        }
    }
}

// Write	a	program	that	prompts	the	user	to	enter	a three-digit	integer	and	determines
// whether	it	is	a	palindrome	integer.	An integer	is	palindrome	if	it	reads	the	same
// from	right	to	left	and	from	left	to right.	A	negative	integer	is	treated	the	same
// as	a	positive	integer.	Here	are sample	runs	of	this	program:
// Enter	a	three-digit	integer:	121		121	is	a	palindrome
//Enter	a	three-digit	integer:	123	123	is	not	a	palindrome