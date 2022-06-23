#include<bits/stdc++.h>

using namespace std;

// accepted solution : O(nLogn)

int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    set<int> s;

    for(auto &x : v)
       {
           cin >> x;
           s.insert(x);
       }



    cout << s.size() << endl;
}