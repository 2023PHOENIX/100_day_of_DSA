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

    vector<int> v(n);

    for(int &a : v)
        cin >> a;

    sort(v.begin(), v.end());

    int i = 0, j = n - 1;
    int cnt = 0;
    while(i<j){

        if(v[i] + v[j] > x){
            j--;
        }else{
            i++;
            j--;
        }
        cnt++;
    }

    if(i==j){
        cnt++;
    }
    cout << cnt << endl;
}