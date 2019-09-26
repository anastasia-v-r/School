package tk.faunsce.financial_calculator;

import	java.util.Scanner;

public class FinancialCalc {
    public static void main(String[] args) {
        Scanner	input	=	new	Scanner(System.in);
        //	Receive	the	amount
        System.out.print( "Enter an	amount in double, for example 11.56: ");
        double	amount	=	input.nextDouble();
        int	remainingAmount	=	(int)(amount	*	100);
        //	Find	the	number	of	one	dollars
        int	numberOfOneDollars	=	remainingAmount	/	100;
        remainingAmount	=	remainingAmount	%	100;
        //	Find	the	number	of	quarters	in	the	remaining	amount quarters
        int	numberOfQuarters	=	remainingAmount	/	25;
        remainingAmount	=	remainingAmount	%	25;
        //	Find	the	number	of	dimes	in	the	remaining	amount dimes
        int	numberOfDimes	=	remainingAmount	/	10;
        remainingAmount	=	remainingAmount	%	10;
        //	Find	the	number	of	nickels	in	the	remaining	amount nickels
        int	numberOfNickels	=	remainingAmount	/	5;
        remainingAmount	=	remainingAmount	%	5;
        //	Find	the	number	of	pennies	in	the	remaining	amount pennies
        int	numberOfPennies	=	remainingAmount;

        //	Display	results	output
        System.out.println("Your	amount	"	+	amount	+	"	consists	of");
        if (numberOfOneDollars == 1)
            System.out.println("	"	+	numberOfOneDollars	+	"	dollar");
        else if (numberOfOneDollars > 1)
            System.out.println("	"	+	numberOfOneDollars	+	"	dollars");
        if (numberOfQuarters == 1)
            System.out.println("	"	+	numberOfQuarters	+	"	quarter");
        else if (numberOfQuarters > 1)
            System.out.println("	"	+	numberOfQuarters	+	"	quarters");
        if (numberOfDimes == 1)
            System.out.println("	"	+	numberOfDimes	+	"	dime");
        else if (numberOfDimes > 1)
            System.out.println("	"	+	numberOfDimes	+	"	dimes");
        if (numberOfNickels == 1)
            System.out.println("    "   +   numberOfNickels +   "   nickel");
        else if (numberOfNickels > 1)
            System.out.println("	"	+	numberOfNickels	+	"	nickels");
        if (numberOfPennies == 1)
            System.out.println("	"	+	numberOfPennies	+	"	penny");
        else if (numberOfPennies > 1)
            System.out.println("	"	+	numberOfPennies	+	"	pennies");
    }
}
