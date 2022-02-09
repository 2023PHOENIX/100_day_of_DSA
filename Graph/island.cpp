#include<iostream>
#include<vector>

using namespace std;

// no of island

void dfs(int **graph,int i,int j,int n,int m){
	if(i<0 or i>=n or j<0 or j>=m or graph[i][j] == 1){
		return;
	}

	graph[i][j] = 1;

	dfs(graph,i + 1,j,n,m);
	dfs(graph,i -1,j,n,m);
	dfs(graph,i,j-1,n,m);
	dfs(graph,i,j + 1,n,m);

}
void Island(int **graph,int n,int m){

	int cnt = 0;

	for(int i = 0; i<n;i++){
		for(int j = 0;j<m;j++){
			if(graph[i][j]==0){
				dfs(graph,i,j,n,m);
				cnt++;
			}
		}
	}

	cout<<cnt<<endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **graph = new int *[n];

    for(int i = 0; i < n; i++)
    {
        graph[i] = new int[m];

        for(int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    Island(graph,n,m);
}