#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair
{
public:
    Node *node = nullptr;
    int state = 0;

    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

int height(Node *node)
{
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1;
}

class bst
{
public:
    bool isbst = false;
    int max = 0;
    int min = 0;
    Node *root = nullptr;
    int size = 0;
};

bst* Bst(Node *node)
{
    if(!node){
        bst *temp = new bst();
        temp->min = 1e6;
        temp->max = -1e6;
        temp->isbst = true;
        return temp;
    }

    bst *left = Bst(node->left);
    bst *right = Bst(node->right);
    bst *ans = new bst();
    ans->min = min(min(left->max, right->min), node->data);
    ans->max = max(max(left->max, right->max), node->data);
    ans->isbst = (node->data >= left->max) & (node->data <= right->min);

    if(ans->isbst == true){
        if (ans->size > left->size + right->size + 1){
        ans->size = left->size + right->size + 1;
        ans->root = node;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(tmp);
        }
    }

    Node *root = constructTree(arr);

    bst *r = Bst(root);
    cout << r->root->data << "@" << r.size;
}