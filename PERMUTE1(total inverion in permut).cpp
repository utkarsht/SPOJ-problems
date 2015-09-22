//		key point of programm is that if count(n,k)  shows exact k inversion in all permutation of n element array.
//		then  count(n,k) = count(n-1,k) + count(n-1,k-1) + count(n-1,k-2)  +  count(n-1,k-3) .... up to n terms 

#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define space	printf("   ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
typedef long long ll;

int main()
{
	int t,i,j,n,k,max,z;
	s(t);
	ll dp[14][100];
	while(t--)
	{
		s(n);	s(k);
		memset(&dp,0,sizeof(dp));
		for(i=0;i<=n;i++)	{	dp[i][0]=1;	 }	
		dp[2][1]=1;
		dp[3][1]=2;		dp[3][2]=2;		dp[3][3]=1;
		max=(n*(n-1))/2;
		for(i=4;i<=n;i++)
		{
			z=(k<=max)?k:max;
			for(j=1;j<=k;j++)
			{
				if(j<i)	    {	dp[i][j] = dp[i][j-1] + dp[i-1][j] ;  }
				else		{	dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i];  }
			}
		}
	/*	for(i=0;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			{
				p(dp[i][j]);	space;
			}
			nl;
		}*/
		pl(dp[n][k]);	
		nl;
	}

}
