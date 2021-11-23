#include<iostream>
#include<vector>
using namespace std;

void targetSubsetSum(vector<int> &v,vector<int> &asf,int n){

    
    if(n<0){
        cout << asf << endl;
        return;
    }
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v){
        cin >> x;
    }
    targetSubsetSum(v, {});
}