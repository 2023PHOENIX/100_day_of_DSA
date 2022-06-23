#include <bits/stdc++.h>

using namespace std;

int collectGold(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
{

    // j = m-1|| i == 0 || i==n-1

    int ans = 0;
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {

            if (j == m - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else
            {

                dp[i][j] = arr[i][j];
                int mex = 0;
                if (i != 0)
                {
                    mex = max(mex, dp[i - 1][j + 1]);
                }
                if (i != n - 1)
                {
                    mex = max(mex, dp[i + 1][j + 1]);
                }
                mex = max(mex, dp[i][j + 1]);

                dp[i][j] += mex;
            }

            if (j == 0)
            {
                ans = max(ans, dp[i][j]);
            }
        }
    }

    // for(auto x : dp){
    //     for(int p : x){
    //         cout << p << " ";
    //     }
    //     cout << endl;
    // }
    return ans;
}


int collectGold2(int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp){

    vector<vector<int>> dir = { {-1, 1}, {0, 1}, {1, 1}};

    for (int j = m - 1; j >= 0;j--){
        for (int i = n - 1; i >= 0;i--){

            if(j==m-1){
                dp[i][j] = arr[i][j];
            }else{
                int maxGold = 0;
                for (int d = 0; d<dir.size() ; d++){
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];

                    if(r>=0 and r<n and c >= 0 and c < m){
                        maxGold = max(maxGold, dp[r][c] + arr[i][j]);
                    }
                }

                dp[i][j] = maxGold;
            }
        }
    }

    int ans = 0;
    for (int i = 0;i<n;i++){
        ans = max(ans, dp[i][0]);
    }

    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));

    cout << collectGold2(n, m, arr, dp);
}