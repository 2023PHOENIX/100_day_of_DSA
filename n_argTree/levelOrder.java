import java.util.*;


public class Main{
    public static class Node{
        int data;
        ArrayList<Node> children = new ArrayList<>();

        Node(int data){
            this.data = data;
        }
    }

    public static void main(String[] args){
         Node root = new Node(10);

    Node twenty = new Node(20);
    root.children.add(twenty);

    Node thirty = new Node(30);
    root.children.add(thirty);

    Node forty = new Node(40);
    root.children.add(forty);
    
    Node fifty = new Node(50);
    twenty.children.add(fifty);

    Node sixty = new Node(60);
    twenty.children.add(sixty);

    Node seventy = new Node(70);
    thirty.children.add(seventy);

    Node eighty = new Node(80);
    thirty.children.add(eighty);

    Node ninety = new Node(90);
    thirty.children.add(ninety);

    Node hundred = new Node(100);
    forty.children.add(hundred);

    Node hundredten = new Node(110);
    eighty.children.add(hundredten);

    Node hundredtwenty = new Node(120);
    eighty.children.add(hundredtwenty);

    levelOrder(root);
    }
    public static void levelOrder(Node root){
        Queue<Node> queue = new ArrayDeque<Node>();

        queue.add(root);

        while(queue.size() > 0){
            Node top = queue.remove();

            System.out.println(top.data + " ");

            for(Node ch : top.children){
                queue.add(ch);
            }
        }
        System.out.println(".");
    }

    public static void levelOrderLine(Node root){
        Queue<Node> qu = new ArrayDeque<Node>();

        qu.add(root);

        while(qu.size() > 0){

            int size = qu.size();
            for(int i = 0; i<size;i++){
                Node top = qu.remove();
                System.out.print(top.data + ", ");
                for(Node ch : top.children){
                    qu.add(ch);
                }

            }


            System.out.println();
        }
    }
}