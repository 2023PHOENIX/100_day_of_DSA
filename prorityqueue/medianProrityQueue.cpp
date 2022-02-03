#include <iostream>
#include <queue>
using namespace std;

class MedianPriorityQueue {
    public:
    priority_queue <int> left;
    priority_queue <int, vector<int>, greater<int>> right;
    
    void push(int val) {
      
       if(right.size() > 0 and val > right.top()){
            right.push(val);
       }else{
            left.push(val);
       }

       handleSize();

    }
    void handleSize(){
        if(left.size() - right.size() == 2){
            int lp = left.top();
            left.pop();
            right.push(lp);
        }else if(right.size() - left.size() == 2){
            int rp = right.top();
            right.pop();
            left.push(rp);
        }
    }
    int pop() {
        if(left.size() >= right.size()){
            int lp = left.top();
            left.pop();
            return lp;
        }
        else{
            int rp = right.top();
            right.pop();
            return rp;
        }
    }
    
    int top() {
        // cout<<left.size() <<" , "<<right.size()<<endl;
        if(left.size() >= right.size())
            return left.top();
        else
            return right.top();
    }
    
    int size() {
          //write your code here
        return left.size()  + right.size();
    }
};

int main() {
    MedianPriorityQueue pq;
    
    string str;
    cin >> str;
    while(str!="quit"){
        if(str=="add"){
            int val;
            cin >> val;
            pq.push(val);
        }
        else if(str=="remove"){
            int val = pq.pop();
            if(val != -1) {
                cout<<val<<endl;
            }
        }
        else if(str=="peek"){
            int val = pq.top();
            if(val != -1) {
                cout<<val<<endl;
            }
        }
        else if(str=="size"){
            cout<<pq.size()<<endl;
        }
        cin >> str;
    }
    
    return 0;
}