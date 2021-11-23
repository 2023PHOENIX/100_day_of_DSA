import java.util.*;

public class First_Last_Index {
    

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int x = sc.nextInt();
        System.out.println(findFirstIndex(a, x));
        System.out.println(findLastIndex(a, x));

    }

    static int findFirstIndex(int[] a, int src) {
        int L = 0;
        int R = a.length;

        while (L <= R) {
            int M = L + (R - L) / 2;

            if (a[M] == src && a[M - 1] != src) {
                return M;
            } else if (a[M] >= src) {
                R = M - 1;
            } else {
                L = M + 1;
            }
        }
        return -1;
    }

    static int findLastIndex(int[] a, int src) {
        int L = 0;
        int R = a.length;

        while (L <= R) {
            int M = L + (R - L) / 2;

            if (a[M] == src && a[M + 1] != src) {
                return M;
            } else if (a[M] > src) {
                R = M - 1;
            } else {
                L = M + 1;
            }
        }

        return -1;
    }

}
