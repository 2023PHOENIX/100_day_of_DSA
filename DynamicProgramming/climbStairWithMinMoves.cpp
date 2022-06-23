#include<iostream>
#include<vector>
using namespace std;


int mem(vector<int> &jumps,vector<int> &dp,int n){
    if(n==jumps.size()){
        return dp[n] = 0;
    }

    if(dp[n]!=1e5){
        return dp[n];
    }

    int mn = 1e5;
    for (int j = 1; j <= jumps[n];j++){
        // cout << "hello";
        if(j + n <= jumps.size()){
            mn = min(mn, mem(jumps, dp, j + n) + 1);
        }
    }

    return dp[n] = mn;
}   

int main(){

    int n;
    cin >> n;

    vector<int> jumps(n, 0);

    for(int &x : jumps){
        cin >> x;
    } 

    // climb stair with min value.
    vector<int> dp(jumps.size() + 1, 1e5);
    dp[n] = 0;
    int ans = mem(jumps, dp, 0);

    for (int x : dp){
        cout << x << " ";
    }
        cout << ans << endl;
}