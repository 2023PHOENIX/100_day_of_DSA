#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Node{
    public:
        int data;
        vector<Node *> children;
    Node(int data){
        this->data = data;
    }
};

// construct tree from array
Node *construct(vector<int> arr){

    list<Node *> st;
    Node *root = new Node(arr[0]);
    st.push_back(root);
    for (int i = 1; i < arr.size(); i++){
        if(arr[i] == -1){
            st.pop_back();
        }else{
            Node *temp = new Node(arr[i]);
            st.back()->children.push_back(temp);
            st.push_back(temp);
        }
    }

    return root;
}


// level order traversal
void levelOrderTraversal(Node *root){

    list<Node *> qu;
    // linkedlist behaving as queue
    qu.push_back(root);

    while(qu.empty() == false){
        int size = qu.size();
        while(size-- > 0){
            Node *top = qu.front();
            qu.pop_front();

            cout << top->data << ", ";
            for(Node *child : top->children){
                qu.push_back(child);
            }
        }
        cout << endl;
    }
    cout << endl;
}

// traversal pre-order | post-order 
void traversal(Node *root){
    cout <<"Node Pre "<< root->data << endl;

    for(Node *child : root->children){
        cout << "Edge Pre " << root->data << "--" << child->data << endl;
        traversal(child);
        cout << "Edge Post " << root->data << "--" << child->data << endl;
    }

    cout << "Node Post " << root->data << endl;
}
// serialize 
void serialize(Node *root,vector<int> &v){
    v.push_back(root->data);
    for (int i = 0; i < root->children.size(); i++){
        serialize(root->children[i], v);
    }
    v.push_back(-1);
}

// mirror a tree 
void mirror(Node *root){

    

    for(Node *child : root->children){
        mirror(child);
    }
    int lo = 0;
    int hi = root->children.size() - 1;
    while (lo <= hi)
    {
        Node *temp = root->children[lo];
        root->children[lo] = root->children[hi];
        root->children[hi] = temp;
        lo++;
        hi--;
    }
}

// display function for generic tree
void display(Node *root){
    cout << root->data << " -> ";
    for(Node *child : root->children){
        cout << child->data << ", ";
    }

    cout << "."<<endl;
    for(Node *child : root->children){
        display(child);
    }
}
int main(){

    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int &x : v)
        cin >> x;

    Node *root = construct(v);
    mirror(root);
    // levelOrderTraversal(root);
    display(root);
    // traversal(root);
    
}