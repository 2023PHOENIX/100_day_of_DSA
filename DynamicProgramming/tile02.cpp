#include<iostream>

using namespace std;

int main(){

	int n,m;	cin>>n>>m;
	int dp[n + 1];

	for(int i = 0; i<=n;i++){
		if(i < m){
		dp[i] = 1;
		}else if(i == m){
			dp[i] = 2;
		}
		else{
			dp[i] = dp[i-m] + dp[i - 1];
		}
	}

	cout<<dp[n]<<endl;
}