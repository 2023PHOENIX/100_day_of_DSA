import java.io.*;
import java.util.*;

public class coinChange {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] coins = new int[n];

        for (int i = 0; i < coins.length; i++) {
            coins[i] = sc.nextInt();
        }

        int target = sc.nextInt();

        int[] dp = new int[target + 1];

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= target; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        System.out.print(dp[target]);
    }
}