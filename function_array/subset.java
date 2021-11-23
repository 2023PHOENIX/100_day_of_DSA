import java.util.Scanner;

public class subset {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] array = new int[n];

        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        // System.out.println((1<<n));
        for (int i = 0; i < (1 << n); i++) {
            int x = i;
         String str = "";

            for (int j = 0; j < n; j++) {
                int rem = x % 2;
                x = x / 2;

                if (rem == 0) {
                    str += " ";
                } else {

                    str = array[array.length - 1 - j] + str;
                }
            }
            
            System.out.println(str);
    
        }
        
    }
}
