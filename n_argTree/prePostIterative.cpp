#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;


class Node{
    public:
    int data;
    vector<Node *> children;

    Node(int data){
        this->data = data;
    }
};

class Pair{
    public:
        Node *node;
        int state = -1;
        Pair(Node *n){
            this->node = n;
        }
};
void levelOrder(Node *root)
{

    queue<Node *> qu;
    qu.push(root);

    while (!qu.empty())
    {

        int size = qu.size();

        for (int i = 0; i < size; i++)
        {

            auto top = qu.front();
            qu.pop();
            cout << top->data << ", ";

            for (auto x : top->children)
            {
                qu.push(x);
            }
        }
        cout << endl;
    }
}
Node* Construct(vector<int> arr){
    stack<Node *> st;
    Node *root;
    int n = arr.size();
    for (int i = 0; i < n;i++){
        if(arr[i]==-1){
            if(st.size() == 1){
                root = st.top();
                return root;
            }
            Node *temp = st.top();
            st.pop();
            st.top()->children.push_back(temp);
        }
        else{
            Node *temp = new Node(arr[i]);
            st.push(temp);
        }
    }
    return root;
}

void IterativeTraversal(Node *root){
    Pair *p = new Pair(root);

    stack<Pair *> st;
    st.push(p);
    string pre;
    string post;
    while(!st.empty()){
        Pair* p = st.top();
        if(p->state==-1){
            pre += to_string(p->node->data) + ", ";
            p->state++;
        }else if(p->state<p->node->children.size()){
            Node *child = p->node->children[p->state];
            st.push(new Pair(child));
            p->state++;
        }
        else if (p->state == p->node->children.size()){
            post += to_string(p->node->data) + ", ";
            p->state++;
        }else{
            st.pop();
        }
    }

    cout << pre << endl;
    cout << post << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v){
        cin >> x;
    }
    Node *root = Construct(v);
    IterativeTraversal(root);
}