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


    void dfs(vector<Edge> graph[], vector<bool> &visited, vector<int> &psf, int src)
    {
        visited[src] = true;
        for(Edge edge : graph[src])
        {
            if(visited[edge.nbr] == false)
            {
                psf.push_back(edge.nbr);
                dfs(graph, visited, psf, edge.nbr);
            }
        }
    }
    void getConnectedCmp(vector<Edge> graph[], vector<vector<int>> &comps, int v)
    {


        vector<bool> visited(v, false);
        vector<int> psf;

        for(int i = 0; i < v; i++)
        {
            if(visited[i] == false)
            {
                psf.push_back(i);
                dfs(graph, visited, psf, i);
            }
            if(psf.size() > 0)
            {
                comps.push_back(psf);
                psf.clear();
            }
        }



    }
    int main()
    {
        int vtces;
        cin >> vtces;
        vector<Edge>graph[vtces];

        int edges;
        cin >> edges;
        for(int i = 0; i < edges; i++)
        {
            int v1 ;
            int v2 ;
            int wt ;
            cin >> v1 >> v2 >> wt;
            graph[v1].push_back( Edge(v1, v2, wt));
            graph[v2].push_back( Edge(v2, v1, wt));
        }


        vector<vector<int>> comps;

        // write your code here




        getConnectedCmp(graph, comps, vtces);
        // cout<<"yes";
        cout << "[";
        for(int i = 0 ; i < comps.size() ; i++)
        {
            cout << "[";
            for(int j = 0 ; j < comps[i].size() ; j++)
            {
                if(j != comps[i].size() - 1)
                    cout << comps[i][j] << ", ";
                else
                    cout << comps[i][j];

            }
            cout << "]";
            if(i != comps.size() - 1)cout << ", ";
        }
        cout << "]";
    }