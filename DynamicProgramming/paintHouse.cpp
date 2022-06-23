#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	int n;	cin>>n;

	vector<vector<int>> mat(n,vector<int>(3,0));


	for(int i = 0; i<n;i++){
		for(int j = 0; j<3;j++){
			cin>>mat[i][j];
		}
	}

	vector<vector<int>> dp(n,vector<int>(3,0));

	for(int j = 0;j<3;j++){
		dp[0][j] = mat[0][j];
	}

	for(int i = 1;i<n;i++){
		for(int c = 0; c<3;c++){
			if(c==0){
				dp[i][c] = min(dp[i-1][c + 1],dp[i-1][c + 2]) + mat[i][c];
			}else if(c==1){
				dp[i][c] = min(dp[i-1][c -1],dp[i-1][c + 1]) + mat[i][c];
			}else{
				dp[i][c] = min(dp[i-1][c-1],dp[i-1][c-2]) + mat[i][c];
			}
		}
	}
	int ans = 1e6;
	for(int i = 0;i<3;i++){
		ans = min(dp[n-1][i],ans);
	}

	cout<<ans<<endl;




}