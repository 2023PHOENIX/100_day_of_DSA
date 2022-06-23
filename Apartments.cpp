#include<bits/stdc++.h>

using namespace std;


int main(){

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n);
    vector<int> apartment(m);

    for(auto &x : desired)
        cin >> x;

    for(auto &x : apartment){
        cin >> x;
    }

    sort(desired.begin(), desired.end());
    sort(apartment.begin(), apartment.end());

    int i = 0, j = 0;

    int cnt = 0;
    while(j<apartment.size() and i < desired.size()){

        if(abs(desired[i] - apartment[j]) <= k){
            i++;
            j++;
            cnt++;
        }
        else if (desired[i] - apartment[j] > k)
        {
            j++;
        }else{
            i++;
        }
    }

    cout << cnt << endl;
}