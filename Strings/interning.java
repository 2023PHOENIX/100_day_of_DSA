public class interning {
    public static void main(String[] args) {
        
        String s1 = "hello";
        String s2 = "hello";
        // s1 and s2 is pointning to same address
        //  while s3 is pointing to different address but at same value
        String s3 = new String("hello");
        String s4 = s1;

        // == check the stack only not the content
        // equals to check stack first then check the content
        System.out.println(s1==s2);
        System.out.println(s1 == s3);
        
        System.out.println(s1.equals(s2));
        System.out.println(s1.equals(s3));

        String x = s1.replace('h', 'b');
        System.out.println(x);
    }
}
