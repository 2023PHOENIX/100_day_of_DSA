#include<iostream>
#include<queue>

using namespace std;

int main(){

	int n;	cin>>n;
	vector<int> v(n);
	for(int &x : v)cin>>x;
	int k;	cin>>k;

	priority_queue<int,vector<int>,greater<int>> pq;
	int i =0;
	for( i = 0; i<k + 1; i++){
		pq.push(v[i]);
	}

	int j = 0;

	while(!pq.empty()){
		int tp = pq.top();
		v[j++] = tp;
		pq.pop();
		if(i<n){
		pq.push(v[i++]);
		}
	}

	for(int &x : v){
		cout<<x<<"\n";
	}
	
}