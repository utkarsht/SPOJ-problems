#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define F(x)	for(int i=0;i<x;i++)
typedef long long ll;
ll max(ll a,ll b)
{
	return (a>b)?a:b;
}
#define sz 10000

ll dp[sz];
int n;
ll a[sz];
ll solve(int i)
{
	if(i==n-1)		return a[i];
	if(i>=n)		return 0;
	if(dp[i]!=0)		return dp[i];
	dp[i] = max(a[i] + solve(i+2) , solve(i+1));
	return dp[i];
}
int main()
{
	int t;
	ll ans;
	s(t);
	for(int j=1;j<=t;j++)
	{
		s(n);
		memset(&dp,0,sizeof(dp));
		F(n)	sl(a[i]);
		ans = solve(0);
		printf("Case %d: %lld\n",j,ans);
	}
}
