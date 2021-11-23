import java.util.*;

class GetSubSequence{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String str = sc.next();
        ArrayList<String> ans = gss(str);

        for(String x : ans){
            System.out.println(x);
        }
    }
    
    static ArrayList<String> gss(String str) {

        if(str.length() == 0){
            ArrayList<String> s = new ArrayList<>();
            s.add("*");
            return s;
        }
        char ch = str.charAt(0);

        //  have faith that for other it will work

        ArrayList<String> faith = gss(str.substring(1));
        ArrayList<String> expect = new ArrayList<>();

        for(String x : faith){
            expect.add("" + x);
        }
        for(String x : faith){
            expect.add(ch + x);
        }

        return expect;
    }
}