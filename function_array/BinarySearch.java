package function_array;

public class BinarySearch {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int x = sc.nextInt();
        findFirstLast(arr,x);

    }
    
    public static void findFirstLast(int[] arr,int x) {
        

        int left = 0, right = 0;
        int mid;

        int firstIndex = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;

            if (arr[mid] > x) {
                right = mid - 1;
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                firstIndex = mid;
                right = mid - 1;
            }
        }

        System.out.println(firstIndex);


    }
}
