//	http://marioslapseofreason.blogspot.in/2010/12/optimal-vertex-cover-for-tree-linear.html

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define M 100002
int n;
bool visit[M];
bool covered[M];
int ct;

void input(vvi& g,int n)
{
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		a--;	b--;									// Based on 1- num donation
		g[a].push_back(b);					
		g[b].push_back(a);
	}
}
void showgraph(vvi& g)
{
	for(int i=0;i<n;i++)
	{
		cout<<(i+1)<<"  : ";
		for(int j=0;j<g[i].size();j++)
			cout<<g[i][j]+1<<"  ";
		cout<<endl;
	}
}
void dfs(vvi& g,int k)
{
	visit[k] = 1;		int child;
	for(int i=0;i<g[k].size();i++)
	{	
		child = g[k][i];
		if(!visit[child])
		{
			dfs(g,child);
			if(covered[child]==0 && covered[k]==0)
			{
				covered[child] = 1;	covered[k] = 1;
				ct++;	       //  if we want vetex cover vertices make here - vc.push_back(k) 
			}	    	   //  we always choose parent node (here k)and size of vc will be vertex cover size
		}
	}
}
int mvc(vvi& g)
{
	ct = 0;
	memset(&visit,0,sizeof(visit));
	memset(&covered,0,sizeof(covered));
	dfs(g,0);
/*	for(i=0;i<n;i++)
	{
		if(select[i])
			//cout<<i+1<<" ",count++;
	}*/
	return ct;
}

int main()
{
	cin>>n;
	vvi G(n);
	input(G,n);
	if(n==1)	cout<<"1\n";	
	else
		cout<<mvc(G)<<endl;
}
