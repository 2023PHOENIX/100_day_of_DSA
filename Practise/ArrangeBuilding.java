import java.util.Scanner;

import java.util.*;
public class ArrangeBuilding {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int prev0 = 1;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int curr0 = prev1;
            int curr1 = prev0 + prev1;

            prev0 = curr0;
            prev1 = curr1;
        }
        
        System.out.println((prev0 + prev1)*(prev0 + prev1));
    }
}
