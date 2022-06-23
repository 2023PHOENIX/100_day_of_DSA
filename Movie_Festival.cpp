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

    vector<pair<int, int>> vp(n);

    for(auto &x : vp){
        cin >> x.first >> x.second;
    }

    sort(vp.begin(), vp.end(), [&](pair<int, int> p1, pair<int, int> p2)
         { return p1.second < p2.second; });

    int ans = 1;

    int curr = vp[0].second;

    for (int i = 1; i < vp.size(); i++){
        if(curr <= vp[i].first){
            ans++;
            curr = vp[i].second;
        }
    }
    cout << ans << endl;
}