#include<iostream>
#include<vector>

using namespace std;
int s;
class Edge{
public:
	int src;
	int nbr;
	int wt;

	Edge(int src,int nbr,int wt){
		this->src = src;
		this->nbr = nbr;
		this->wt = wt;
	}
};

void dfs(vector<Edge> graph[],int src,vector<bool> &visited,int v,vector<int> &asf){

	if(asf.size() == v){
		bool isCycle = false;
		for(auto edge : graph[src]){
			if(edge.nbr == s){
				isCycle = true;
				break;
			}
		}
		for(auto x : asf)cout<<x;
		(isCycle)?cout<<"*":cout<<".";
		cout<<endl;
		return;
	}
	// cout<<asf<<endl;
	visited[src] = true;
	for(Edge edge : graph[src]){
		if(visited[edge.nbr]==false){
			asf.push_back(edge.nbr);
			dfs(graph,edge.nbr,visited,v,asf);
			asf.pop_back();
		}
	}
	visited[src] = false;

}

void hamiltonianPath(vector<Edge> graph[],int v){
	vector<bool> visited(v,false);

	vector<int> ans;
	ans.push_back(s);
	dfs(graph,s,visited,v,ans);
}

int main(){

	int v,e;	cin>>v>>e;

	vector<Edge> graph[v];

	for(int i = 0; i<e;i++){
		int a,b,wt;	cin>>a>>b>>wt;

		graph[a].push_back(Edge(a,b,wt));
		graph[b].push_back(Edge(b,a,wt));
	}
		cin>>s;

	hamiltonianPath(graph,v);
}