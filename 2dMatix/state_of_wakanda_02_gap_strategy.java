import java.util.Scanner;

public class state_of_wakanda_02_gap_strategy {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
         
        int[][] mat = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = sc.nextInt();
            }
        }

        for (int g = 0; g < mat[0].length; g++) {
            for (int i = 0, j = g; true; i++) {
                System.out.println(mat[i][j]);
            }
        }
    }
}
