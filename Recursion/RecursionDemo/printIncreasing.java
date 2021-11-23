import java.util.Scanner;

import java.util.*;
public class printIncreasing {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        printincreasing(n);

    }
    
    static void printincreasing(int n) {
        if (n == 0) {
            return;
        }
        printincreasing(n - 1);
        System.out.println(n);
    }
}   
