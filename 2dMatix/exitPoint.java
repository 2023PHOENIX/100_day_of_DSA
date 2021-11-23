import java.util.*;



public class exitPoint {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    
        int n = sc.nextInt();
        int m = sc.nextInt();   
        int[][] matrix = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        int i = 0, j = 0, dir = 0;

        while (true) {

            dir = (dir + matrix[i][j]) % 4;
            if (dir == 0) {
                j++;
                if (j == m) {
                    j--;
                    break;
                }
            }
            else if (dir == 1) {
                i++;
                if (i == n) {
                    i--;
                    break;
                }
                
            } else if (dir == 2) {
                j--;
                if (j == -1) {
                    j++;
                    break;
                }
            } else {
                i--;
                if (i == -1) {
                    i++;
                    break;
                }
            }
        }

        System.out.println(i);
        System.out.println(j);        
    }
    
}
