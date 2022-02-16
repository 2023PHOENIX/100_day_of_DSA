#include<iostream>
#include<stack>

using namespace std;


void fn(vector<int> &v,int idx,stack<int> &st){

	if(idx == v.size()){
		st.push(-1);
		return;
	}

	fn(v,idx + 1,st);

	while(st.size() > 0 and st.top() < v[idx]){
		st.pop();
	}
	if(st.size()==0){
		cout<<v[i] <<" is "<<-1<<endl;
	}else{
		cout<<v[i]<<" is " st.top()<<endl;
	}

	st.push(v[idx]);

}

int main(){

	int n;	cin>>n;
	vector<int> v(n);

	for(auto &x : v)cin>>x;


	stack<int> st;

	fn(v,i,st);
}