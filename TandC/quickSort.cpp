#include<iostream>
#include<vector>
using namespace std;


int main(){

    int n;
    cin >> n;
    vector<int> v(n);

    for(auto &x : v)
        cin >> x;
    quickSort(v, 0, v.size() - 1);

    for(auto &x : v)
        cout << x;
}