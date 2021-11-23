


import java.util.Scanner;

public class any_base_addition {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int b = scn.nextInt();
        int n1 = scn.nextInt();
        int n2 = scn.nextInt();

        int x = getSum(b, n1, n2);

        System.out.println(x);
    }

    static int getSum(int b, int n1, int n2) {
        int newNum = 0;
        int carry = 0, p = 1;

        while (n1 > 0 || n2 > 0) {

            int x = n1 %10;
            int y  = n2 % 10;

            int t = x + y + carry;

            newNum = newNum + (t%b)*p;

            carry = t/b;
            p = p * 10;
            n1 = n1 /10;
            n2  = n2/10;

        }
        if(carry>0){
            newNum = newNum + carry*p;
        }

        return newNum;
    }
}
