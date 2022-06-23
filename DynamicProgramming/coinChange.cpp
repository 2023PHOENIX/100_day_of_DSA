#include<iostream>
#include<vector>

using namespace std;


int coinsCombination(vector<int> coins,int amt){
    
    if(amt < 0){
        return 0;
    }
    if(amt == 0){
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < coins.size();i++){
        if(amt - coins[i] >= 0){
            ans += coinsCombination(coins, amt - coins[i]);
        }
    }

    return ans;
}
int main(){

    int n;
    cin >> n;

    vector<int> coins(n);
    for(int &x : coins)
        cin >> x;

    int amt;1
    cin >> amt;

    int comb = coinsCombination(coins, amt);
    cout << comb << endl;
}