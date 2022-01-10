#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Node {
    public:
        int data;
        vector<Node *> child;

        Node(int data){
            this->data = data;
        }
};
class Tree{
    Node *root;

    public: 
        Node * construct(vector<int> v){

            stack<Node *> st;
            int n = v.size();
            for (int i = 0; i < n;i++){
                if(v[i]==-1){
                    Node *ch = st.top();
                    st.pop();
                    
                    if(st.size()==0){
                        root = ch;
                    }else{
                        st.top()->child.push_back(ch);
                    }
                }else{
                    Node *tp = new Node(v[i]);
                    st.push(tp);
                }
            }

            return root;
        }
};

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(auto &x : v)
        cin >> x;

    Tree tree;
    Node *root = tree.construct(v);

    root->child.size();
}