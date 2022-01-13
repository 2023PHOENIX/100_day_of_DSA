#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Node

{

public:
    int data = 0;

    vector<Node *> children;

    Node(int data)

    {

        this->data = data;
    }
};

Node *constructor01(vector<int> &arr)

{

    if (arr.size() == 0)

        return NULL;

    vector<Node *> stack;

    stack.push_back(new Node(arr[0]));

    Node *root = stack[0];

    for (int i = 1; i < arr.size(); i++)

    {

        if (arr[i] != -1)

        {

            Node *node = stack.back();

            Node *nnode = new Node(arr[i]);

            node->children.push_back(nnode);

            stack.push_back(nnode);
        }

        else

            stack.pop_back();
    }

    return root;
}


void Serialize(Node *root,vector<int> &v){
    v.push_back(root->data);
    for(auto x : root->children){
        Serialize(x,v);
    }
    v.push_back(-1);
}
void levelOderZigZag(Node *node)
{
    list<Node *> qu;
    list<Node *> st;

    qu.push_back(node);
    int level = 0;
    while (!qu.empty())
    {
        int size = qu.size();
        while (size-- > 0)
        {
            auto tp = qu.front();
            cout << tp->data << ", ";
            qu.pop_front();
            if (level % 2 == 0)
            {

                for (int i = 0; i < tp->children.size(); i++)
                {
                    st.push_front(tp->children[i]);
                }
            }
            else
            {
                for (int i = tp->children.size() - 1; i >= 0; i--)
                {
                    st.push_front(tp->children[i]);
                }
            }
            
        }
        cout << endl;
        list<Node *> t = st;
        st = qu;
        qu = t;
        level++;
    }
}
void traversal(Node *root)
{

    cout << "pre node : " << root->data << endl;

    for (auto child : root->children)
    {
        cout << "edge pre :" << child->data << " -> " << root->data << endl;
        traversal(child);
        cout << "edge post :" << child->data << " -> " << root->data << endl;
    }

    cout << "post node : " << root->data << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = constructor01(arr);

    vector<int> serial;
    Serialize(root,serial);
        // traversal(root);

        for(auto x : serial){
            cout << x << " ";
        }
}

int main()
{
    solve();

    return 0;
}