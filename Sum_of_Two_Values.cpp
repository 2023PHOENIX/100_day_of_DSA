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

    int n, x;
    cin >> n >> x;

    map<int, int> mp;

    for (int i = 0; i < n;i++){

        int d;
        cin >> d;

        if(mp.find(x-d) != mp.end()){
            (i > mp[x - d]) ? cout << mp[x-d] << " " << i + 1 << endl : cout << i + 1 << " " << mp[x - d] << endl;
            return 0;
        }

        mp[d] = i + 1;
    }

    cout << "IMPOSSIBLE" << endl;
}