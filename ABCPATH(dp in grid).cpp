#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
#define sz 100
#include<iostream>
using namespace std;
typedef long long ll;
int w,h;
char c[sz][52];
int dp[sz][52];
bool ok(int i,int j)
{
	if(i>=0 && i<h && j>=0 && j<w)
		return 1;
	else	
		return 0;
}
int max(int *k)
{
	int maxv=0;
	for(int i=0;i<8;i++)
	{
		if(maxv<k[i])
			maxv=k[i];
	}
	return maxv;
}
int solve(char data,int i,int j)
{
	if(dp[i][j]!=-1 && c[i][j]==data)	return dp[i][j];
	int k[8]={0};
	if(ok(i-1,j-1)  &&  c[i-1][j-1]==data+1)		k[0]=1+solve(data+1,i-1,j-1);
	if(ok(i-1,j)	&&	c[i-1][j]  ==data+1)		k[1]=1+solve(data+1,i-1,j);	
	if(ok(i-1,j+1)	&&	c[i-1][j+1]==data+1)		k[2]=1+solve(data+1,i-1,j+1);
	if(ok(i,j-1)	&&	c[i][j-1]  ==data+1)		k[3]=1+solve(data+1,i,j-1);
	if(ok(i,j+1)	&&	c[i][j+1]  ==data+1)		k[4]=1+solve(data+1,i,j+1);
	if(ok(i+1,j-1)	&&	c[i+1][j-1]==data+1)		k[5]=1+solve(data+1,i+1,j-1);
	if(ok(i+1,j)	&&	c[i+1][j]  ==data+1)		k[6]=1+solve(data+1,i+1,j);
	if(ok(i+1,j+1)	&&	c[i+1][j+1]==data+1)		k[7]=1+solve(data+1,i+1,j+1);
	dp[i][j] = max(k);
	if(dp[i][j]==0)		dp[i][j]=1;
	return dp[i][j];
}

int main()
{
	int i,j,t,ans;
	for(t=1;1;t++)
	{
		s(h);	s(w);
		if(!h && !w)	break;
			memset(&dp,-1,sizeof(dp));
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				cin>>c[i][j];
			}
		}
		int max = 0,ans=0;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(c[i][j]=='A')
				{	ans = solve('A',i,j);	if(max<ans)		{	max=ans;}}
			}
		}
		printf("Case %d: %d\n",t,max);
	}
}
