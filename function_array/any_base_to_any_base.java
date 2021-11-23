

import java.util.Scanner;

public class any_base_to_any_base {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int sourceBase = scn.nextInt();
        int  destBase= scn.nextInt();

        int x = anyDecimal(n,sourceBase);
        int y = anyBase(x,destBase);
        System.out.println(y);

    }

    static int anyBase(int n,int b){

        int p = 1;
        int newNum = 0;

        while(n>0){

            newNum += (n % b)*p;
            p = p * 10;

            n = n / b;
        }

        return newNum;
    }
    static int anyDecimal(int n,int b){
     int p = 1;
    int newNum = 0;


    while(n>0){

        newNum += (n%10)*p;

        p = p * b;
        n = n/10;
    }

    return newNum;
    }
}
