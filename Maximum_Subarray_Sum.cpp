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

    vector<int> v(n);

    for(auto &x : v)
        cin >> x;

    long long int  maxSum = v[0];
    long long int currSum = v[0];

    for (int i = 1; i < n;i++){

        if(currSum < 0){
            currSum = v[i];
        }else{
            currSum += v[i];
        }
        maxSum = max(maxSum, currSum);
    }

    cout << maxSum << endl;
}