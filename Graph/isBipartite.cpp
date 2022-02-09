#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge
{
public:
    int src = 0;
    int nbr = 0;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};

class Pair
{
public:
    int src;
    int level;

    Pair(int src, int level)
    {
        this->src = src;
        this->level = level;
    }

};


bool bfs(vector<vector<Edge>> graph, int src, vector<bool> &visited)
{



    queue<Pair> qu;
    qu.push(Pair(src, 1));

    while(qu.empty() == false)
    {
        Pair p = qu.front();
        qu.pop();

        if(visited[p.src] == true)
        {
          // to check odd cycle
            if(p.level%2==1){
              return false;
            }
        }

        visited[p.src] = true;

        for(Edge edge : graph[p.src])
        {
            if(visited[edge.nbr] == false)
            {
                qu.push(Pair(edge.nbr, p.level + 1));
            }
        }


    }



    return true;
}


bool isBipartite(vector<vector<Edge>> &graph, int v)
{

    // if graph is bipartite
    // need to acyclic || even cycle
    vector<bool> visited(v, false);

    for(int i = 0; i < v; i++)
    {
        if(visited[i] == false)
        {
           int ans =  bfs(graph, i, visited);
           if(ans == false){
            return false;
           }
        }
    }

    return true;


}


int main()
{
    int vtces;
    cin >> vtces;
    vector<vector<Edge>> graph(vtces, vector<Edge>());


    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++ )
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge(u, v));
        graph[v].push_back(Edge(v, u));

    }
    bool ans = isBipartite(graph,vtces);

    (ans)?cout<<"true":cout<<"false";
    // write your code here
    return 0;
}