import java.util.*;

public class unbounderKnapsack {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] cost = new int[n];
        int[] weight = new int[n];

        for (int i = 0; i < n; i++) {
            cost[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            weight[i] = sc.nextInt();
        }

        int target = sc.nextInt();
        int[] dp = new int[target + 1];
        dp[0] = 0;
        for (int wt = 1; wt <= target; wt++) {
            for (int x = 0; x < n; x++) {
                if (wt >= weight[x]) {
                    dp[wt] = Math.max(dp[wt - weight[x]] + cost[x],dp[wt]); 
                }
            }
        }

        for (int c : dp) {
            System.out.println(c);
        }
    
    }

}
