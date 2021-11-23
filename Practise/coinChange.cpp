#include<vector>
#include<iostream>
#include<cstring>
using namespace std;

int dp[1001];
int arr[1001];
int n;
int tar;

int F(int idx, int sum)
{
    if(sum==0){
        return dp[0] = 1;
    }

   
    if(sum < 0){
        return 0;
    }
    if(idx >= n){
        return 0;
    }

    

    return dp[sum] = F(idx + 1, sum) + F(idx , sum-arr[idx]);
}

int main(){

    cin >> n;

    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }

    cin >> tar;


    memset(dp, sizeof dp,0);
    cout << F(0, tar) << endl;

    cout << dp[tar] << endl;
}