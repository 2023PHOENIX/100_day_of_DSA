import java.io.*;
import java.util.*;

public class getStairPath {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        ArrayList<String> ans = getStairPaths(n);

        System.out.println(ans);
    }

    public static ArrayList<String> getStairPaths(int n) {
        if (n == 0) {
            ArrayList<String> ans = new ArrayList<>();
            ans.add("");
            return ans;
        }
        if (n < 0) {
            ArrayList<String> ans = new ArrayList<>();
            return ans;
        }
        // ... faith

        ArrayList<String> ans = new ArrayList<>();
        for (int i = 1; i <= 3; i++) {
            ArrayList<String> faith = getStairPaths(n - i);

            for (String x : faith) {
                ans.add(i + x);
            }
        }

        return ans;
    }

}
