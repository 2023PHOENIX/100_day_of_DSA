import java.util.*;
public class removePrime {

    static void solution(ArrayList<Integer> arr) {

        for (int i = arr.size()-1; i >=0; i--) {
            if (isPrime(arr.get(i))) {
                arr.remove(i);   
            }
        }
    }
    
    static Boolean isPrime(int x) {
        
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                return false;
            }
        }

        return true;
    }0
    public static void main(String[] args) {
     
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        ArrayList<Integer> arr = new ArrayList<>(); 

        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }

        solution(arr);

        System.out.println(arr);

    }
}
