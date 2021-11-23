import java.util.*;
public class BinarySearch2D {
    
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
    
        int n = sc.nextInt();
        int[][] mat = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = sc.nextInt();
            }
        }

        int target = sc.nextInt();

        int targetRow = findRow(mat, target);


        for (int j = 0; j < mat[0].length; j++) {
            if (mat[targetRow][j] == target) {
                System.out.println(targetRow);
                System.out.println(j);
                return;
            }
        }

        System.out.println("Not Found");


    }
    
    static int findRow(int[][] mat, int target) {

        int n = mat.length;
        int m = mat[0].length;

        for (int i = 0; i < n; i++) {
            if (mat[i][m - 1] >= target) {
                return i;
            }
        }

        return -1;
    }
    

}
