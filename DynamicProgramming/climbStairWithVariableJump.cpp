#include<vector>
#include<iostream>

using namespace std;

int mem(vector<int> jumps,vector<int> &dp,int n){
    // base case 

    if(n == jumps.size()){
        return dp[n] = 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ways = 0;

    // cout << jumps[n] << endl;

    for (int jump = 1; jump <= jumps[n]; jump++){
        if(jump + n < dp.size()){
            ways += mem(jumps,dp,n + jump);
        }
    }

    return dp[n] = ways;
}


int main(){

    int n;
    cin >> n;

    vector<int> v(n,0);

    for (int i = 0; i < n;i++){
        cin >> v[i];
    }


    vector<int> dp(n + 1, -1);
    dp[n] = 1;
    int ans = mem(v, dp,0);
    cout << ans << endl;

   
}