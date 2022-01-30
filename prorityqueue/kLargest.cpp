#include<iostream>
#include<queue>

using namespace std;

int main(){

	int n,k;	cin>>n>>k;
	vector<int> v(n);

	for(int &x : v)cin>>x;


	// for(int x : v)cout<<x<<",";
	priority_queue<int,vector<int> ,greater<int>> pq;

	for(int i= 0; i<n;i++){
		if(i<k){
			pq.push(v[i]);
		}else{
			if(pq.top() < v[i]){
				pq.pop();
				pq.push(v[i]);
			}
		}
	}

	while(!pq.empty()){
		cout<<pq.top()<<endl;
	
		pq.pop();
	}

}