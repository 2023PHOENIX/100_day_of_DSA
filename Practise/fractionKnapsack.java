import java.io.*;
import java.util.*;

public class fractionKnapsack {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] value = new int[n];
        int[] weight = new int[n];

        for (int i = 0; i < n; i++) {
            value[i] = sc.nextInt();
        }

        for (int j = 0; j < n; j++) {
            weight[j] = sc.nextInt();
        }

        int target = sc.nextInt();

        double[][] dp = new double[n][target + 1];
        for (int i = 0; i < n; i++) {
            for (int w = 0; w <= target; w++) {
                if (w == 0) {
                    dp[i][w] = 0;
                    continue;
                }
                if (i != 0)
                    dp[i][w] = dp[i - 1][w];
                if (weight[i] <= w) {
                    dp[i][w] = Math.max(dp[i][w], dp[i][w - weight[i]] + value[i]);
                } else {
                    double price = w * (value[i] / weight[i]);
                    dp[i][w] = Math.max(dp[i][w], dp[i][0] + price);
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        // for (int j = 0; j <= target; j++) {
        // System.out.print(dp[i][j] + " ");
        // }
        // System.out.println();
        // }
        System.out.println(dp[n - 1][target]);

    }
}