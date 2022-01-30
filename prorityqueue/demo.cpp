#include<iostream>
#include<queue>

using namespace std;

int main(){
	// bigger has more priority 
	
	priority_queue<int> pq;

	pq.push(10);
	pq.push(20);
	pq.push(30);


	while(pq.size() > 0){
		auto tp = pq.top();
		cout<<tp<<endl;
		pq.pop();
	}
	cout<<endl;
	priority_queue<int,vector<int>,greater<int>> qp;
	qp.push(20);
	qp.push(10);
	qp.push(30);

	while(qp.size() > 0){
		auto tp = qp.top();
		cout<<tp<<endl;
		qp.pop();
	}

}