#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Pair{
public:
	int data;
	int list;
	int idx;

	Pair(int data,int list,int idx){
		this->data = data;
		this->list = list;
		this->idx = idx;
	}
};
class compare{
public:
	bool operator()(Pair &p1,Pair &p2){
		return p1.data > p2.data;
	}
};

void mergeLists(vector<vector<int>> &lists){
	// cout<<lists.size()<<endl;
	priority_queue<Pair,vector<Pair>,compare> pq;

	for(int i = 0; i<lists.size();i++){
		Pair p(lists[i][0],i,0);
		pq.push(p);
	}
	vector<int> output;
	// cout<<pq.size()<<endl;
	while(!pq.empty()){
		Pair p = pq.top();
		pq.pop();
		output.push_back(p.data);

		p.idx++;
		if(p.idx < lists[p.list].size()){
			p.data = lists[p.list][p.idx];
			pq.push(p);
		}

	}

	// cout<<output.size()<<endl;
	for(auto x : output){
		cout<<x<<" ";
	}
}

int main(){
	int n;	cin>>n;
	vector<vector<int>> lists(n);


	for(int i = 0; i<n;i++){
		int m;	cin>>m;
		vector<int> vs(m);
		for(int &x : vs)cin>>x;

		lists[i] = vs;
	}
	mergeLists(lists);

}