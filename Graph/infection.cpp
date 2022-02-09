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
    int time;
    Pair(int src, int time)
    {
        this->src = src;
        this->time = time;
    }
};
void bfs(vector<Edge> graph[], int v, int src, int time)
{

    vector<int> visited(v, false);

    queue<Pair> qu;
    qu.push(Pair(src, 1));

    int cnt = 0;
    // visited[src] = true;

    while(qu.size() > 0)
    {
        auto tp = qu.front();
        qu.pop();
        if(tp.time > time)
        {
            break;
        }
        if(visited[tp.src] == true){
        	// cout<<"yes";
        	continue;
        }
        visited[tp.src] = true;
        // cout<<"yes";
        cnt++;
        for(auto edge : graph[tp.src])
        {
            if(visited[edge.nbr] == false)
            {
                qu.push(Pair(edge.nbr, tp.time + 1));
            }
        }



    }
    cout << cnt << endl;
}

int main()
{
    int n;
    cin >> n;
    int e;
    cin >> e;

    vector<Edge> graph[n];

    for(int i = 0 ; i < e; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        graph[a].push_back(Edge(a, b, wt));
        graph[b].push_back(Edge(b, a, wt));
    }
    int src, time;
    cin >> src >> time;
    // cout<<src<<endl;


    bfs(graph, n, src, time);
    // bfs(graph,n,src,time);
}

