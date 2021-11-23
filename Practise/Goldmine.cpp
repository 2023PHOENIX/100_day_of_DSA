const int INT_MAX = 2147483647;
const int INT_MIN = -2147483647;
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[1001][1001];
int F(vector<vector<int>> v, int i, int j, int n, int m)
{
   
    if(dp[i][j]){
        return dp[i][j];
    }
    if (j == m - 1)
    {
        return dp[i][j] = v[i][j];
    }
    if (i == 0)
    {
        return dp[i][j] = v[i][j] + max(F(v, i + 1, j + 1, n, m), F(v, i , j+1, n, m));
    }
    if (i == n - 1)
    {
        return dp[i][j] = v[i][j] + max(F(v, i, j + 1, n, m), F(v, i - 1, j + 1, n, m));
    }

    return dp[i][j] = v[i][j] + max({F(v, i, j + 1, n, m), F(v, i + 1, j + 1, n, m), F(v, i - 1, j + 1, n, m)});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    // F(v, 0, 0, n, m);

    // for (int i = 0; i < n;i++){
    //     for (int j = 0; j < m;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    memset(dp, sizeof dp, 0);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, F(v, i, 0, n, m));
    }

    cout << ans << endl;
}