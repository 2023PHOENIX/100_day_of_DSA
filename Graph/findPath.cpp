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



void display(vector<Edge> graph[], int v)
{
    for(int i = 0; i < v; i++)
    {
        cout << i << "-> ";
        for(Edge x : graph[i])
        {
            cout << x.nbr << ", ";
        }
        cout << endl;
    }
}

bool find(vector<Edge> graph[], int src, int dest, map<int, int> &visited)
{

    if(src == dest)
    {
        return true;
    }
    for(Edge e : graph[src])
    {
        if(visited[e.nbr] == false)
        {
            visited[e.nbr] = true;
            bool ans = find(graph, e.nbr, dest, visited);
            if(ans == true){
            	return true;
            }
        }
    }
}
void findDest(int src, int dest, vector<Edge> graph[], int v)
{

    map<int, int> visited;

    bool ans = find(graph,src,dest,visited);
    cout<<ans<<endl;
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
        graph[s].push_back(e);
    }

    // display(graph, v);


    int src;
    cin >> src;
    int dest;
    cin >> dest;

    findDest(src,dest,graph,v);
}