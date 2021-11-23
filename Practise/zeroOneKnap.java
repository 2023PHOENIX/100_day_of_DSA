import java.util.Scanner;

public class zeroOneKnap {
    




   
    



    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] price = new int[n];
        int[] weight = new int[n];

        for (int i = 0; i < n; i++) {
            price[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            weight[i] = sc.nextInt();
        }
        int W = sc.nextInt();
        int[][] dp = new int[n + 1][W + 1];
        int ans = Fn(0, W, weight, price,dp);
        System.out.println(ans);


    }
    
    static int Fn(int idx, int W, int[] wt, int[] price,int [][] dp) {

        if (dp[idx][W]!=0) {
            return dp[idx][W];
        }
        if (idx >= wt.length) {
            return 0;
        }

        if (W <= 0) {
            return 0;
        }

        int exclude = Fn(idx + 1, W, wt, price,dp);
        int include = 0;

        if (wt[idx] <= W) {
            include = Fn(idx + 1, W - wt[idx], wt, price,dp) + price[idx];
        }
        

        return dp[idx][W] = Math.max(include, exclude);
    }
}
