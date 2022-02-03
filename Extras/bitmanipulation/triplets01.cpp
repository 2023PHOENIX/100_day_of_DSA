#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int> &v){

	int n = v.size();
	int cnt = 0;
	for(int i = 0; i<n;i++){
		int val = v[i];
		for(int k = i + 1; k<n;k++){
			val ^= v[k];

			if(val == 0){
				cnt += (k - i);
			}
		}
	}
	cout<<cnt<<endl;
	return;
}


int main(){
	int n;	cin>>n;
	vector<int> v(n);
	for(int &x : v){
		cin>>x;
	}
	solve(v);
}