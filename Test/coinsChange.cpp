#include<iostream>
#include<vector>

using namespace std;

vector<int> dp;
int helper(int amount, vector<int> &coins, int idx)
{
    if(idx >= coins.size())
    {
        return 0;
    }
    if(amount < 0)
    {
        return 0;
    }
    if(dp[amount]!=-1){
        return dp[amount];
    }



    int inc = helper(amount - coins[idx], coins, idx);

    int exc = helper(amount, coins, idx + 1);
    dp[amount] = inc + exc;
    return inc + exc;
}
int change(int amount, vector<int> &coins)
{
    dp = vector<int>(amount + 1,-1);
    dp[0] = 1;
    int ans = helper(amount, coins, 0);
    cout<<dp[amount]<<endl;
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> coins(n);

    for(int &x : coins)
    {
        cin >> x;
    }
    int tar;
    cin >> tar;

    change(tar, coins);
}

