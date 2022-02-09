#include<bits/stdc++.h>
using namespace std;
class PriorityQueue{
    vector<int> data;
public: 
  void upheapify(int idx){
    if(idx==0)return;

    int parent = (idx-1)/2;


    if(data[parent] > data[idx]){
    int temp = data[idx];
    data[idx] = data[parent];
    data[parent] = temp;
    upheapify(parent);
  }

  }
  void add(int val){
    data.push_back(val);

    upheapify(data.size() -1);
  }

  void downheapify(int i){
    int mini = i;

    int left = 2*i + 1;
    int right = 2*i + 2;
   
    if(left < data.size() and data[left] < data[mini])
        mini = left;
    if(right < data.size() and data[right] < data[mini])  
        mini = right;

    if(mini!=i){
    int temp = data[mini];
    data[mini] = data[i];
    data[i] = temp;
    downheapify(mini);
      }
  }
  int remove(){
    if(data.size() == 0){
      cout<<"Underflow"<<endl;
      return -1;
    }

    int t = data[0];
    data[0] = data[data.size() -1];
    data.pop_back();


    downheapify(0);




    return t;
  }
 
  int peek(){
    if(data.size() == 0){
      cout<<"Underflow"<<endl;
      return -1;
    }
    return data[0];
  }
}; 



int main(){
   
  PriorityQueue pq;
  while(1){
      string str;
        getline(cin,str);
      if(str[0]=='a'){
          string num=str.substr(4,str.length());
          int val=stoi(num);
          pq.add(val);
      }else if(str[0]=='r'){
          int val=pq.remove();
          if(val!=-1){
              cout<<val<<endl;
          }
      }else if(str[0]=='p'){
          int val=pq.peek();
          if(val!=-1){
              cout<<val<<endl;
          }
      }else break;
  }


   
}