// C++ program for implementation of Ford Fulkerson algorithm
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
#define inf 2147483647
#define V 210

int graph[V][V];
int rGraph[V][V];
bool visited[V];
int parent[V];
int N;
 
bool bfs(int s, int t)
{
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<N; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    // If we reached sink in BFS starting from source, then return true, else false
    return (visited[t] == true);
}
int fordFulkerson(int s, int t)
{
    int u, v;
    for (u = 0; u < N; u++)
        for (v = 0; v < N; v++)
             rGraph[u][v] = graph[u][v];
 
    int max_flow = 0;     
    while (bfs(s, t))
    {
        // Find minimum residual capacity of the edhes along the path filled by BFS. 
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
    return max_flow;
}
 
int main()
{
	int t,tmp,k;
	scanf("%d",&t);
	while(t--)
	{
    	scanf("%d",&N);
        memset(graph,0,sizeof(graph));
        for(int i=1;i<N;i++)
        {
            scanf("%d",&tmp);
            for(int j=0;j<tmp;j++)
            {
                scanf("%d",&k);
                if(i==1 || k==N)	graph[i][k]=1;
                else graph[i][k]=inf;
            }
        }
       /* for(int i=1;i<=N;i++) 
             {
                for(int j=1;j<=N;j++)
                    printf("%d ",graph[i][j]);
                printf("\n");
            }*/
    	cout << fordFulkerson(1, N) << endl;
    }
}
