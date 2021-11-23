import java.util.*;

class saddlePoint {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] mat = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            
            int saddle = mat[i][0];
            int idx = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] < saddle) {
                    saddle = mat[i][j];
                    idx = j;
                }
            }

            boolean isMax = true;
            for (int k = 0; k < n; k++) {
                if (mat[k][idx] > saddle) {
                    isMax = false;
                    break;
                }
            }

            if (isMax == true) {
                System.out.println(saddle);
            }




           
        }
    }
}

// import java.util.*;

// class saddlePoint {
//     public static void main(String[] args) {

//         Scanner sc = new Scanner(System.in);

//         int n = sc.nextInt();

//         int[][] mat = new int[n][n];

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 mat[i][j] = sc.nextInt();
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {

//                 // find smallest in a row
//                 Boolean isSmallest = true;
//                 for (int xi = 0; xi != n; xi++) {
//                     if (xi != i && mat[xi][j] >= mat[i][j]) {
//                         isSmallest = false;
//                     }
//                 }
//                 // largest in column
//                 Boolean isLargest = true;
//                 for (int xj = 0; xj != n && isSmallest == true; xj++) {
//                     if (xj != j && mat[i][xj] < mat[i][j]) {
//                         isLargest = false;
//                     }
//                 }

//                 if (isLargest == true && isSmallest == true) {
//                     System.out.println(mat[i][j]);
//                 }
//             }
//         }

//     }
// }