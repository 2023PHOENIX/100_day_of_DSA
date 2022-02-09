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

class Pair
{
public:
    int src;
    int dist;

    Pair(int src, int dist)
    {
        this->src = src;
        this->dist = dist;
    }
};

bool bfs(vector<Edge> graph[], int src, vector<bool> &visited)
{


    queue<Pair> qu;
    qu.push(Pair(src, 0));


    while(qu.empty() == false)
    {
        Pair p = qu.front();
        qu.pop();

        if(visited[p.src] == true)
        {
            return true;
            // continue;
        }
        // cout<<p.src<<endl;
        visited[p.src] = true;


        for(Edge edge : graph[src])
        {
            if(visited[edge.nbr] == false)
            {
                qu.push(Pair(edge.nbr, p.dist + 1));
                // cout<<qu.top
            }
        }
    }

    return false;

}
void isCycle(vector<Edge> graph[], int v)
{

    vector<bool> visited(v, false);

    for(int i = 0; i < v; i++)
    {
        if(visited[i] == false)
        {

            // cout<<i<<endl;
            int ans = bfs(graph, i, visited);
            if(ans)
            {
                cout << "true";
                return;
            }
        }
    }
    cout << "false";
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
    isCycle(graph, v);


}