    
import java.io.*;
import java.util.*;

public class SpiralDisplay {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] mat = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = sc.nextInt();
            }
        }

        int rs = 0, re = n - 1, cs = 0, ce = m - 1;

        while (rs <= re && cs <= ce) {

            for (int i = rs; i <= re ; i++) {
                System.out.println(mat[i][cs]);
            }
            cs++;

            for (int i = cs; i <= ce ; i++) {
                System.out.println(mat[re][i]);
            }
            re--;

            for (int i = re; i >= rs && cs <= ce; i--) {
                System.out.println(mat[i][ce]);
            }
            ce--;
            for (int i = ce; i >= cs && rs <= re; i--) {
                System.out.println(mat[rs][i]);
            }
            rs++;
        }
    }

}

