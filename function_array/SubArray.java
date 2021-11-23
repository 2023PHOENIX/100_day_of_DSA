import java.util.Scanner;

public class SubArray {
    public static void main(String[] args) {
        
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        for (int i = 0; i < a.length; i++) {
            for (int j = i; j < a.length; j++) {
                for (int x = i; x <= j; x++) {
                    System.out.print(a[x] + " ");
                }
                System.out.println();
            }
        }

    }
}
