#include<iostream>
#include<vector>

using namespace std;


int main(){
	int n;	cin>>n;
	vector<int> v(n);

	for(int &x : v)cin>>x;

	int d;	cin>>d;

	int dp[d][n];

	int maxAll = 0;
	for(int i = 0; i<n;i++){
		maxAll = max(v[i],maxAll);
		dp[0][i] = maxAll;
	}


	for(int i = 1; i<d;i++){
		for(int j = i; j<n;j++){
			// jth job must be consumed on day i.
			int mn = dp[i-1][j-1] + v[j];
			int mex = v[j];

			for(int k = i ; k<=j;k++){
				mex = max(mex,v[k]);
				mn = min(mn,dp[i-1][k-1] + mex);
			}
		    dp[i][j] = mn;
		}
	}
	// cout<<"hello"<<endl;
	for(int i = 0; i<d;i++){
		for(int j = 0; j<n;j++){
			cout<<dp[i][j]<<" | ";
		}cout<<endl;
	}

	cout<<dp[d-1][n-1]<<endl;
}