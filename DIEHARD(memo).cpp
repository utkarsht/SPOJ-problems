#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define F(x)	for(int i=0;i<x;i++)
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long ll;
typedef unsigned long long ull;
int max(int a,int b)
{
	return (a>b)	? a:b;
}
/*
#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
*/
//void print(int *a,int n)
//{	nl;	F(n)	{	p(a[i]);	space;	}	nl;		}

/*
#include<time.h>
#define timestart int tstart = clock()
#define printtime (double)(clock()-tstart)/CLOCKS_PER_SEC
*/
/*
#define gc getchar_unlocked
void sfast(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
*/
#define sz 250
int dp[sz][sz];

int solve(int h,int a,int chk)
{
	if(h<=0 || a<=0)			return 0;
	if(dp[h][a]!=-1)		return dp[h][a];
	if(chk==0)
	{
		dp[h][a] = 1 + solve(h+3,a+2,1);
		return dp[h][a];
	}
	else
	{
		dp[h][a] = 1 + max(solve(h-5,a-10,0), solve(h-20,a+5,0));
		return dp[h][a];
	}
}
int main()
{
	int t,ans,h,a;
	s(t);
	while(t--)
	{
		memset(&dp,-1,sizeof(dp));
		s(h);	s(a);
		ans = solve(h,a,0);
		p(ans-1);
		nl;
	}

}
