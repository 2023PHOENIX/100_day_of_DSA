#include<iostream>
#include<vector>
using namespace std;
int val;
int partition(vector<int> &v, int lo, int hi, int pivot)
{
    int i = lo, j = lo;
    
    while(i<=hi){
        if(v[i] <= pivot){
            swap(v[i], v[j]);
            j++;
        }
        i++;
    }
    return j - 1;
}
int quickSelect(vector<int> &v,int lo,int hi){
    
    if(lo > hi){
        return -1;
    } 
    int pivot = v[hi];

    int pIdx = partition(v, lo, hi,pivot);

    if(pIdx > val){
        return quickSelect(v, lo, pIdx - 1); 
    }else if(pIdx < val){
        return quickSelect(v, pIdx + 1,hi);
    }else{
        return pIdx;
    }
}

int main(){
    int n;
    cin >> n;


    vector<int> v(n);
    for(auto &x : v){
        cin >> x;
    };



    cin >> val;
    int idx = quickSelect(v, 0, v.size() - 1);
    cout << v[idx] << endl;
}


// 10^9