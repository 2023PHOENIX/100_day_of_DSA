#include<iostream>
#include<vector>
#include<queue>

using namespace std;


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
void infection(vector<vector<int>> &graph, int v, int src, int time)
{

    queue<Pair> qu;
    qu.push(Pair(src, 1));
    vector<bool> visited(v, false);

    int count = 0;
    while(qu.empty() == false)
    {
        Pair p = qu.front();
        qu.pop();
        
        if(visited[p.src] == true)
        {
            continue;
        }

        // for(bool x : visited)cout<<x<<",";

        cout<<endl;
        visited[p.src] = true;
        // cout << p.src << endl;
        count++;
        for(int i = 0; i<v;i++){
        	if(visited[i] == false and graph[p.src][i] > 0){
        		
        		qu.push(Pair(i,p.time + 1));
        	}
        }
    }

    cout << count << endl;

}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>(v, -1));
    for (int i = 0; i < e; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        graph[a][b] = wt;
        graph[b][a] = wt;
    }
    int src, time;
    cin >> src >> time;
    infection(graph, v, src, time);
}