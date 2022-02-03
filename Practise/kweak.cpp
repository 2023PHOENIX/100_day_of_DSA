#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct Pair{
	int index;
	int soldiers;
	Pair(int index,int soldiers){
		this->index = index;
		this->soldiers = soldiers;
	}
};
// a > b min heap 

struct Comp{
	bool operator()(Pair a,Pair b){
		if(a.soldiers == b.soldiers){
			return a.index > b.index;
		} 
		return a.soldiers > b.soldiers;
	}
};
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    
    vector<Pair> vp;
    for(int i = 0; i<mat.size() ; i++){
    	int cnt = 0;
    	for(int x : mat[i]){
    		if(x){
    			cnt++;
    		}
    	}
    	vp.push_back({i,cnt});
    }

   	priority_queue<Pair,vector<Pair> , Comp> pq;
   	for(Pair p : vp){
   		pq.push(p);
   	}


   	vector<int> ans(k);
   	for(int i = 0; i<k;i++){
   		ans[i] = pq.top().index;
   		pq.pop();
   	}
   	return ans;
}
int main(){
	int n;	cin>>n;
	vector<vector<int>> v(n,vector<int> (n,0));

	for(auto &vec : v){
		for(auto &x : vec)cin>>x;
	}
	int k;	cin>>k;

	auto ans = kWeakestRows(v,k);
	for(int x : ans)cout<<x<<",";
}