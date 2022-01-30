#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
struct Pair{
    Node *node;
    int state;
    Pair(Node *node){
        this->node = node;
        this->state = 1;
    }
};

Node* construct(vector<int> v){
    stack<Pair *> st;

    Node *root = new Node(v[0]);
    int idx = 1;
    st.push(new Pair(root));

    while(!st.empty()){

        Pair *p = st.top();

        if(p->state == 1){
            if(v[idx]!=-1){
                Node *n = new Node(v[idx]);
                p->node->left = n;
                st.push(new Pair(n));
            }
            idx++;
            p->state++;
        }else if(p->state == 2){
            if (v[idx] != -1)
            {
                Node *n = new Node(v[idx]);
                p->node->right = n;
                st.push(new Pair(n));
            }
            idx++;
            p->state++;
        }else{
            st.pop();
        }

        
    }
    return root;
}

void display(Node *root){
    if(!root){
        return;
    }
    cout << root->data << endl;
    display(root->left);
    display(root->right);
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n;i++){
        string s;
        cin >> s;
        if(s=="n"){
            v[i] = -1;
        }else{
            v[i] = stoi(s);
        }
    }

    Node *root = construct(v);
    display(root);
    // cout << root->data << endl;


}