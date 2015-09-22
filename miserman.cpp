#include<iostream>
#include<stdio.h>
#include<string.h>
#define sz 102
#define MAX 2147483647
using namespace std;
int a[sz][sz];
int dp[sz][sz];
int min(int a,int b)
{
	return (a<b)?a:b;
}
int min(int a,int b,int c)
{
	return min(a,min(b,c));
}
int m,n;
int way(int i,int j)
{
	if(j<0 || j>=m)		return MAX;
	if(dp[i][j]!=-1)	return dp[i][j];
	if(i==n-1)	return a[i][j];
	dp[i][j] = a[i][j] + min(way(i+1,j+1),way(i+1,j),way(i+1,j-1));
	return dp[i][j];
}
int main()
{
	int i,j;
	int low = MAX;
	cin>>m>>n;
	memset(&dp,-1,sizeof(dp));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}
	//cout<<way(0,0);
	for(i=0;i<m;i++)
	{
		low = min(low,way(0,i));
	}
	cout<<low<<endl;
}
