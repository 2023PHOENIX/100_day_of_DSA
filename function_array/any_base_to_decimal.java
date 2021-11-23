import java.util.Scanner;

public class any_base_to_decimal {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int b = sc.nextInt();

        int p = 1;
        int newNum = 0;

        while (n > 0) {

            newNum += (n % 10) * p;

            p = p * b;
            n = n / 10;
        }
        System.out.println(newNum);
    }
}
