import java.util.*;
public class printDecreasing {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        printdecreasing(n);

    }
    
    static void printdecreasing(int n) {
        // base case 
        if (n == 0) {
            return;
        }

        // recursive case
        System.out.println(n);
        printdecreasing(n-1);
    }
}
