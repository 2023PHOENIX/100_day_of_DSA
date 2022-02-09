#include<bits/stdc++.h>
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

void printAllPaths(vector<Edge> graph[], vector<bool>  &visited,
                   int src, int dest, string psf)
{
    if(src == dest){
        cout<<psf<<endl;
        return;
    }


    visited[src] = true;

    for(Edge edge : graph[src]){
        if(visited[edge.nbr]==false){
            printAllPaths(graph,visited,edge.nbr,dest,psf + to_string(edge.nbr));
        }
    }

    visited[src] = false;


}


int main()
{
    int v;
    cin >> v;
    vector<Edge> graph[v];
    int e;
    cin >> e;

    for(int i = 0; i < e; i++)
    {
        int s, n, w;
        cin >> s >> n >> w;
        Edge e(s, n, w);
        Edge e1(n, s, w);
        graph[s].push_back(e);
        graph[n].push_back(e1);
    }

    // display(graph, v);


    int src;
    cin >> src;
    int dest;
    cin >> dest;

    // findDest(src,dest,graph,v);
    vector<bool> visited(v, false);
    printAllPaths(graph, visited, src, dest, to_string(src));
}
