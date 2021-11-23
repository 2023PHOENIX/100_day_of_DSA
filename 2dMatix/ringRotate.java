import java.util.Scanner;

public class ringRotate {
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

        int s = sc.nextInt();
        int r = sc.nextInt();

        int[] arr = get1D(mat, s);
        // for (int i = 0; i < ans.length; i++) {
        //     System.out.println(ans[i] + " ");
        // }
        Rotate(arr, r);
        int[][] result = get2D(mat, arr, s);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(result[i][j] + " ");
            }System.out.println();
        }
    }
    
    static void Rotate(int[] arr, int r) {

        r = r % arr.length;
        r = (r < 0) ? r + arr.length : r;
        r = arr.length - r;
        reverse(arr, 0, r - 1);
        reverse(arr, r, arr.length - 1);
        reverse(arr, 0, arr.length - 1);
    }

    static void reverse(int[] arr, int s, int e) {
        
        
        while (s < e) {
            int t = arr[s];
            arr[s] = arr[e];
            arr[e] = t;
            s++;
            e--;
        }
    }

    static int[] get1D(int[][] mat, int s) {

        int n = mat.length;
        int m = mat[0].length;

        int minR = s - 1;
        int minC = s - 1;

        int maxR = n - s;
        int maxC = m - s;

        int H = maxC - minC + 1;
        int V = maxR - minR + 1;
        int T = 2 * (H + V) - 4;

        int[] ans = new int[T];
        int idx = 0;
        for (int i = minR; i <= maxR; i++) {
            ans[idx++] = mat[i][minC];
        }
        minC++;
        for (int j = minC; j <= maxC; j++) {
            ans[idx++] = mat[maxR][j];
        }
        maxR--;

        for (int i = maxR; i >= minR; i--) {
            ans[idx++] = mat[i][maxC];
        }
        maxC--;
        for (int j = maxC; j >= minC; j--) {
            ans[idx++] = mat[minR][j];
        }
        minR++;

        return ans;
    }

    static int[][] get2D(int[][] mat, int[] arr,int s) {
        int n = mat.length;
        int m = mat[0].length;

        int minR = s - 1;
        int minC = s - 1;

        int maxR = n - s;
        int maxC = m - s;



        int idx = 0;
        for (int i = minR; i <= maxR; i++) {
            mat[i][minC] = arr[idx++];
        }
        minC++;
        for (int j = minC; j <= maxC; j++) {
            mat[maxR][j] = arr[idx++];
        }
        maxR--;

        for (int i = maxR; i >= minR; i--) {
            mat[i][maxC] = arr[idx++];
        }
        maxC--;
        for (int j = maxC; j >= minC; j--) {
            mat[minR][j] = arr[idx++];
        }
        minR++;

        return mat;
    }
}