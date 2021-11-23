#include<iostream>
#include<vector>

using namespace std;


void countSort(vector<int> &v){

    // find min and max

    int mn = 10000;
    int mx = -1111;

    for (int i = 0; i < v.size(); i++){
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
    }

    vector<int> range(mx - mn + 1, 0);

    for (int i = 0; i < v.size() ; i++){
        range[v[i]-mn] += 1;
    }

    // subarray sum
    for (int i = 1; i < range.size();i++){
        range[i] += range[i - 1];
    }

    // for (int i = 0; i < range.size() ;i++){
        // cout << range[i] << " ";
    // }  
    
    
    vector<int> sortedArray(v.size(),0);

    for (int i = v.size() - 1; i >= 0; i--){
        int num = v[i];
        // find index for num
        int idx = range[num - mn];

        sortedArray[idx - 1] = num;
        range[num - mn]--;
    }

    for(auto x : sortedArray){
        cout << x << " ";
    }
}
int main(){

    int n;
    cin >> n;
    vector<int> v(n);

    for(auto &x : v)
        cin >> x;

    countSort(v); 
}