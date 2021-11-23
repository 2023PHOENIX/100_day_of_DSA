#include<iostream>
#include<vector>

using namespace std;
vector<int> *v;

vector<int> *dp;

bool F(int idx,int sum){
    if(sum==0){
        return true;
    }
    if(idx==v->size()){
        return false;
    }


    return (F(idx + 1, sum) || F(idx + 1, sum - v->at(idx)));
}
int main(){

    int n;
    cin >> n;

    v = new vector<int>(n, 0);

    for (int i = 0; i < n;i++){
        cin >> v->at(i);
    }
    int target;
    cin >> target;
    dp = new vector<int>(n,0);

    int ans = F(0, target);

    cout << ans << endl;
}