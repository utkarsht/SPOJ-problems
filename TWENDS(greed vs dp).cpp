#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
typedef long long ll;
int max(int a,int b)
{
	return (a>b)?a:b;
}
#define sz 100
int a[sz];
int dp[sz][sz];
int p1=0;
int solve(int i,int j,int n)
{
	if(i>j)		return 0;
	if(i==j)	return a[i];
	if(dp[i][j]!=0)		return dp[i][j];
	if(i+1==j)	{	if(a[i]>=a[j])	{		return a[i];	}	else {		return a[j];	}	}
	if(n==0)	return 0;
	if(n%2==0)	{ 	 dp[i][j] = max(a[i] + solve(i+1,j,n-1) , a[j] + solve(i,j-1,n-1)) ;		return dp[i][j];	}
	else
	{
		if(a[i]>=a[j])
		{		 return solve(i+1,j,n-1);			}
		else
		{		return solve(i,j-1,n-1);			}
	}
}
int main()
{
	int n;
	for(int j=1;1;j++)
	{
		s(n);
		int sum=0;
		F(n)	s(a[i]);
		if(!n)		break;
		memset(&dp,0,sizeof(dp));	
		p1 = solve(0,n-1,n);
		for(int i=0;i<n;i++)
			sum+=a[i];
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",j,2*p1-sum);
	}	
}
