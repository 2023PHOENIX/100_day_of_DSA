import java.io.*;
import java.util.*;

public class stringDifference {

    public static String solution(String str) {
        // write your code here
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < str.length() - 1; i++) {
            char c1 = str.charAt(i);
            char c2 = str.charAt(i + 1);

            sb.append(c1);
            sb.append(c2 - c1);
        }
        
        sb.append(str.charAt(str.length() - 1));
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();
        System.out.println(solution(str));
    }

}