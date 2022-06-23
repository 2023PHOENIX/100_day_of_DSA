#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9
#define INF 1e18
#define mod 10000007
#define MOD 1000000000


int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> vp(2*n);

    for (int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;

        vp.push_back({a, 1});
        vp.push_back({b, -1});
    }

    sort(vp.begin(), vp.end());

    int ans = 0;
    int sum = 0;

    for(auto &x : vp){
        sum += x.second;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}   