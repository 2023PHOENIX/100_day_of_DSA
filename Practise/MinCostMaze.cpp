#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9
#define INF 1e18
#define mod 10000007
#define MOD 1000000000

int maze[10][10];
int dp2[10][10];

int f(int i, int j, int n, int m)
{   
    if(i==n || j==n){
        return 0;
    }
    else if(i==n-1 and j==m-1){
        return dp2[i][j] = maze[i][j];
    }else if(i==n-1){
        return dp2[i][j] =  dp2[i][j + 1] + maze[i][j];
    }else if(j==m-1){
        return dp2[i][j] = dp2[i + 1][j] + maze[i][j];
    }else{
        return dp2[i][j] = maze[i][j] + min(dp2[i + 1][j], dp2[i][j + 1]);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }

    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
            {
                dp[i][j] = maze[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = maze[i][j] + dp[i][j - 1];
            }
            else if (j == 0)
            {
                dp[i][j] = maze[i][j] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = maze[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << f(0, 0, n, m) << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp2[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n - 1][m - 1];
}