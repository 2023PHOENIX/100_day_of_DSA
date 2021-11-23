#include<iostream>
#include<algorithm>
using namespace std;


int main(){

    vector<int> v{9, 5, 0, 4, 8, 2, 0, 3, 0, 6};

    int n = v.size();
    int j = n-1;

    for (int i = n - 1; i >= 0; i--){
        if(v[i]>0){
            swap(v[i], v[j]);
            j--;
        }
    }

    for(auto x : v){
        cout << x << " ";
    }
}