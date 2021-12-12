#include <bits/stdc++.h>
using namespace std;

class node
{
    public :
    int data;
    node *next;
};

class linked_list
{
public:
    node *head,*tail;
    int size=0;
    
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        size++;
     
        
    }
     void display(){
      for(node* tmp = head; tmp != NULL; tmp = tmp->next){
        cout<<tmp->data<<" ";
      }
     
    }
    
    node * left = NULL;
    int PalindromeHelper(node *right){
        if(!right){
            return 1;
        }

        int result = PalindromeHelper(right->next);
        if(result==0){
            return 0;
        }
        else if(left->data!=right->data){
            return 0;
        }else{
        left = left->next;

            return 1;
        }
    }
    int isPalindrome(){
        left = head;
        return PalindromeHelper(head);
    }
};
int main()
{
    int b ;
    cin>>b;
        linked_list a;
        vector<int> arr(b,0);
        for(int i=0;i<b;i++)
        {
            
            cin>>arr[i];
            a.add_node(arr[i]);
        }
    
        

  int res = a.isPalindrome();
  if(res==1)
  {
  cout<<"true";
  }
  else
  {
      cout<<"false";
  }
    return 0;
}