#include<iostream>
#include<vector>

using namespace std;
struct Node {
    Node *left;
    Node *right;
    int data;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node *construct(vector<int> arr,int lo,int hi){
    if(lo > hi){
        return nullptr;
    }
    int mid = (lo + hi) / 2;

    Node *root = new Node(arr[mid]);
    root->left = construct(arr,lo,mid-1);
    root->right = construct(arr, mid + 1, hi);
    return root;
}
int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;

    Node *root = construct(v, 0, n - 1);
    // cout << root->left->data << endl;
}