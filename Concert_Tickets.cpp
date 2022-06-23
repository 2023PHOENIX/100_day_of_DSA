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

    int n, m;
    cin >> n >> m;
    vector<int> ticket(n);
    vector<int> maxPrice(m);

    for(auto &t : ticket)
        cin >> t;

    for(auto &mP : maxPrice)
        cin >> mP;

    multiset<int> mst;

    for(auto &x : ticket){
        mst.insert(x);
    }

    for(auto &mp : maxPrice){
        auto it = mst.upper_bound(mp);

        if(it == mst.begin()){
            // all the ticket are expensive 
            cout<<-1<<endl;
        }else{
            cout << *(--it) << endl;
            mst.erase(it);
        }
    }
}