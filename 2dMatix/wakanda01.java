import java.util.Scanner;

public class wakanda01 {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] mat = new int[n][m];

        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) {
                mat[i][j] = sc.nextInt();
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (j % 2 == 0) {
                    System.out.println(mat[i][j]);
                } else {
                    System.out.println(mat[n-1-i][j]);
                }
            }
        }
    }
}
