import java.util.*;
public class Main {
    public class GenericTree {
        Node root;

        GenericTree(Node root) {
            this.root = root;
        }

        public Iterator<Integer> iterator() {
            Iterator<Integer> obj = new GTPreOrderIterator();
            return obj;
        }
    }
    public static class Node {
        int data;
        ArrayList<Node> children = new ArrayList<>();

        Node(int data) {
            this.data = data;
        }
    };

    public static Node construct(int[] arr) {
        Node root = null;

        Stack<Node> st = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == -1) {
                st.pop();
            } else {
                Node t = new Node(arr[i]);
                if (st.size() > 0) {
                    st.peek().children.add(t);
                } else {
                    root = t;
                }
                st.push(t);
            }
        }

        return root;
    }

    public static void display(Node root) {
        System.out.print(root.data + " -> ");
        for (Node child : root.children) {
            System.out.print(child.data + ", ");
        }
        System.out.println();

        for (Node child : root.children) {
            display(child);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Node root = construct(arr);
        display(root);
    }
}