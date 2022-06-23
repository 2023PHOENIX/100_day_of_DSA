#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define inf 1e9
#define INF 1e18
#define mod 10000007
#define MOD 1000000000


struct Pair{
    int bleed;
    int wait;
    int power;
    int last;
    int index;
};

bool comp(Pair &p1,Pair &p2){
    if(p1.last == p2.last){
        return p1.power > p2.power;
    }
    return p1.last > p2.last;
}
int main()
{
    int current, max_stamina, turns, num;
    cin >> current >> max_stamina >> turns >> num;

    vector<Pair> Demon;
    for (int i = 0; i < num; i++){
        int a, b, c;
        cin >> a >> b >> c;

        int demon;
        cin >> demon;

        for (int j = 0; j < demon;j++){
            int d;
            cin >> d;
            if(j == 0){
                Demon.push_back({a, b, c, d,i});
            }
            // score[i].push_back(d);
        }
    }

    sort(Demon.begin(), Demon.end(), comp);


    

    
}