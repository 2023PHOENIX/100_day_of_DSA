#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9
#define INF 1e18
#define mod 10000007
#define MOD 1000000000

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {

        int N, X;
        cin >> N >> X;

        int correct{0}, incorrect{0}, unattempt{0};

        int marks = 0;
        bool ans = false;
        int val = (X / 3);
        
        if(val == N){
            cout << "YES" << endl;
            cout<<val<<" 0 "<<" 0 "<<endl;
            continue;
        }else if(val + 1 >= N){
            cout << "NO" << endl;
            
        }else{
            // 8  0.
            correct = val + 1;
            // attemps =
            int value = 3 * correct;
            bool flag = false;
            for (int i = val + 2; i < N;i++){
                if(value > X){
                    incorrect++;
                    value--;
                }else{
                    flag = true;
                    unattempt = N - i - correct;
                }
            }

            if(flag){
                cout << "YES" << endl;
                cout << correct << " " << incorrect << " " << unattempt << endl;
            }else{
                cout << "NO" << endl;
            }
        }
        
        

    }
}