import java.io.*;
import java.util.*;

public class climbStair {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] dp = new int[n + 1];
        // int ans = climbStairs(n,dp);
        int ans = countPath(n);
        System.out.println(ans);
    }

    static int countPath(int n) {
        int[] dp2 = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                dp2[i] = 1;
            } else if (i == 1) {
                dp2[i] = dp2[i - 1];
            } else if (i == 2) {
                dp2[i] = dp2[i - 1] + dp2[i - 2];
            } else {
                dp2[i] = dp2[i - 1] + dp2[i - 2] + dp2[i - 3];
            }

        }

        return dp2[n];
    }

    static int climbStairs(int n, int[] dp) {

        if (n == 0) {
            return dp[n] = 1;
        }
        if (n < 0) {
            return 0;
        }
        if (dp[n] != 0) {
            return dp[n];
        }

        return dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp) + climbStairs(n - 3, dp);
    }

}