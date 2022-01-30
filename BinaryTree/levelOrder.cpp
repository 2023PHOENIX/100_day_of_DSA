#include <iostream>
#include <stack>
#include<queue>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
struct Pair
{
    Node *node;
    int state;
    Pair(Node *node)
    {
        this->node = node;
        this->state = 1;
    }
};


void levelOrder(Node *root){

    queue<Node *> qu;
    qu.push(root);
    while(!qu.empty()){
        int x = qu.size();

        while(x--){
        Node *n = qu.front();
        qu.pop();
        cout << n->data <<", ";
        if(n->left){
            qu.push(n->left);
        }
         if(n->right){
            qu.push(n->right);
        }
        }
        cout<< endl
    }
}
Node *construct(vector<int> v)
{
    stack<Pair *> st;

    Node *root = new Node(v[0]);
    int idx = 1;
    st.push(new Pair(root));

    while (!st.empty())
    {

        Pair *p = st.top();

        if (p->state == 1)
        {
            if (v[idx] != -1)
            {
                Node *n = new Node(v[idx]);
                p->node->left = n;
                st.push(new Pair(n));
            }
            idx++;
            p->state++;
        }
        else if (p->state == 2)
        {
            if (v[idx] != -1)
            {
                Node *n = new Node(v[idx]);
                p->node->right = n;
                st.push(new Pair(n));
            }
            idx++;
            p->state++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

void display(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << endl;
    display(root->left);
    display(root->right);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "n")
        {
            v[i] = -1;
        }
        else
        {
            v[i] = stoi(s);
        }
    }

    Node *root = construct(v);
    // display(root);
    levelOrder(root);
    // cout << root->data << endl;
}