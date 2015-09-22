#include<bits/stdc++.h>
#define M 105
using namespace std;
int main()
{
	int n,m,x,b,wt;
	int a[M][M];
	long double dis[M][M];
	while(1)
	{	
	cin>>n;		if(n==0)		break;
	cin>>m;
	memset(&a,0,sizeof(a));
	memset(&dis,0,sizeof(dis));
	for(int i=0;i<m;i++)
	{
		cin>>x>>b>>wt;
		x--;	b--;
		a[x][b] = wt;
		a[b][x] = wt;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			dis[i][j] = (long double)a[i][j]/100;
	}
	for(int k=0;k<=n;k++)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(dis[i][k]*dis[k][j]>dis[i][j])
					dis[i][j] = (long double)(dis[i][k]*dis[k][j]);
			}
		}
	}
	dis[0][n-1] = 100*dis[0][n-1];
	printf("%.6llf percent\n",dis[0][n-1]);
	}
}
