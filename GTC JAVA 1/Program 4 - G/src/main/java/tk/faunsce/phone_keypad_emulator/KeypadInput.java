package tk.faunsce.phone_keypad_emulator;

import java.util.*;

public class KeypadInput {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        char currentChar = ' ';
        int userInput;
        int lastKey = -0;
        int depth = 0;
        String message = "";
        boolean done = false;
        while (!done) {
            userInput = input.nextInt();
            if (userInput == lastKey) {
                switch (userInput)
                {
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 8:
                        if (depth > 2) {
                            depth = 0;
                            message += currentChar;
                        } else {
                            depth++;
                        }
                        break;
                    case 7:
                    case 9:
                        if (depth > 3) {
                            depth = 0;
                            message += currentChar;
                        } else {
                            depth++;
                        }
                        break;
                }
            } else {
                depth = 0;
                message += currentChar;
            }
            lastKey = userInput;
            switch (userInput)
            {
                case 1:
                    currentChar = ' ';
                    break;
                case 2:
                    switch (depth)
                    {
                        case 0:
                            currentChar = 'A';
                            break;
                        case 1:
                            currentChar = 'B';
                            break;
                        case 2:
                            currentChar = 'C';
                            break;
                    }
                    break;
                case 3:
                    switch (depth)
                    {
                        case 0:
                            currentChar = 'D';
                            break;
                        case 1:
                            currentChar = 'E';
                            break;
                        case 2:
                            currentChar = 'F';
                            break;
                    }
                    break;
                case 4:
                    switch (depth)
                    {
                        case 0:
                            currentChar = 'G';
                            break;
                        case 1:
                            currentChar = 'H';
                            break;
                        case 2:
                            currentChar = 'I';
                            break;
                    }
                    break;
                case 5:
                    switch (depth)
                    {
                        case 0:
                            currentChar = 'J';
                            break;
                        case 1:
                            currentChar = 'K';
                            break;
                        case 2:
                            currentChar = 'L';
                            break;
                    }
                    break;
                case 6:
                    switch (depth)
                    {
                        case 0:
                            currentChar = 'M';
                            break;
                        case 1:
                            currentChar = 'N';
                            break;
                        case 2:
                            currentChar = 'O';
                            break;
                    }
                    break;
                case 7:
                    switch (depth)
                    {
                        case 0:
                            currentChar = 'P';
                            break;
                        case 1:
                            currentChar = 'Q';
                            break;
                        case 2:
                            currentChar = 'R';
                            break;
                        case 3:
                            currentChar = 'S';
                            break;
                    }
                    break;
                case 8:
                    switch (depth)
                    {
                        case 0:
                            currentChar = 'T';
                            break;
                        case 1:
                            currentChar = 'U';
                            break;
                        case 2:
                            currentChar = 'V';
                            break;
                    }
                    break;
                case 9:
                    switch (depth)
                    {
                        case 0:
                            currentChar = 'W';
                            break;
                        case 1:
                            currentChar = 'X';
                            break;
                        case 2:
                            currentChar = 'Y';
                            break;
                        case 3:
                            currentChar = 'Z';
                            break;
                    }
                    break;
                case 0:
                    done = true;
                    break;
            }
            System.out.println(currentChar);
            System.out.println(message);
        }
        System.out.println(message);
    }
}
