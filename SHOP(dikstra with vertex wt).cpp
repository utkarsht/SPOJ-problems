#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
int source,dest;
int m,n;
char c[30][30];
void addall(vvii& g,int i,int j)
{
	//if(c[i-1][j-1]!='X')	g[i*(m+2)+j].push_back(ii((i-1)*(m+2)+(j-1),c[i-1][j-1]-'0'));
	if(c[i-1][j]!='X')	    g[i*(m+2)+j].push_back(ii((i-1)*(m+2)+(j),c[i-1][j]-'0'));
	//if(c[i-1][j+1]!='X')	g[i*(m+2)+j].push_back(ii((i-1)*(m+2)+(j+1),c[i-1][j+1]-'0'));
	if(c[i][j-1]!='X')	    g[i*(m+2)+j].push_back(ii((i)*(m+2)+(j-1),c[i][j-1]-'0'));
	if(c[i][j+1]!='X')		g[i*(m+2)+j].push_back(ii((i)*(m+2)+(j+1),c[i][j+1]-'0'));
	//if(c[i+1][j-1]!='X')	g[i*(m+2)+j].push_back(ii((i+1)*(m+2)+(j-1),c[i+1][j-1]-'0'));
	if(c[i+1][j]!='X')		g[i*(m+2)+j].push_back(ii((i+1)*(m+2)+(j),c[i+1][j]-'0'));
	//if(c[i+1][j+1]!='X')	g[i*(m+2)+j].push_back(ii((i+1)*(m+2)+(j+1),c[i+1][j+1]-'0'));
}
void inputgraph(vvii& g,int m,int n)
{
	int k,weight;		
	for(int a=0;a<=n+1;a++)
	{
		for(int b=0;b<=m+1;b++)
		{
			if(a==0 || b==0 || a==n+1 || b==m+1)
				c[a][b] = 'X';
			else
			{	cin>>c[a][b];
			if(c[a][b]=='S')
				{	source = a*(m+2)+b;		c[a][b]='0';	}
			if(c[a][b]=='D')
				{	dest = a*(m+2)+b;		c[a][b]='0';	}
			}
		}
	}
	k = 0;
	for(int a=0;a<=n+1;a++)
	{
		for(int b=0;b<=m+1;b++)
		{		
			if(c[a][b]!='X')
				addall(g,a,b);
		}
	}
}

void showgraph(vvii& g)
{
	m+=2;	n+=2;
	for(int i=0;i<m*n;i++)
	{
		cout<<(i)<<"  : ";
		for(int j=0;j<g[i].size();j++)
		{
			cout<<g[i][j].first<<"  ("<<g[i][j].second<<")  "<<"   ";
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
	s.clear();
}

void showsp(vvii& g,vi& dis)
{
	cout<<dis[dest]<<endl;
}

int main()
{	
	while(1)
	{
		cin>>m>>n;
		vvii G((m+2)*(n+2));
		vi dis((m+2)*(n+2),987654321);
		if(!m && !n)	break;
		inputgraph(G,m,n);
		sp(G,source,dis);
		showsp(G,dis);
		dis.clear();
		G.clear();
	}
}
