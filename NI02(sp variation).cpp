#include<bits/stdc++.h>
#define MAX 2147483647
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

int n;
int d(ii x,ii y)
{
	return (x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second);
}
int getmin(int s,vii& p,vi& visit,vi& dis)
{
	int save,alpha;
	int mini = MAX;
	for(int i=0;i<n+2;i++)
	{
		if(visit[i]==0)
		{ 
			alpha = d(p[s],p[i]);
			if(dis[i] > dis[s]+alpha)
				dis[i] = dis[s]+alpha;
			if(mini>dis[i])
			{
				mini = dis[i];
				save = i;
			}
		}
	}
	return save;
}
int sp(vii& p,int source,int dest)
{
	vi dis(n+2,MAX);	int t = source;
    vi visit(n+2,0);
	dis[source] = 0;	visit[source] = 1;
	while(visit[dest]!=1)
	{
	//	cout<<t<<endl;
		t = getmin(t,p,visit,dis);
		visit[t] = 1;	//	cout<<t<<"   "<<dis[t]<<endl;
	}
	return dis[dest];
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	vii points;		int x,y;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n+2;i++)
		{
			cin>>x>>y;
			points.push_back(ii(x,y));
		}	
		cout<<sp(points,n,n+1)<<endl;
		points.clear();
	}
}
