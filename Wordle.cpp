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

    cin.ignore();

    for (int i = 0; i < n;i++){

        string S;
        string T;
        cin >> S >> T;

        for (int i = 0; i < S.length();i++){
            if(S[i]==T[i]){
                cout << "G";
            }else{
                cout << "B";
            }
        }
        cout << endl;
    }
}