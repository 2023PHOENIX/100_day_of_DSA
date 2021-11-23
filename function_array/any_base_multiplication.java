import java.util.*;

public class any_base_multiplication {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int b = scn.nextInt();
        int n1 = scn.nextInt();
        int n2 = scn.nextInt();

        int d = getProduct(b, n1, n2);
        System.out.println(d);
    }

    static int getProduct(int b, int n1, int n2) {

        int p = 1;
        int ans = 0;
        while (n2 > 0) {
            int d = n2 % 10;

            int x = getMultiply(b, n1, d);
            ans = getSum(b, ans, p * x);

            p = p * 10;
            n2 = n2 / 10;
        }

        return ans;
    }

    public static int getSum(int b, int n1, int n2) {
        int newNum = 0;
        int carry = 0, p = 1;

        while (n1 > 0 || n2 > 0) {

            int x = n1 % 10;
            int y = n2 % 10;

            int t = x + y + carry;

            newNum = newNum + (t % b) * p;

            carry = t / b;
            p = p * 10;
            n1 = n1 / 10;
            n2 = n2 / 10;

        }
        if (carry > 0) {
            newNum = newNum + carry * p;
        }

        return newNum;
    }

    static int getMultiply(int b, int n1, int d) {

        int carry = 0;
        int p = 1;
        int newNum = 0;
        while (n1 > 0 || carry > 0) {
            int x = n1 % 10;

            x = x * d + carry;
            carry = x / b;

            newNum += p * (x % b);

            n1 = n1 / 10;
            p = p * 10;
        }

        return newNum;

    }
}
