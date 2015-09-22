//  not working yet

#include<bits/stdc++.h>
#define M 100
using namespace std;
int main()
{
	int n,t,lagat;
	int a[M][M],dis[M][M],time[M][M];
	while(1)
	{
		cin>>n>>t;
		lagat = 0;
		if(n==0 && t==0)	break;
		for(int i = 0 ; i<n ; i++)
			for(int j = 0 ; j<n ; j++)
				cin>>a[i][j];
				
		for(int i = 0 ; i<n ; i++)
			for(int j = 0 ; j<n ; j++)
				cin>>time[i][j];
				
		for(int i = 0 ; i<n ; i++)
			for(int j = 0 ; j<n ; j++)
				dis[i][j] = a[i][j];
						
		for(int k=1;k<n;k++)
		{
			for(int i=0;i<k;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(dis[i][k]+dis[j][k]<dis[i][j] && t > lagat + time[i][j])
					{
						dis[i][j] = dis[i][k] + dis[k][j];
						lagat += time[i][j]; 
					}
				}
			}
		}
		cout<<dis[0][n-1]<<" "<<lagat<<endl;
	}
}
