import java.util.*;

public class matrixMultiplication {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);

        int n1 = sc.nextInt();
        int m1 = sc.nextInt();

        int[][] mat1 = new int[n1][m1];

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                mat1[i][j] = sc.nextInt();
            }
        }

        // 50 x 40 === 40 x 81
        int n2 = sc.nextInt();
        int m2 = sc.nextInt();
        int[][] mat2 = new int[n2][m2];

        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < m2; j++) {
                mat2[i][j] = sc.nextInt();
            }
        }

        if (m1 != n2) {
            System.out.println("Invalid input");
            return;
        }

        int[][] mat = new int[n1][m2];
        // n1 x m1 || n2 x m2 =>
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m2; j++) {

                for (int k = 0; k < n2; k++) {
                    mat[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }


        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                System.out.print(mat[i][j] + " ");
            }System.out.println();
        }

    }

}