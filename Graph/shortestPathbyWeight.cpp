#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Edge{
public:

	int src;
	int nbr;
	int wt;

	Edge(int a,int b,int wt){
		this->src = a;
		this->nbr = b;
		this->wt = wt;
	}
};
class Pair{
public:
	int src;
	string psf;
	int wsf; // weight so far
	Pair(int src,string psf,int wsf){
		this->src = src;
		this->psf = psf;
		this->wsf = wsf;
	}
};

class Comp{
public:
	bool operator()(Pair &p1,Pair &p2){
		// min heap 
		return p1.wsf > p2.wsf;
	}
};


void shortestPath(vector<Edge> graph[],int v,int src){


	priority_queue<Pair,vector<Pair>,Comp> pq;
	pq.push(Pair(src,"" + to_string(src),0));

	vector<bool> visited(v,false);

	vector<Pair> vp(v,Pair(-1,"",-1));

	while(pq.empty()==false){
		Pair p = pq.top();
		// removing the node with weight min
		pq.pop();
		
		// if(vp[p.src].src==-1 or vp[p.src].wsf >= p.wsf){
		// 	vp[p.src] = p;
		// }		
		if(visited[p.src]==true){
			continue;
		}
		cout<<p.src<<" via "<<p.psf<<" @ "<<p.wsf<<endl;

		visited[p.src] = true;
		// 0 via 0 @ 0
		for(Edge edge : graph[p.src]){
			if(visited[edge.nbr]==false){
				pq.push(Pair(edge.nbr,p.psf + to_string(edge.nbr),p.wsf + edge.wt));
			}
		}
	}

	// for(auto p : vp){
	// 	
	// }
}

int main(){

	int v,e; cin>>v>>e;
	vector<Edge> graph[v];

	for(int i = 0; i<e;i++){
		int a,b,wt;	cin>>a>>b>>wt;
		graph[a].push_back(Edge(a,b,wt));
		graph[b].push_back(Edge(b,a,wt));
	}
	int src;	cin>>src;
	shortestPath(graph,v,src);
}