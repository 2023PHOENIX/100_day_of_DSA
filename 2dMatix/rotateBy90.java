import java.util.Scanner;

public class rotateBy90 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[][] mat = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = sc.nextInt();
            }
        }

        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            int low = 0, high = n - 1;
            while (low < high) {
                int temp = mat[i][low];
                mat[i][low] = mat[i][high];
                mat[i][high] = temp;
                low++;
                high--;
            }

        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
    }
}
// import java.util.Scanner;

// class rotateBy90 {
// public static void main(String[] args) {

// Scanner sc = new Scanner(System.in);

// int n = sc.nextInt();

// int [][] mat = new int[n][n];

// for (int i = 0; i < n; i++) {
// for (int j = 0; j < n; j++) {
// mat[i][j] = sc.nextInt();
// }
// }

// // Transpose
// for (int i = 0; i < n; i++) {
// for (int j = i; j < n; j++) {
// int temp = mat[i][j];
// mat[i][j] = mat[j][i];
// mat[j][i] = temp;
// }
// }

// // for (int i = 0; i < n; i++) {
// // for (int j = 0; j < n; j++) {
// // int temp = mat[i][j];
// // mat[i][j] = mat[j][i];
// // mat[j][i] = temp;
// // }
// // }

// for (int i = 0; i < n; i++) {
// for (int j = 0; j < n; j++) {
// System.out.print(mat[i][n - 1 - j] + " ");
// }
// System.out.println();
// }

// }
// }

// for (int i = 0; i < n; i++) {
// for (int j = 0; j < n; j++) {
// System.out.print(mat[i][n-1-j] + " ");
// }System.out.println();
// }
// }
// }