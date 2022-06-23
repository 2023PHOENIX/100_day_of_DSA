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

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        if(n < 6){

            cout << 0;
        }else if(n==6){
            cout << 1;
        }else{
            int r = n % 7;

            cout << n / 7 + (r == 6) ? 1 : 0;
        }
        cout << endl;
    }
}