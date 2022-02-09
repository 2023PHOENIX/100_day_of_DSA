#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
// const INT_MAX  = 1e5;
using namespace std;

int coinChange(vector<int> &coins,int target){


    vector<int> dp(target + 1,1e5);

    dp[0] = 0;

    for(int i = 0; i<=target;i++){
        for(int j = 0;j<coins.size();j++){
            if(i >= coins[j]){
                dp[i] = min(dp[i],dp[i-coins[j]]) + 1;
            }
        }
    }
    for(int i = 0; i<=target;i++){
        cout<<i<<" -> " << dp[i]<<endl;
    }
    return dp[target];

}
int main(){
    int n;  cin>>n;
    vector<int> coins(n,0);

    for(int &x : coins)cin>>x;

    int tar;    cin>>tar;

    int d = coinChange(coins,tar);
        cout<<d<<endl;
}