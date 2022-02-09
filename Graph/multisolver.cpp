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


struct myComp
{
    bool operator()(
        pair<int, string> &a,
        pair<int, string> &b)
    {
        return a.first > b.first;
    }
};
string spath;
int spathwt = INT_MAX;
string lpath;
int lpathwt = INT_MIN;
string cpath;
int cpathwt = INT_MAX;
string fpath;
int fpathwt = INT_MIN;

priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;
// min heap


void Path(vector<Edge> graph[], int src, int dest, vector<bool> &visited, int dist, string psf, int criteria, int k)
{
    if(src == dest)
    {

        if(spathwt > dist)
        {
            spathwt = dist;
            spath = psf;
        }
        if(lpathwt < dist)
        {
            lpathwt = dist;
            lpath = psf;
        }
        if(dist > criteria and dist < cpathwt)
        {
            cpath = psf;
            cpathwt = dist;
        }
        if(dist < criteria and dist > fpathwt)
        {
            fpath = psf;
            fpathwt = dist;
        }

        // priority_queue
        if(pq.size() < k)
        {
            pq.push({dist, psf});
        }
        else
        {
            if(pq.top().first < dist)
            {
                pq.pop();
                pq.push({dist, psf});
            }
        }


        return;
    }


    visited[src] = true;

    for(Edge edge : graph[src])
    {
        if(visited[edge.nbr] == false)
        {
            Path(graph, edge.nbr, dest, visited, dist + edge.wt, psf + to_string(edge.nbr), criteria, k);
        }
    }
    visited[src] = false;
}



void multisolver(vector<Edge> graph[], int src, int dest, vector<bool> &visited, int criteria, int k, string psf, int wsf)
{
    //write your code here
    Path(graph, src, dest, visited, 0, to_string(src), criteria, k);



}

int main()
{

    int vtces;
    cin >> vtces;
    vector<Edge>grap h[vtces];

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1 ;
        int v2 ;
        int wt ;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back( Edge(v1, v2, wt));
        graph[v2].push_back( Edge(v2, v1, wt));
    }

    int src;
    cin >> src;
    int dest;
    cin >> dest;

    int criteria;
    cin >> criteria;
    int k;
    cin >> k;

    vector<bool> visited(vtces, false);
    multisolver(graph, src, dest, visited, criteria, k, src + "0", 0);

    cout << "Smallest Path = " << spath << "@" << spathwt << endl;
    cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
    cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
    cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt << endl;
    cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;

    return 0;
}