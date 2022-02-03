#include<iostream>
#include<vector>
#include<algorithm>
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
struct Comp{
	bool operator()(Pair &p1,Pair &p2){
		if(p1.soldiers == p1.soldiers){
			p1.index < p2.index;
		}
		return p1.soldiers < p2.soldiers;
	}
};

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
	
	vector<Pair> vp;
	int n =mat.size();
	for(int i =0; i<n;i++){
		int count = 0;
		for(int x : mat[i]){
			if(x)count++;
		}
		vp.push_back({i,count});
	}


	priority_queue<Pair,vector<Pair>,Comp> pq;
	for(int i = 0; i<k;i++){
		pq.push(vp[i]);
	}
	for(int i = k ; i<n;i++){
		if(pq.top().soldiers >= vp[i].soldiers){
			pq.pop();
			pq.push(vp[i]);
		}
	}

	vector<int> ans(k);
	for(int i = k-1;i>=0;i--){
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