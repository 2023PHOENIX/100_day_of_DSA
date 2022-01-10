#include<iostream>
#include<vector>
#include<queue>
#include<stack>


using namespace std;

struct Node{
    int val;
    vector<Node *> child;
    Node(int data)
    {
        this->val = data;
    }
};
 

Node *constructTree(vector<int> v){

    Node *root = nullptr;

    stack<Node *> st;
    int n = v.size();

    for (int i = 0; i < n;i++){
        if(v[i]==-1){
            Node* temp = st.top();
            st.pop();
            if(st.size()==0){
                return temp;
            }
            st.top()->child.push_back(temp);
        }else{
            Node *temp = new Node(v[i]);
            st.push(temp);
        }
    }
    return root;
}


void levelOrder(Node *root)
{

    queue<Node *> qu;
    qu.push(root);

    while(!qu.empty()){

        int size = qu.size();

        for (int i = 0; i < size;i++){

            auto top = qu.front();
            qu.pop();
            cout << top->val << ", ";

            for (auto x : top->child){
                qu.push(x);
            }
        }
        cout << endl;
    }
}

int main(){

    vector<int> v{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = constructTree(v);
    levelOrder(root);
}