import java.io.*;
import java.util.*;

public class Ceil {

    public static void main(String[] args) throws Exception {
        // write your code here

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int x = sc.nextInt();

        int fr = floor(a, x);
        int cl = ceil(a, x);
        System.out.println(cl);
        System.out.println(fr);
    }

    public static int floor(int[] a, int x) {
        int low = 0, high = a.length - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (a[mid] >= x && a[mid - 1] < x) {
                return a[mid - 1];
            } else if (a[mid] >= x) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    public static int ceil(int[] a, int x) {
        int low = 0;
        int high = a.length - 1;

        while (low <= high) {
            int m = low + (high - low) / 2;

            if (a[m] <= x && a[m + 1] > x) {
                return a[m + 1];
            } else if (a[m] > x) {
                high = m - 1;
            } else {
                low = m + 1;
            }
        }

        return -1;
    }
}