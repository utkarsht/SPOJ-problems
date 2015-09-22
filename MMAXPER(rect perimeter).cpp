#include<bits/stdc++.h>
using namespace std;
struct rect
{
	int p[2];
};
int abs(int x)
{
	return (x>0)?x:-x;
}
int max(int x,int y)
{
	return (x>y)?x:y;
}
rect r[1002];
int dp[1002][2];
int n;

int solve(int i,int idx)
{
	if(i==n-1)
		return r[i].p[idx];
	if(dp[i][idx]!=-1)
		return dp[i][idx];
	else
	{
		dp[i][idx] = r[i].p[idx] + max( abs(r[i+1].p[1-idx]-r[i].p[1-idx]) + solve(i+1,idx) , abs(r[i+1].p[idx]-r[i].p[1-idx]) + solve(i+1,1-idx) );
		return dp[i][idx];
	}	
}
int main()
{
	int x,y;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>r[i].p[0]>>r[i].p[1];
	}
	
	memset(&dp,-1,sizeof(dp));
	x = solve(0,0);
	memset(&dp,-1,sizeof(dp));
	y = solve(0,1);
	cout<<max(x,y)<<endl;
}
