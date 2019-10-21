package tk.faunsce.compute_gcd;

import java.util.*;
public class compute_gcd {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] array = new int[5];
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }
        System.out.println("The most common number was [" + gcd(array) + "]");
    }

    public static int gcd(int... numbers) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int gNum = numbers[0];
        int gFreq = 0;
        for (Integer num : numbers) {
            if (!map.containsKey(num))
                map.put(num, 1);
            else
                map.put(num, map.get(num) + 1);
        }
        for (int num : numbers) {
            if (map.get(num) > gFreq) {
                gNum = num;
                gFreq = map.get(num);
            }
        }
        return gNum;
    }
}
