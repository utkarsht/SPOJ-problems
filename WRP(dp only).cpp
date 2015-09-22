#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define space	printf("   ")
#define nl   printf("\n")
#define sz 100001						
#define M 1000000007
typedef long long ll;
using namespace std;

int dp[2][sz];		
	
int main()
{
	int t,i,j,m,n,k;
	s(t);
	while(t--)
	{
		memset(&dp,0,sizeof(dp));
		s(n);	s(k);	s(m);
		for(i=1;i<=m;i++)
		{
			dp[1][i]=1;
		}
		for(i=2;i<=k;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(j<=m)	{  	dp[i%2][j] = ( dp[(i-1)%2][j-1] + dp[(i)%2][j-1] ) % M ;   }
				else		{   dp[i%2][j] = ( dp[(i-1)%2][j-1] + dp[(i)%2][j-1] - dp[(i-1)%2][j-m-1] ) % M ; }
			}
		}
		pl(dp[k%2][n] % M);		nl;
	}
}
