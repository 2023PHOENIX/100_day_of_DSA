#include<iostream>
#include<vector>
#include<stack>

using namespace std;

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
class Pair{
public:
	int src;
	string asf;

	Pair(int src,string asf){
		this->src = src;
		this->asf = asf;
	}
};

void iterativeDFS(vector<Edge> graph[],int v,int src){


	stack<Pair> st;
	st.push(Pair(src,to_string(src)));
	vector<bool> visited(v,false);

	int itr = 0;
	while(st.size() > 0){

		auto top = st.top();
		st.pop();
     if(visited[top.src]==true)continue;
		cout<<top.src<<"@"<<top.asf<<endl;
   
    visited[top.src] = true;
  

		for(Edge edge : graph[top.src]){
			if(visited[edge.nbr]==false){
				st.push(Pair(edge.nbr,top.asf + to_string(edge.nbr)));
			}
		}
		

	}
		


}

int main(){

	int v,e;	cin>>v>>e;

	vector<Edge> graph[v];

	for(int i = 0; i<e;i++){
		int a,b,wt;	cin>>a>>b>>wt;

		graph[a].push_back(Edge(a,b,wt));
		graph[b].push_back(Edge(b,a,wt));

	}
	int src;
	cin>>src;
	iterativeDFS(graph,v,src);
}