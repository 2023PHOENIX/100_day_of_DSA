#include<iostream>
#include<vector>

using namespace std;
struct Comp{
	bool operator(pair<int,int> p1,pair<int,int> p2){
		int d1 = dist(p1);
		int d2 = dist(p2);

		// max heap
		return d1 < d2;
	}
};

int square(int x){
	return x*x;
}
int dist(pair<int,int> p1){
	return square(p1.first) + square(p1.second);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

	priority_queue<pair<int,int>,vector<pair<int,int>>,Comp> pq;

	for(int i = 0; i<points.size() ; i++){
		if(i<k){
			pq.push({points[i][0],points[i][1]});
		}else{
			auto top = pq.top();
			if(dist({points[i][0],points[i][1]}) <dist(top)){
				pq.pop();
				pq.push({points[i][0],points[i][1]});
			}
		}
	}

	vector<vector<int>> ans(k);

	for(int i = k-1;i>=0;i--){
		ans[i][0] = pq.top().first;
		ans[i][1] = pq.top().second;
	}

	return ans;
}

int main(){
	int n;	cin>>n;
	vector<vector<int>> points(n,vector<int>(2,0));

	for(auto &x : points){
		for(auto &y : x)cin>>y;
	}
	
	auto ans = 
}