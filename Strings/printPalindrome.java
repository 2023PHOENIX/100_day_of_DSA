import java.util.*;

public class printPalindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {

                String st = s.substring(i, j + 1);

                if (isPalidrome(st)) {
                    System.out.println(st);
                }
            }
        }
    }

    static Boolean isPalidrome(String s) {

        int low = 0;
        int high = s.length() - 1;

        while (low < high) {
            if (s.charAt(low) != s.charAt(high)) {
                return false;
            }

            low++;
            high--;
        }

        return true;
    }
}
