import java.io.*;
public class rotate_an_array {
     public static void display(int[] a){
    StringBuilder sb = new StringBuilder();

    for(int val: a){
      sb.append(val + " ");
    }
    System.out.println(sb);
  }

  public static void rotate(int[] a, int k){
    // write your code here
    // BA = (A` B `)`
    // reverse(a, 0, k -1);
    // reverse(a, k , a.length - 1);
    k = k % a.length;
    if (k < 0) {
        k = k + a.length;
    }
    reverse(a, 0, a.length - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, a.length-1);

    
  }

  public static void reverse(int [] a,int low ,int high){

    while(low < high){
        int temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        low++;
        high--;
    }

  }

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
       a[i] = Integer.parseInt(br.readLine());
    }
    int k = Integer.parseInt(br.readLine());

    rotate(a, k);
    display(a);
 }

}

