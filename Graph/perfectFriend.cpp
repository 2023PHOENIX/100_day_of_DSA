#include<iostream>
#include<vector>

using namespace std;

class Edge{
public:
   int src,nbr;
   Edge(int a,int b){
      this->src = a;
      this->nbr = b;
   }
};
void dfs(vector<Edge> graph[],vector<int> &comp,int src,vector<bool> &visited){
   

   visited[src] = true;

   comp.push_back(src);
   // cout<<src<<endl;
   for(Edge e : graph[src]){
      if(visited[e.nbr]==false){
         dfs(graph,comp,e.nbr,visited);
      }
   }



}
void perfectFrd(vector<Edge> graph[],int v){
   vector<bool> visited(v,false);
   vector<vector<int>> comps;
   vector<int> comp;

   for(int i =0; i<v;i++){
      if(visited[i]==false){
         // cout<<"hello";
         dfs(graph,comp,i,visited);
         // cout<<comp.size()<<endl;
         comps.push_back(comp);
         comp.clear();
      }
   }

   int ans = 0;
   for(int i = 0; i<comps.size() ;i++){
      for(int j = i + 1; j<comps.size() ; j++){
         // cout<<comps[i].size()<<","<<comps[j].size()<<endl;
         ans += comps[i].size() * comps[j].size();
      }
   }

   cout<<ans<<endl;

}

int main(){

   int n;   cin>>n;

   int e;   cin>>e;

   vector<Edge> graph[n];

   for(int i = 0; i<e;i++){
      int a,b;  cin>>a>>b;
      graph[a].push_back(Edge(a,b));
      graph[b].push_back(Edge(b,a));
   }

   perfectFrd(graph,n);


}