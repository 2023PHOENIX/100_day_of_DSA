#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9
#define INF 1e18
#define mod 10000007
#define MOD 1000000000


int findMultiple(int b,int n1,int d){


    int newNum = 0;
    int carry = 0;
    int p = 1;
    
    while(n1>0){
         int x = n1 % 10;
         x = x * d + carry;

         carry = x / b;
         newNum += (x%b) * p;

         p = p * 10;
         n1 = n1 / 10;
    }

    return newNum;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int b;
    cin >> b;
    int n1, n2;
    cin >> n1 >> n2;

    int p = 1;
    int newNum = 0;
    int carry = 0;

    while(n2 >0){
        int x = n2 % 10;
        int m = findMultiple(b, n1, x);

            
    }
}
