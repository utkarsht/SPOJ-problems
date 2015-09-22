#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
int n,m;

void inputgraph(vvii& g)
{
	int a,b,weight;
	while(m--)
	{
		cin>>a>>b>>weight;
		a--;	b--;
		g[a].push_back(ii(b,weight));
		g[b].push_back(ii(a,weight));				// only for Undirected 
	}
}

void showgraph(vvii& g)
{
	for(int i=0;i<n;i++)
	{
		cout<<(i+1)<<"  : ";
		for(int j=0;j<g[i].size();j++)
		{
			cout<<g[i][j].first+1<<"  ("<<g[i][j].second<<")  "<<"   ";
		}
		cout<<endl;
	}
}

void sp(vvii& g,int source,vi& dis)
{
	set<ii> s;		ii k;
	int a,pathlen;		int b,weight;
	s.insert(ii(0,source));	   
    dis[source] = 0;   
	while(!s.empty())
	{
		k = *(s.begin());		s.erase(s.begin());	
		pathlen = k.first;		a = k.second;		
		for(int i=0;i<g[a].size();i++)
		{
			b = g[a][i].first;		weight = g[a][i].second;
			if(dis[b] > dis[a] + weight)
			{
				if(dis[b]!=987654321)	{		s.erase(s.find(ii(dis[b],b)));		}
				dis[b] = dis[a] + weight;
			    s.insert(ii(dis[b],b));
			}
		}
	}
}

void showsp(vi& dis,int k)
{
	if(dis[k]==987654321)
		cout<<"NONE\n";
	else
		cout<<dis[k]<<endl;
}

int main()
{
	int t,source,dest;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>source>>dest;
		source--;	dest--;
		vvii G(n);		
		vi dis(n,987654321);
		inputgraph(G);
		sp(G,source,dis);
		showsp(dis,dest);
	}
}
