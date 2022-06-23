#include<bits/stdc++.h>

using namespace std;


int main(){

	int n,k;	cin>>n>>k;


	long long int dp[n + 1][k + 1] = {0};

	for(int i = 1;i<=n;i++){
		for(int j = 1; j<=k;j++){
			if(j>i){
				dp[i][j] = 0;
			}else if(i==j){
				dp[i][j] = 1;
			}else{
				dp[i][j] = dp[i-1][j-1]  + dp[i-1][j] * j;
			}
		}
	}

	cout<<dp[n][k]<<endl;


// for(int i = 1;i<=n;i++){
// 		for(int j = 1; j<=k;j++){
// 			cout<<dp[i][j]<<" ,";
// 		}cout<<endl;
// 	}
}