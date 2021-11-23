import java.util.Scanner;

public class sumOfArray {
    public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);


        int n = sc.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i<n;i++){
            arr[i] = sc.nextInt();
        }
        int m = sc.nextInt();
        int [] brr = new int[m];
        for(int i = 0; i<n;i++){
            brr[i] = sc.nextInt();
        }

        int [] sum = new int[n > m?n + 1:m +1];


    }
}
