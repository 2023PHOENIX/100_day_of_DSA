#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int maxProfit(int k,vector<int> &prices){
	int n = prices.size();
	vector<int> dp(prices.size() , 0);
	dp[n-1] = 0;

	for(int i = n-1;i>=0;i--){
		dp[i] = 0;
		for(int j = i; j<n;j++){
			if(prices[i] < prices[j]){
				dp[i] = max(dp[i] , prices[j] - prices[i]);
			}
		}
	}

	priority_queue<int,vector<int>,greater<int>> pq;

	for(int x : dp){
		if(x > 0){

			if(pq.size() > k){
				if(pq.top() < x){
					pq.pop();
					pq.push(x);
				}
			}else{
				pq.push(pq.top());
				pq.pop();
			}

		}
	}
	int ans =0;
	while(pq.size()> 0){
		ans += pq.top();
		pq.pop();
	}
	return ans;
}

int main(){
	int n;	cin>>n;
	// cout<<"y"<<endl;
	vector<int> v(n);
	for(int &x : v)cin>>x;
	int k;	cin>>k;
	int ans = maxProfit(k,v);
	cout<<ans<<endl;
}