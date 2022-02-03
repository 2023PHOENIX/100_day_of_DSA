#include<bits/stdc++.h>
using namespace std;

void solution(vector<int>&arr){
    //write your code here
    int xxor = 0;
    for(auto x : arr){
        xxor ^= x;
    } 

    int a = 0,b = 0;
    int rmsb = xxor & -xxor;
    for(int i = 0; i<arr.size();i++){
        if((rmsb & arr[i]) == 0){
            a ^= arr[i];
        }else{
            b ^= arr[i];
        }
    }
    if(a > b){
        cout<<b<<endl;
        cout<<a<<endl;
    }else{
        cout<<a<<endl;
        cout<<b<<endl;
    }
    
}
int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    solution(arr);
}