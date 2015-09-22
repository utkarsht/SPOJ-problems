#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,k,pos,i,j;
	int dp[51][51];
	bool a[51];
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		memset(&a,0,sizeof(a));
		memset(&dp,0,sizeof(dp));
		for(i=0;i<k;i++)
		{
			cin>>pos;
			a[pos] = 1;
		}
		
		for(i=1;i<=2*n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(i==1)
				{
					if(j==1)	dp[i][j] = 1;
					else		dp[i][j] = 0;
				}
				else
				{
					if(!a[i])	dp[i][j] = (j==0)?0:dp[i-1][j-1];
					else		dp[i][j] = dp[i-1][j+1] + (j==0)?0:dp[i-1][j-1];
				}
			}
		}	
		for(i=1;i<=2*n;i++)
		{
			for(j=0;j<=i;j++)
				cout<<dp[i][j]<<"  ";
			cout<<endl;
		}
		cout<<dp[2*n][0]<<endl;
	}	
}
