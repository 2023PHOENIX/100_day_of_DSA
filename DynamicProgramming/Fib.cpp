#include<iostream>
#include<vector>

using namespace std;

int *dp;

int mem(int n){
    if(n==1 || n==0){
        dp[n] = n;
        return dp[n];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int second = mem(n - 1);
    int first = mem(n - 2);

    dp[n] = second + first;

    return dp[n];
}
int main(){

    int n;
    cin >> n;
    dp = new int[n + 1];
    for (int i = 0; i <= n;i++){
        dp[i] = -1;
    }
    int ans = mem(n);
    cout << ans << endl;


}