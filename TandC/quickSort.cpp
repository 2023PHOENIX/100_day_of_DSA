#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &v,int lo,int hi,int pivot){

    int i = lo, j = lo;

    while(i<=hi){
        
        if(pivot >= v[i]){
            swap(v[i], v[j]);
            j++;
        }
        i++;
    }

    cout << "pivot index" << j - 1 << endl;
    return j - 1;
}


void quickSort(vector<int> &v,int lo,int hi){

    if(lo>hi){
        return;
    }

    int idx = partition(v, lo, hi, v[hi]);
    quickSort(v, lo, idx - 1);
    quickSort(v, idx + 1, hi);
}
int main(){

    int n;
    cin >> n;
    vector<int> v(n);

    for(auto &x : v)
        cin >> x;
    quickSort(v, 0, v.size() - 1);

    for(auto &x : v)
        cout << x;
}