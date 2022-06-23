#include<iostream>

using namespace std;

int *dp;



int climbStair(int n){
    if (dp[n] != -1)
    {
        return dp[n];
    }

    if(n==0){
        return dp[n] = 0;
    }
    if(n==1){
        dp[n] = 1;
        return dp[n];
    } if(n==2){
        dp[n] = 2;
        return dp[n];
    }if(n==3){
        dp[n] = 4;
        return dp[n];
    }

    // dp 
    


    return dp[n] = climbStair(n - 1) + climbStair(n - 2) + climbStair(n - 3);
}
int main(){

    int n;
    cin >> n;

    dp = new int[n + 1];
    for (int i = 0; i < n + 1; i++){
        dp[i] = -1;
    }

    cout << climbStair(n);
}