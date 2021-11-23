import java.io.*;
import java.util.*;

public class climbStairVariablejump {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] jumps = new int[n];

        for (int i = 0; i < n; i++) {
            jumps[i] = sc.nextInt();
        }

        int ans = climbStair(jumps, n);
        System.out.println(ans);


    }



    static int climbStair(int[] jumps, int n) {

        int[] ways = new int[n + 1];

        ways[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= jumps[i]; j++) {
                if (i + j > n) {
                    continue;
                }
                ways[i] += ways[i + j];
            }
        }

        // for (int i = 0; i <= n; i++) {
        //     System.out.println(ways[i]);
        // }
        return ways[0];
    }
}