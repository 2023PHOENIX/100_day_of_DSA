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

    Edge(int src, int dest, int wt)
    {
        this->src = src;
        this->nbr = dest;
        this->wt = wt;
    }
};
class Pair
{
public:
    int parent;
    int src;
    int cost;

    Pair(int parent, int src, int cost)
    {
        this->parent = parent;
        this->src = src;
        this->cost = cost;
    }
};

class Comp{
public:
	bool operator()(Pair &p1,Pair &p2){
		// min heap 
		return p1.cost > p2.cost;
	}
};

void prims(vector<Edge> graph[],int v){

	vector<bool> visited(v,false);

	priority_queue<Pair,vector<Pair> , Comp> qu;
	qu.push(Pair(-1,0,0));

	while(qu.size() > 0){

		Pair p = qu.top();
		qu.pop();

		if(visited[p.src]==true)continue;

		visited[p.src] = true;
		if(p.src!=0){
		cout<<"["<<p.src<<"-"<<p.parent<<"@"<<p.cost<<"]"<<endl;
		}
		for(Edge edge : graph[p.src]){
			if(visited[edge.nbr]==false){
				qu.push(Pair(edge.src,edge.nbr,edge.wt));
			}
		}
	}

}
int main()
{
    int v, e;
    cin >> v >> e;

    vector<Edge> graph[v];

    for(int i = 0; i < e; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;

        graph[a].push_back(Edge(a, b, wt));
        graph[b].push_back(Edge(b, a, wt));
    }
    prims(graph,v);
}