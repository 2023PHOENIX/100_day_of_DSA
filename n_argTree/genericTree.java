import java.util.*;

import javax.sound.sampled.Line;

public class genericTree {

    private static class Node {
        int data;
        ArrayList<Node> children = new ArrayList<>();

        Node(int data) {
            this.data = data;
        }
    }

    // construct generic tree 
    public static Node construct(int[] arr) {
        Node root = null;

        Stack<Node> st = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == -1) {
                if (st.size() == 1) {
                    root = st.peek();
                    return root;
                }
                Node x = st.pop();
                st.peek().children.add(x);

            } else {
                Node temp = new Node(arr[i]);
                st.push(temp);
            }
        }
        return root;
    }
    
    // LevelOrder Traversal
    public static void LevelOrderTraversal(Node root)
    {
        Queue<Node> qu = new LinkedList<>();
        qu.add(root);

        while (qu.isEmpty() == false) {
            int size = qu.size();

            for (int i = 0; i < size; i++) {
                Node top = qu.remove();

                System.out.print(top.data + ", ");
                for (Node child : top.children) {
                    qu.add(child);
                }
            }
            System.out.println();
        }
    }
    // size of generic tree 
    public static int SizeOfTree(Node node) {

        int cnt = 0;

        for (Node child : node.children) {
            cnt += SizeOfTree(child);
        }

        return cnt + 1;
    }
    


    // pre-order post-order traversal
    public static void traversals(Node root) {
        System.out.println("Node Pre " + root.data);

        for (Node child : root.children) {
            System.out.println("Edge Pre " + root.data + "--" + child.data);
            traversals(child);
            System.out.println("Edge Post " + root.data + "--" + child.data);
        }
        System.out.println("Node Post " + root.data);
    }

    // Remove Leaves in Generic Tree
    public static void RemoveLeaves(Node root) {
        

        // children whose size == 0 just remove it 
        for (int i = root.children.size() - 1; i >= 0; i--) {
            Node child = root.children.get(i);
            if (child.children.size() == 0) {
                // System.out.println(child.data + "this is delete");
                root.children.remove(i);
            }
            RemoveLeaves(child);
        }
    }

    // max depth of tree
    public static int height(Node root) {
        int height = -1;

        for (Node child : root.children) {
            height = Math.max(height(child), height);
        }

        return height + 1;
    }

    public static void display(Node node) {
        
        System.out.print(node.data + " -> ");
        for (Node child : node.children) {
            System.out.print(child.data + ", ");
        }
        System.out.println(".");

        for (Node child : node.children) {
            display(child);
        }
    }

    public static boolean find(Node node, int data) {
        if (node.data == data) {
            return true;
        }

        for (Node child : node.children) {
            boolean faith = find(child, data);
            if (faith) {
                return true;
            }
        }
        return false;
    }
    
    public static ArrayList<Integer> NodeToRoot(Node root,int data) {
        if (root.data == data) {
            ArrayList<Integer> arr = new ArrayList<>();
            arr.add(root.data);
            return arr;
        }
        for (Node child : root.children) {
            ArrayList<Integer> faith = NodeToRoot(child,data);
            if (faith.size() > 0) {
                faith.add(root.data);
                return faith;
            }

        }
        
        return new ArrayList<>();
    }

    public static void mirror(Node node) {

        for (int i = 0; i < node.children.size(); i++) {
            mirror(node);
        }

        Collections.reverse(node.children);
    }
    
    public static int LCA(Node node, int x, int y) {
        ArrayList<Integer> xpath = NodeToRoot(node, x);
        ArrayList<Integer> ypath = NodeToRoot(node, y);

        int i = xpath.size() - 1;
        int j = ypath.size() - 1;

        while (i >= 0 && j >= 0 && xpath.get(i) == ypath.get(j)) {

            i--;
            j--;
        }
        return xpath.get(i + 1);
    }

    public static void zigzak(Node node) {
        LinkedList<Node> qu = new LinkedList<>();
        LinkedList<Node> st = new LinkedList<>();
        qu.addLast(node);
        int level = 0;
        while(qu.size() > 0){
            int sz = qu.size();

            while (sz-- > 0) {
                Node tp = qu.removeFirst();
                if (level % 2 == 0) {
                    for (int i = 0; i < tp.children.size(); i++) {
                        st.addFirst(node);
                    }
                } else {
                    for (int i = tp.children.size(); i >= 0; i--) {
                        st.addFirst(node);
                    }
                }
            }
            qu = st;
            st = new LinkedList<>();
            level++;
        }

    }

    public static int distance(Node node, int p1, int p2) {
        ArrayList<Integer> P1 = NodeToRoot(node, p1);
        ArrayList<Integer> P2 = NodeToRoot(node, p2);
        int i = P1.size() - 1;
        int j = P2.size() - 1;
        while (i >= 0 && j >= 0 && P1.get(i) == P2.get(j)) {
            i--;
            j--;
        }
        int distance = 0;
        distance += i + 1;
        distance += j + 1;
        return distance;
    }

    public static Node depth(Node root) {
        
        while (root.children.size() > 0) {
            root = root.children.get(0);
        }

        return root;
    }
    public static void Linearize(Node root) {
        
        for (Node child : root.children) {
            Linearize(child);
        }

        while (root.children.size() > 1) {
            Node lastChild = root.children.remove(root.children.size() - 1);
            Node secondLastChild = root.children.get(root.children.size() - 1);
            Node secondLastTail = depth(secondLastChild);
            secondLastTail.children.add(lastChild);
        }
    }
    

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        // int x = sc.nextInt();
        // int y = sc.nextInt();
        Node root = construct(arr);
        // int a = distance(root, x, y);
        // System.out.println(a);
        // mirror(root);
        // RemoveLeaves(root);
        // display(root);
        // System.out.println(find(root, x));
        // ArrayList<Integer> ans = NodeToRoot(root, x);
        Linearize(root);
        display(root);
    }
}


// 1.level order traversal 
// 2. pre-post traversal
// 3. size (count of nodes)
// 4. max of tree
// 5. height of tree
// 6. Mirror of tree
// 7. remove leaves in generic tree
// 8. FIND
// 9. NODE TO ROOT
// 10. Linearlize 
// TODO: FIND , NODE TO ROOT
// TODO: LCA , Distance b/w two nodes
// TODO: isGenericTree Symmetric
// TODO: Ceil and floor
// TODO: level order zigzak
// 