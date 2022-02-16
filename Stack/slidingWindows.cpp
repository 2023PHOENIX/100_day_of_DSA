#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main(){

	int n;	cin>>n;
	vector<int> v(n);

	for(auto &x : v)cin>>x;

    int k;		cin>>k;
	stack<int> st;
	vector<int> greater(n);

	for(int i = n-1;i>=0;i--){


		while(st.size() > 0 and v[st.top()] <= v[i]){
				st.pop();
		}
		if(st.size()==0){
			greater[i] = n;
		}else{
			greater[i] = st.top();
		}

		st.push(i);
	}

	// for(int x : greater){
	// 	cout<<x<<",";
	// }cout<<endl;

	vector<int> ans(n - k + 1);

	int j = 0;
	for(int i = 0; i<n - k + 1; i++){
	   if(j<i){
	   	  j = i;
	   }

	   while(greater[j]< i + k){
	   		j = greater[j];
	   }
	   ans[i] = v[j];
	   // cout<<ans[i]<<",";
	}
	for(auto x : ans)cout<<x<<",";


}