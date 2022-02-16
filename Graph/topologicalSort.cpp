#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Edge
{
public:
    int src;
    int nbr;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};

void dfs(vector<Edge> graph[],int src,vector<bool> &visited,stack<int> &tps){

	if(visited[src]==true){
		return;
	}

	visited[src] = true;

	for(auto edge : graph[src]){
		if(visited[edge.nbr]==false){
			dfs(graph,edge.nbr,visited,tps);
		}
	}

	tps.push(src);
}
void topologicalSort(vector<Edge> graph[],int v){
	vector<bool> visited(v,false);
	stack<int> tps;
	for(int i = 0; i<v;i++){
		if(visited[i]==false){
			dfs(graph,i,visited,tps);
		}
	}

	while(tps.size() > 0){
		cout<<tps.top()<<endl;
		tps.pop();
	}
}
int main()
{
    int v, e;
    cin >> v >> e;

    vector<Edge> graph[v];

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(Edge(a, b));
    }
    topologicalSort(graph,v);

}