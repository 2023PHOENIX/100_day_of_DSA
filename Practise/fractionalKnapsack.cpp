#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9
#define INF 1e18
#define mod 10000007
#define MOD 1000000000

int *price;
int *weight;
int n;
int target;

double F(int tar, int i)
{

    if(i>= n){
        return 0;
    }
    if(target == 0){
        return 0;
    }

    double inc = 0;
    if (tar <= weight[i])
    {
        inc = F(tar - weight[i], i + 1) + price[i];
    }
    else
    {
        double ratio =  price[i]/weight[i];
        double wt = tar * ratio ;

        inc = F(0,i + 1) + wt;
    }

    return max(inc, F(tar, i + 1));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    price = new int[n];
    weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cin >> target;

    cout << F(target, 0);
}