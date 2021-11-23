import java.util.Scanner;

public class state_of_wakanda_02 {
    public static void main(String[] args) {
        

        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();


        int[][] mat = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = sc.nextInt();
            }
        }

        for (int k = 0; k < n; k++) {
            
            int j = k;
            int i = 0;

            while (j < n) {
                System.out.println(mat[i][j]);
                j++;
                i++;
            }

        }
    }
}
