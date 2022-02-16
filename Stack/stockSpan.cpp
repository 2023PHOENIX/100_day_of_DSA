#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int findGreater(stack<int> st,int val){

	int count = 1;

	while(st.size() > 0 and st.top() < val){
		st.pop();
		count++;
	}

	return count;
}

int main(){

	int n;	cin>>n;
	vector<int> v(n);
	for(int &x : v)cin>>x;


	stack<int> st;

	for(int i = 0 ; i<n;i++){
		int x = findGreater(st,v[i]);
		cout<<v[i]<<"\t"<<x<<endl;
		st.push(v[i]);
	}

}