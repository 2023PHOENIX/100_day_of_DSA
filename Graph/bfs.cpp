#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Edge
{
public:
    int src;
    int nbr;
    int wt;


    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

class Pair{
public:
	int src;
	string asf;
	Pair(int src,string asf){
		this->src = src;
		this->asf = asf;
	}
};
void bfs(vector<Edge> graph[],int v){


	vector<bool> visited(v,false);

	queue<Pair> qu;
	qu.push(Pair(0,"0"));

	while(qu.empty()==false){
		Pair top = qu.front();
		qu.pop();
		visited[top.src] = true;
		cout<<top.src<<"-> "<<top.asf<<endl;
		for(Edge e : graph[top.src]){
			if(visited[e.nbr]==false){
				qu.push(Pair(e.nbr,top.asf + to_string(e.nbr)));
			}
		}
	}

}

int main()
{
	int n;	cin>>n;
	int e;	cin>>e;

	vector<Edge> graph[n];

	for(int i = 0 ; i<n;i++){
		int a,b,wt;	cin>>a>>b>>wt;
		graph[a].push_back(Edge(a,b,wt));
		graph[b].push_back(Edge(b,a,wt));
	}
	bfs(graph,n);
}

